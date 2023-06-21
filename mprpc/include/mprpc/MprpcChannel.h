#pragma once
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

class MprpcChannel : public google::protobuf::RpcChannel
{
public:
    // RpcChannel是protobuf中的一个接口，它表示与Service通信的通道，可以用于调用Service的方法
    // Service可能在另一台机器上运行。通常情况下，你不应该直接调用RpcChannel，而是应该构造一个包装它
    // 的stub Service
    // 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
    void CallMethod(const google::protobuf::MethodDescriptor *method,
                    google::protobuf::RpcController*, const google::protobuf::Message *request,
                    google::protobuf::Message *response, google::protobuf::Closure *done) override;
};