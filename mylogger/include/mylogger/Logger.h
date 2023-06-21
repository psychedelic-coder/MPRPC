#pragma once

#include <mylogger/Timestamp.h>
#include <mylogger/LogStream.h>
#include <mylogger/LogFile.h>

#include <string>
#include <string.h>
#include <functional>

// LOG_INFO("%s %d", arg1, arg2)
#define LOG_FMT_INFO(logmsgFormat, ...)                                                           \
    do                                                                                            \
    {                                                                                             \
        char buf[1024] = {0};                                                                     \
        int cnt = snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                               \
        if (cnt >= 0 && cnt <= 1024)                                                              \
            mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::INFO).stream().append(buf, cnt); \
    } while (0)

#define LOG_FMT_ERROR(logmsgFormat, ...)                                                           \
    do                                                                                             \
    {                                                                                              \
        char buf[1024] = {0};                                                                      \
        int cnt = snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                                \
        if (cnt >= 0 && cnt <= 1024)                                                               \
            mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::ERROR).stream().append(buf, cnt); \
    } while (0)

#define LOG_FMT_FATAL(logmsgFormat, ...)                                                           \
    do                                                                                             \
    {                                                                                              \
        char buf[1024] = {0};                                                                      \
        int cnt = snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                                \
        if (cnt >= 0 && cnt <= 1024)                                                               \
            mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::FATAL).stream().append(buf, cnt); \
    } while (0)

#ifdef FMT_DEBUG
#define LOG_FMT_DEBUG(logmsgFormat, ...)                                                           \
    do                                                                                             \
    {                                                                                              \
        char buf[1024] = {0};                                                                      \
        int cnt = snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__);                                \
        if (ccnt >= 0 && cnt <= 1024)                                                              \
            mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::DEBUG).stream().append(buf, cnt); \
    } while (0)
#else
#define LOG_FMT_DEBUG(logmsgFormat, ...)
#endif

// 定义日志的级别 INFO ERROR FATAL DEBUG
namespace mylogger
{
    class Logger
    {
    public:
        // SourceFile的作用是提取文件名
        class SourceFile
        {
        public:
            template <int N>
            SourceFile(const char (&arr)[N])
                : data_(arr),
                  size_(N - 1)
            {
                // char* strrchr(const char*s, int c)
                // The  strchr() function returns a pointer to the first occurrence of the
                // character c in the string s.
                // *slash指向第一个出现的'\'字符
                const char *slash = ::strrchr(data_, '/'); // builtin function
                if (slash)
                {
                    data_ = slash + 1;
                    size_ -= static_cast<int>(data_ - arr);
                }
            }

            explicit SourceFile(const char *filename)
                : data_(filename)
            {
                /**
                 * char *strrchr(const char *s, int c);
                 * The strrchr() function returns a pointer to the last occurrence of the character c in the string s.
                 */
                const char *slash = ::strrchr(filename, '/');
                if (slash)
                {
                    data_ = slash + 1;
                }
                size_ = static_cast<int>(strlen(data_));
            }

            const char *data_;
            int size_;
        };

        enum LogLevel
        {
            INFO,  // 普通信息
            ERROR, // 错误信息
            FATAL, // core信息
            DEBUG  // 调试信息
        };

        Logger(SourceFile file, int line);
        Logger(SourceFile file, int line, LogLevel level);
        Logger(SourceFile file, int line, LogLevel level, const char *func);
        ~Logger();

        // 流是会改变的
        LogStream &stream() { return impl_.stream_; }

        static LogLevel logLevel();
        static void setLogLevel(LogLevel level);
        // 获取日志唯一的实例对象
        // static Logger &instance();
        // 设置日志级别
        // void setLoglevel(int level);
        // 写日志
        // void log(std::string msg);

        using OutputFunc = std::function<void(const char *msg, int len)>;
        using FlushFunc = std::function<void()>;
        static void setOutput(OutputFunc);
        static void setFlush(FlushFunc);

    private:
        class Impl
        {
        public:
            using LogLevel = Logger::LogLevel;
            Impl(LogLevel level, int old_errno, const SourceFile &file, int line);
            void formatTime();
            void finish();

            Timestamp time_;
            LogStream stream_;
            LogLevel level_;
            int line_;
            SourceFile basename_;
        };

        Impl impl_;
    };

    extern Logger::LogLevel g_logLevel;

    inline Logger::LogLevel Logger::logLevel()
    {
        return g_logLevel;
    }

    const char *getErrnoMsg(int savedErrno);

/**
 * 当日志等级小于对应等级才会输出
 * 比如设置等级为FATAL，则logLevel等级大于DEBUG和INFO，DEBUG和INFO等级的日志就不会输出
 */
#define LOG_DEBUG                                              \
    if (mylogger::Logger::logLevel() <= mylogger::Logger::DEBUG) \
    mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::DEBUG, __func__).stream()
#define LOG_INFO                                              \
    if (mylogger::Logger::logLevel() <= mylogger::Logger::INFO) \
    mylogger::Logger(__FILE__, __LINE__).stream()
#define LOG_WARN mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::WARN).stream()
#define LOG_ERROR mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::ERROR).stream()
#define LOG_FATAL mylogger::Logger(__FILE__, __LINE__, mylogger::Logger::FATAL).stream()

} // namespace mylogger