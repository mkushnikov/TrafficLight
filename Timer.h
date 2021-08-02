#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <functional>

class Timer
{
private:
    bool isPaused;
    bool isInterrupted;
    std::chrono::milliseconds updateStep;

public:
    bool isRunning;

    void onPauseButtonPressed();
    void onStartButtonPressed();
    void onExitButtonPressed();
    // Запускаем таймер и вызываем функцию после окончания
    void runTimer(std::chrono::milliseconds delay,
                  std::function<void()> callback);

    Timer()
        : updateStep(std::chrono::milliseconds(100)),
          isRunning(false),
          isPaused(false),
          isInterrupted(false)
    {
    }
};
#endif