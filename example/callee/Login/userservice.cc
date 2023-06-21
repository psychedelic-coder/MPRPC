#include <iostream>
#include <string>

#include <mprpc/user.pb.h>
#include <mprpc/MprpcApplication.h>
#include <mprpc/rpcprovider.h>

using namespace fixbug;
/**
 * @brief UserSerice 原本是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendLists
 *
 */
class UserService : public UserServiceRpc
{
public:
    // 提供rpc服务的服务器的本地业务方法
    // 做本地业务
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "doing local service: Login" << std::endl;
        std::cout << "name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }

    // 重写基类UserServiceRpc的虚函数 下面这些方法都是框架直接调用的
    // 也就是作为生产者，我们提供给用户Login等服务
    // caller => Login(LoginRequest) => muduo => callee
    // callee => Login(LoginRequest) => 交给下面重写的这个Login方法上
    void Login(::google::protobuf::RpcController *controller,
                               const ::fixbug::LoginRequest *request,
                               ::fixbug::LoginResponse *response,
                               ::google::protobuf::Closure *done)
    {
        // 框架给业务上报了请求参数，业务获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool login_result = Login(name, pwd); // 做本地业务

        // 把响应写入框架 包括错误码、错误消息、返回值
        fixbug::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_sucess(login_result);

        // 执行回调操作 执行相应对象数据的序列化和网络发送（都是由框架来完成的00）
        done->Run();
    }
    
};

int main(int argc, char** argv)
{
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // 把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());

    // 启动一个rpc服务发布节点  Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}