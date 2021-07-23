#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_


class TrafficLight
{
private:
    //Макс. кол-во миганий для жёлтого
    static const int yellowSwitchesMaxCount;
    // Счётчик миганий
    int currentYellowSwitchesCount;

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
    bool isStarted;
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

    // Обновляем стейт светофора для следующего круга отрисовки
    void updateTLState();

    TrafficLight()
        : isStarted(true),
          isFinished(false),
          isYellowBlinking(false),
          currentSwitchTime(0),
          trafficLightState(States::EMPTY),
          currentDirection(SwitchDirection::FORWARD),
          currentYellowSwitchesCount(0)
    {
    }
};
#endif