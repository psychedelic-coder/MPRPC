#pragma once
#include <mprpc/MprpcConfig.h>
#include <mprpc/MprpcChannel.h>
#include <mprpc/MprpcController.h>

// mprpc框架的基础类、用单例模式
class MprpcApplication
{
public:
    static void Init(int, char **);
    static MprpcApplication &GetInstance();
    static MprpcConfig &GetConfig();
private:
    static MprpcConfig m_config;

    MprpcApplication(){};
    MprpcApplication(const MprpcApplication &) = delete;
    MprpcApplication(MprpcApplication &) = delete;
};