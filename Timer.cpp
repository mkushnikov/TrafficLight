#include "Timer.h"

#include <thread>

void Timer::runTimer(std::chrono::seconds delay, std::function<void()> callback, bool isAsync)
{
    if (isAsync)
    {
        std::thread([=]
                    {
                        std::this_thread::sleep_for(std::chrono::seconds(delay));
                        callback();
                    })
            .detach();
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::seconds(delay));
        callback();
    }
}