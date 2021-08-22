#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <functional>

class Timer
{
private:
    //Интервал для обновления таймера
    std::chrono::milliseconds updateStep_;

    //Прерывание таймера по вводу
    bool isInterrupted_;

    //Переменная для хранения кол-ва оставшегося времени при прерывании
    std::chrono::milliseconds timeRemains_;

public:
    //Флаг для проверки, запущен ли таймер
    bool isRunning;

    // Запускаем таймер и вызываем функцию по окончании
    void runTimer(std::chrono::milliseconds delay,
                  std::function<void()> callback);

    //Функция для прерывания таймера
    std::chrono::milliseconds stopTimer();

    Timer()
        : updateStep_(std::chrono::milliseconds(100)),
          isInterrupted_(false),
          isRunning(false)
    {
    }
};
#endif