#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

#include "TrafficLight.h"

class Timer
{
private:
    // Момент времени, в который было последнее переключение светофора
    time_t lastSwitchTime;
    // Счётчик для определения момента следующего переключения
    time_t nextSwitchCounter;

public:
    // Функция для таймера, весьма корявая
    //
    // TODO: Полагаю, что таймер должен зависеть от нажатий
    // Тогда наверное нужен отдельный поток, чтобы реагировать на них и не крутить время, если мы поставили паузу/вышли
    // Но я решил не лезть в эти дебри, т.к. это более тонкий контроль потоков
    void runTimer(const TrafficLight &tl);

    Timer();
    ~Timer();
};
#endif