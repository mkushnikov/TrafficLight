#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include <string>
#include <vector>

class TrafficLight
{
private:
    //Макс. кол-во миганий для жёлтого
    static const int yellowSwitchesMaxCount;

    // Символьная графика для цветов светофора
    static const std::vector<std::string> emptyCircle;

    static const std::vector<std::string> redCircle;

    static const std::vector<std::string> yellowCircle;

    static const std::vector<std::string> greenCircle;

    // Счётчик миганий
    int currentYellowSwitchesCount;

    // Функция для отрисовки цветов светофора
    void showLight(std::vector<std::string> circle);

    // Функции для отрисовки светофора в конкретном стейте
    void drawEmpty();
    void drawRed();
    void drawYellow();
    void drawGreen();

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

    // Состояние светофора
    States trafficLightState;
    // Направление переключений
    SwitchDirection currentDirection;
    // Используется для смены состояний светофора по время мигания жёлтого
    bool isYellowBlinking;

    // Информация об управлении
    void showControllInfo();

    // Обновляем стейт светофора для следующего круга отрисовки
    void updateTLState();

    // Отрисовываем нужный цвет в зависимости от стейта
    void drawTL();

    // Чистка консоли
    void clearConsole();

    TrafficLight()
        : isStarted(true),
          isFinished(false),
          isYellowBlinking(false),
          trafficLightState(States::EMPTY),
          currentDirection(SwitchDirection::FORWARD),
          currentYellowSwitchesCount(0)
    {
    }
};
#endif