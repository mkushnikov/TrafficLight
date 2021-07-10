#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

// Список состояний светофора для отрисовки
enum class TrafficLightStates
{
    EMPTY,
    RED,
    YELLOW,
    GREEN
};
// Список направлений переключения цветов
enum class ColorChangeDirection
{
    FORWARD,
    REVERSE
};

class TrafficLight
{
private:
    //Макс. кол-во миганий для жёлтого
    const int yellowSwitchesMaxCount = 4;

    // Символьная графика для цветов светофора
    const vector<string> emptyCircle = {
        "    ---   ",
        "  /     \\  ",
        " /       \\ ",
        "|         |",
        " \\       / ",
        "  \\     /  ",
        "    ---    "};

    const vector<string> redCircle = {
        "    ---   ",
        "  / RRR \\  ",
        " / RRRRR \\ ",
        "| RRRRRRR |",
        " \\ RRRRR / ",
        "  \\ RRR /  ",
        "    ---    "};

    const vector<string> yellowCircle = {
        "    ---   ",
        "  / YYY \\  ",
        " / YYYYY \\ ",
        "| YYYYYYY |",
        " \\ YYYYY / ",
        "  \\ YYY /  ",
        "    ---    "};

    const vector<string> greenCircle = {
        "    ---   ",
        "  / GGG \\  ",
        " / GGGGG \\ ",
        "| GGGGGGG |",
        " \\ GGGGG / ",
        "  \\ GGG /  ",
        "    ---    "};

    // Счётчик миганий
    int currentYellowSwitchesCount;

    // Функция для отрисовки цветов светофора
    void showLight(vector<string> circle);

    // Функции для отрисовки светофора в конкретном стейте
    void drawEmpty();
    void drawRed();
    void drawYellow();
    void drawGreen();

public:
    // Тайминг для красного цвета
    const int redTimeSwitch = 2;
    // Тайминг для зелёного цвета
    const int greenTimeSwitch = 3;
    // Частота мигания жёлтого
    const int yellowTimeBlinkFrequency = 1;

    // Определяет, запущено переключение или нет
    bool isStarted;
    // Используется для завершения работы светофора
    bool isFinished;

    // Состояние светофора
    TrafficLightStates trafficLightState;
    // Направление переключений
    ColorChangeDirection currentDirection;
    // Используется для смены состояний светофора по время мигания жёлтого
    bool isYellowBlinking;

    // Информация об управлении
    void showControllInfo();

    // Обновляем стейт светофора для следующего круга отрисовки
    void updateTLState();

    // Отрисовываем нужный цвет в зависимости от стейта
    void drawTL();

    TrafficLight();
    ~TrafficLight();
};
#endif