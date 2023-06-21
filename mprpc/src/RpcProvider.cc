#include <mprpc/rpcprovider.h>
#include <mprpc/MprpcApplication.h>
#include <mprpc/rpcheader.pb.h>
#include <google/protobuf/descriptor.h>
#include <mymuduo/TcpConnection.h>
#include <mylogger/Logger.h>

/**
 * @brief
 * service_name => service描述
 * => method_name => method方法
 * @param service
 */
// 框架对外提供使用的，可以发布rpc方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiceInfo service_info;

    // Describes an RPC service. Use DescriptorPool to construct your own descriptors.
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    // 获取服务的名字
    std::string service_name = pserviceDesc->name();
    LOG_INFO << "service_name " << service_name;
    // 获取服务对象service的数量
    int methodCnt = pserviceDesc->method_count();
    
    for (int i = 0; i < methodCnt; i++)
    {
        // 获取了服务对象指定下标的服务方法的描述（抽象描述）
        const google::protobuf::MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        LOG_INFO << "method_name " << method_name;
        service_info.m_methodDescMap.insert({method_name, pmethodDesc});
    }
    service_info.m_service = service;
    m_serciceInfoMap.insert({service_name, service_info});
}

// 启动rpc服务节点，开始提供rpc远程调用服务
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    std::string s_port = MprpcApplication::GetInstance().GetConfig().Load("rpcserverport");
    uint16_t port = atoi(s_port.c_str());
    mymuduo::InetAddress address(port, ip);

    // 创建TcpServer对象
    mymuduo::TcpServer server(&m_eventLoop, address, "RpcProvider");
    std::cout << "服务器创建成功！" << std::endl;
    // 绑定连接回调和消息读写回调方法
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置mymuduo库的线程数量
    server.setThreadNum(4);

    // 启动网络服务
    server.start();
    m_eventLoop.loop();
}

// 新的socket连接回调
void RpcProvider::OnConnection(const mymuduo::TcpConnectionPtr &conn)
{
    // RPC请求是短连接请求，和http一样请求一次服务器返回结果后就主动关闭连接
    if (!conn->connected())
    {
        // 和rpc client的连接断开了
        conn->shutdown();
    }
}
// 在框架内部，RpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型
// service name / method name / args 在框架中定义proto 的message类型，进行数据头的序列化和反序列化
// protobuf协议制定：其中下面的args_size是为了防止发生TCP粘包定义了要读取args的长度
// header_sz(4个字节) + header_str + args_size
// 关于读取多少字节为header_size，要用到std::string 的 insert 和 copy方法

// 已建立连接用户的读写事件回调 如果远程有一个rpc服务的调用请求，那么onMessage方法就会响应
void RpcProvider::OnMessage(const mymuduo::TcpConnectionPtr &conn,
                            mymuduo::Buffer *buffer,
                            mymuduo::Timestamp timestamp)
{
    // 网络上接收的远程rpc调用请求的字符流 Login args
    std::string recv_buf = buffer->retrieveAllAsString();
    // 从字符流中读取前四个字节的内容
    uint32_t header_size = 0;
    recv_buf.copy((char *)&header_size, 4, 0);

    // 根据header_size读取数据头的原始字符流，反序列化数据，得到rpc请求的详细信息
    std::string rpc_header_str = recv_buf.substr(4, header_size);
    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if (rpcHeader.ParseFromString(rpc_header_str))
    {
        // 数据头反序列化成功
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else
    {
        // 数据头反序列化失败
        std::cout << "rpc_header_str: " << rpc_header_str << " parse error!" << std::endl;
        return;
    }

    // 获取rpc方法参数的字符流数据
    std::string args_str = recv_buf.substr(4 + header_size, args_size);
    // 打印调试信息
    std::cout << "==========================================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "method_nameargs_str: " << args_str << std::endl;
    std::cout << "==========================================" << std::endl;

    // 获取service对象
    if (!m_serciceInfoMap.count(service_name))
    {
        std::cout << service_name << " does not exist!" << std::endl;
        return;
    }
    ServiceInfo sinfo = m_serciceInfoMap[service_name];
    google::protobuf::Service *service = sinfo.m_service;
    // 获取service的method对象
    if (!sinfo.m_methodDescMap.count(method_name))
    {
        std::cout << method_name << " does not exist!" << std::endl;
        return;
    }
    const google::protobuf::MethodDescriptor *method = sinfo.m_methodDescMap[method_name];

    // 生成rpc方法调用的请求request和响应response参数
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args_str))
    {
        std::cout << "request parse error, content: " << args_str << std::endl;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();

    // 给下面method调用，绑定一个Closure的回调函数
    google::protobuf::Closure *done = google::protobuf::NewCallback<RpcProvider, const mymuduo::TcpConnectionPtr &, google::protobuf::Message *>(this, &RpcProvider::SendRpcResponse, conn, response);
    // 在框架上根据远端rpc的请求，调用当前rpc节点上发布的方法
    // 框架上service调用CallMethod，也就是服务调用远程发过来的请求调用的方法
    service->CallMethod(method, nullptr, request, response, done);
}

void RpcProvider::SendRpcResponse(const mymuduo::TcpConnectionPtr &conn, google::protobuf::Message *response)
{
    std::string response_str;
    if (response->SerializePartialToString(&response_str))
    {
        // response进行序列化
        // 序列化成功后，通过网络把rpc方法执行结果发送给rpc服务调用方
        conn->send(response_str);
    }
    else
    {
        std::cout << "serialize response_str error!" << std::endl;
    }
    conn->shutdown(); // 模拟http的短链接服务，由rpcprovider主动断开连接
}