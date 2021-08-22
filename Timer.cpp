#include "Timer.h"

#include <thread>

void Timer::runTimer(std::chrono::milliseconds delay, std::function<void()> callback)
{
    isRunning = true;

    std::thread([&, delay]
                {
                    std::chrono::milliseconds counter = std::chrono::milliseconds(0);
                    while (counter < delay && !isInterrupted_)
                    {
                        std::this_thread::sleep_for(updateStep_);
                        counter += updateStep_;
                    }

                    if (!isInterrupted_)
                    {
                        callback();
                    }
                    else
                    {
                        timeRemains_ = delay - counter;
                    }

                    isRunning = false;
                })
        .detach();
}

std::chrono::milliseconds Timer::stopTimer()
{
    isInterrupted_ = true;

    while (isRunning)
    {
        std::this_thread::sleep_for(updateStep_);
    }

    isInterrupted_ = false;

    return timeRemains_;
}