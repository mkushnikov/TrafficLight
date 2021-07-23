#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <functional>

class Timer
{
public:
    // Запускаем таймер и вызываем функцию после окончания
    void runTimer(std::chrono::seconds delay,
                  std::function<void()> callback,
                  bool isAsync);
};
#endif