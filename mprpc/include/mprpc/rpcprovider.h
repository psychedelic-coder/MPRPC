#pragma once
#include <google/protobuf/service.h>
#include <string>
#include <functional>
#include <unordered_map>
#include <mymuduo/TcpServer.h>
#include <mymuduo/EventLoop.h>
#include <mymuduo/InetAddress.h>


// 框架提供的专门服务发布rpc服务的网络对象类
class RpcProvider 
{
public:
    // 框架类代码可以接收任何注册的rpc服务
    // 也就是说框架类代码不能依赖于某个业务
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    // 启动rpc服务节点，开始提供rpc远程调用服务
    void Run();
private:
    // 组合EventLoop
    mymuduo::EventLoop m_eventLoop;

    // 服务类型信息
    struct ServiceInfo
    {
        google::protobuf::Service *m_service;   // 保存服务对象
        std::unordered_map<std::string, 
                            const google::protobuf::MethodDescriptor *> m_methodDescMap;  // 保存服务方法描述子
    };
    // 存储注册成功的服务对象和其服务方法的所有信息
    std::unordered_map<std::string, ServiceInfo> m_serciceInfoMap;
    // 新的socket连接回调
    void OnConnection(const mymuduo::TcpConnectionPtr &);
    // 已建立连接用户的读写事件回调
    void OnMessage(const mymuduo::TcpConnectionPtr &, mymuduo::Buffer *, mymuduo::Timestamp);

    // closure的回调操作，用于序列化rpc的响应和网络发送
    // 也就是rpc调用方法的响应通过网络库发送回调用者caller
    void SendRpcResponse(const mymuduo::TcpConnectionPtr&, google::protobuf::Message*);
};