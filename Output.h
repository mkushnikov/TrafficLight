#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string>

#include "TrafficLight.h"

class Output
{
private:
    // Символьная графика для цветов светофора
    static const std::vector<std::string> emptyCircle;

    static const std::vector<std::string> redCircle;

    static const std::vector<std::string> yellowCircle;

    static const std::vector<std::string> greenCircle;

    // Функция для отрисовки цветов светофора
    void showLight(std::vector<std::string> circle);

    // Функции для отрисовки светофора в конкретном стейте
    void drawEmpty();
    void drawRed();
    void drawYellow();
    void drawGreen();

public:
    // Чистка консоли
    void clearConsole();
    // Информация об управлении
    void showControllInfo();
    // Отрисовываем нужный цвет в зависимости от стейта
    void drawTL(TrafficLight::States currentState);
};
#endif
