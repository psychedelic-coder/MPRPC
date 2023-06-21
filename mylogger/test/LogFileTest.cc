#include <unistd.h>
#include <mylogger/Logger.h>
#include <memory>

std::unique_ptr<mylogger::LogFile> g_logFile;

void outputFunc(const char *msg, int len)
{
  g_logFile->append(msg, len);
}

void flushFunc()
{
  g_logFile->flush();
}

int main(int argc, char *argv[])
{
  char name[3] = {'1', '2', '3'};
  //strncpy(name, argv[0], sizeof name - 1);
  //std::string name = "test";
  g_logFile.reset(new mylogger::LogFile(::basename(name), 1000));
  mylogger::Logger::setOutput(outputFunc);
  mylogger::Logger::setFlush(flushFunc);

  std::string line = "1234567890 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

  for (int i = 0; i < 10000; ++i)
  {
    LOG_INFO << line << i;

    usleep(1000);
  }
}