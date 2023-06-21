#include <mylogger/Timestamp.h>

#include <time.h>

namespace mylogger
{
    // Timestamp::Timestamp() : microSecondsSinceEpoch_(0) {}

    Timestamp::Timestamp(int64_t microSecondsSinceEpoch_)
        : microSecondsSinceEpoch_(microSecondsSinceEpoch_)
    {
    }

    Timestamp Timestamp::now()
    {
        struct timeval tv;
        ::gettimeofday(&tv, NULL);
        int64_t seconds = tv.tv_sec;
        return Timestamp(seconds * kMicroSecondsPerSecond + tv.tv_usec);
    }

    std::string Timestamp::tostring() const
    {
        char buf[128] = {0};
        tm *tm_time = localtime(&microSecondsSinceEpoch_);
        snprintf(buf, 128, "%4d/%02d/%02d   %02d:%02d:%02d",
                 tm_time->tm_year + 1900,
                 tm_time->tm_mon + 1,
                 tm_time->tm_mday,
                 tm_time->tm_hour,
                 tm_time->tm_min,
                 tm_time->tm_sec);

        return buf;
    }
}

// #include <iostream>

// int main()
//{
//     std::cout << mylogger::Timestamp::now().tostring() << std::endl;
//     return 0;
// }