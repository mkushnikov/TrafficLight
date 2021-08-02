#include "Input.h"

#include <conio.h>

void Input::handleInput()
{
    while (true)
    {
        pressedKey = getch();

        switch (pressedKey)
        {
        case 'S':
        case 's':
            tlCb.startCallback();
            timerCb.startCallback();
            break;
        case 'P':
        case 'p':
            tlCb.pauseCallback();
            timerCb.pauseCallback();
            break;
        case 'E':
        case 'e':
            tlCb.exitCallback();
            timerCb.exitCallback();
            break;
        default:
            break;
        }
    }
}