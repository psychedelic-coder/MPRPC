# mprpc分布式网络通信框架项目

#### `本项目基于自实现的高性能网络库mymuduo+Protobuf开发，所以命名为mprpc`

## 技术栈

- 集群和分布式概念以及原理
- RPC远程过程调用原理以及实现
- Protobuf数据序列化和反序列化协议
- ZooKeeper分布式一致性协调服务应用以及编程
- 自实现高性能网络库编程
- conf配置文件读取
- 高性能异步日志
- CMake构建项目集成编译环境
- github管理项目

## 集群和分布式

**集群**：每一台服务器独立运行一个工程的所有模块。

**分布式**：一个工程拆分了很多模块，每一个模块独立部署运行在一个服务器主机上，所有服务器协同工
作共同提供服务，每一台服务器称作分布式的一个节点，根据节点的并发要求，对一个节点可以再做节
点模块集群部署。

## RPC通信原理

RPC（Remote Procedure Call Protocol）远程过程调用协议。

![](/home/liuchen/图片/RPC通信原理.png)

- 黄色部分：设计rpc方法参数的打包和解析，也就是数据的序列化和反序列化，使用Protobuf

- 绿色部分：网络部分，包括寻找rpc服务主机，发起rpc调用请求和响应rpc调用结果，使用mymuduo网络

  库和zookeeper服务配置中心（专门做服务发现）

- mprpc框架主要包含以上两个部分的内容

## 高性能日志模块

### 使用说明

```C++
#include <unistd.h>
#include <memory>
#include <mylogger/Logger.h>
#include <mylogger/LogFile.h>

std::unique_ptr<mylogger::LogFile> g_logFile;

void outputFunc(const char *msg, int len)
{
  g_logFile->append(msg, len);
}
// 一般不用改flushFunc函数
void flushFunc()
{
  g_logFile->flush();
}

int main(int argc, char *argv[])
{
  // 日志文件名字
  std::string name = "123";
  // 初始化一个LogFile日志文件
  // mylogger::LogFile::LogFile(const std::string &basename, int flushEveryN = 1024)
  g_logFile.reset(new mylogger::LogFile(name, 1000));
  // 设定Logger输出函数为outputFunc，在本例中日志输出到文件123里面
  mylogger::Logger::setOutput(outputFunc);
  // 设定Logger刷新日志函数为flushFunc
  mylogger::Logger::setFlush(flushFunc);

  // 要写的日志信息
  std::string line = "1234567890 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

  for (int i = 0; i < 10000; ++i)
  {
      
    LOG_INFO << line;

    usleep(1000);
  }
}
```

