#include "Timer.h"

#include <thread>

void Timer::runTimer(std::chrono::milliseconds delay, std::function<void()> callback)
{
    isRunning = true;
    std::thread([=]
                {
                    std::chrono::milliseconds counter = std::chrono::milliseconds(0);
                    while (counter < delay && !isInterrupted)
                    {
                        if (!isPaused)
                        {
                            std::this_thread::sleep_for(updateStep);
                            counter += updateStep;
                        }
                    }

                    if (!isInterrupted)
                    {
                        callback();
                    }
                    isRunning = false;
                })
        .detach();
}

void Timer::onStartButtonPressed()
{
    isPaused = false;
}

void Timer::onPauseButtonPressed()
{
    isPaused = true;
}

void Timer::onExitButtonPressed()
{
    isInterrupted = true;
}