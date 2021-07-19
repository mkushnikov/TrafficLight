#ifndef INPUT_H_
#define INPUT_H_

#include "TrafficLight.h"

class Input
{
private:
    char pressedKey;

public:
    // Основная функция для ввода
    // Контролирует переменные, по которым отрабатывает вывод
    // Реагирует только на латинские буквы
    void handleInput(TrafficLight &tl);
};
#endif