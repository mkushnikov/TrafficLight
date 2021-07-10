#include "Input.h"

Input::Input()
{
}
Input::~Input()
{
}

void Input::handleInput(TrafficLight &tl)
{
    while (!tl.isFinished)
    {
        // Видел инфу, что этот метод, как и саму библиотеку conio - не рекомендуют использовать
        // Но другие варианты не смог закодить(пробовал future + async - не завёлся)
        pressedKey = getch();

        switch (pressedKey)
        {
        case 'S':
        case 's':
            tl.isStarted = true;
            break;
        case 'P':
        case 'p':
            tl.isStarted = false;
            break;
        case 'E':
        case 'e':
            tl.isFinished = true;
            break;
        default:
            break;
        }
    }
}