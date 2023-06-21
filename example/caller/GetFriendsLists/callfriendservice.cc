#include <iostream>
#include <mprpc/MprpcApplication.h>
#include <mprpc/friend.pb.h>

int main(int argc, char **argv)
{
    // 整个程序启动以后，想使用mprpc框架来享受rpc服务调用，一定需要调用框架的初始化函数
    MprpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    // stub:存根
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel(), google::protobuf::Service::ChannelOwnership::STUB_OWNS_CHANNEL);

    // rpc方法的请求参数
    fixbug::GetFriendListRequest request;
    request.set_userid(1000);

    // rpc方法的响应
    fixbug::GetFriendListResponse response;
    // 发起rpc方法的调用 同步的rpc调用过程 也就是stub.Login的底层调用是stub的rpcChannel的CallMethod方法
    MprpcController controller;
    stub.GetFriendList(&controller, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    if (controller.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        // 一次rpc调用完成，读调用的结果
        if (0 == response.result().errcode())
        {
            std::cout << "rpc get_friends_list response success!" << std::endl;
            for (auto &name : response.friends())
            {
                std::cout << name << std::endl;
            }
        }
        else
        {
            std::cout << "rpc get_friends_list response error : " << response.result().errmsg() << std::endl;
        }
    }

    return 0;
}