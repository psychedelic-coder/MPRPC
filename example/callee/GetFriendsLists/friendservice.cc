#include <iostream>
#include <string>
#include <vector>

#include <mprpc/friend.pb.h>
#include <mprpc/MprpcApplication.h>
#include <mprpc/rpcprovider.h>
#include <mylogger/Logger.h>

class FriendService : public fixbug::FriendServiceRpc
{
public:
    // 服务器本地业务
    std::vector<std::string> GetFriendList(uint32_t userid)
    {
        std::cout << "do GetFriendList Service! userid = " << userid << std::endl;
        std::vector<std::string> vec;
        // get friendslist from local data base or somewhere else

        return vec;
    }

    // 重写基类方法
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::fixbug::GetFriendListRequest *request,
                       ::fixbug::GetFriendListResponse *response,
                       ::google::protobuf::Closure *done)
    {
        uint32_t userid = request->userid();
        std::vector<std::string> friendsList = GetFriendList(userid);   // 做本地业务
        // 把本地业务结果数据往response里面写
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for(auto &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char** argv)
{

    LOG_INFO << "first log message";
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // 把FriendService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    // 启动一个rpc服务发布节点  Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}