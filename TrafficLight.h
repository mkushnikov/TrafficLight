#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include "Timer.h"

class TrafficLight
{
private:
    //Макс. кол-во миганий для жёлтого
    static const int yellowSwitchesMaxCount_;
    // Счётчик миганий
    int currentYellowSwitchesCount_;

    //Функции для реакции на ввод
    void onPauseButtonPressed();
    void onStartButtonPressed();
    void onExitButtonPressed();

public:
    // Список состояний светофора для отрисовки
    enum States
    {
        EMPTY,
        RED,
        YELLOW,
        GREEN
    };

    // Список направлений переключения цветов
    enum SwitchDirection
    {
        FORWARD,
        REVERSE
    };

    // Тайминг для красного цвета
    static const int redTimeSwitch;
    // Тайминг для зелёного цвета
    static const int greenTimeSwitch;
    // Частота мигания жёлтого
    static const int yellowTimeBlinkFrequency;

    // Определяет, запущено переключение или нет
    bool isStopped;
    // Используется для завершения работы светофора
    bool isFinished;
    // Используется для смены состояний светофора по время мигания жёлтого
    bool isYellowBlinking;

    // Содержит текущее время мигания
    int currentSwitchTime;

    // Состояние светофора
    States trafficLightState;
    // Направление переключений
    SwitchDirection currentDirection;

    //Таймер для переключений светофора
    Timer myTimer;

    //Переменная для хранения кол-ва времени в случае Паузы
    std::chrono::milliseconds timeRemainingUntilSwitch;

    // Обновляем стейт светофора для следующего круга отрисовки
    void updateTLState();

    //Обработчик ввода
    void handlePressedKey(char pressedKey);

    TrafficLight()
        : isStopped(false),
          isFinished(false),
          isYellowBlinking(false),
          currentSwitchTime(0),
          trafficLightState(States::EMPTY),
          currentDirection(SwitchDirection::FORWARD),
          timeRemainingUntilSwitch(std::chrono::milliseconds(0)),
          currentYellowSwitchesCount_(0)
    {
    }
};
#endif