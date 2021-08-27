#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string_view>

#include "TrafficLight.h"

class Output
{
private:
    // Символьная графика для цветов светофора
    static const std::vector<std::string_view> emptyCircle_;

    static const std::vector<std::string_view> redCircle_;

    static const std::vector<std::string_view> yellowCircle_;

    static const std::vector<std::string_view> greenCircle_;

    // Функция для отрисовки цветов светофора
    void showLight(const std::vector<std::string_view> &circle);

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
