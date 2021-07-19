#include "Input.h"

#include <conio.h>

void Input::handleInput(TrafficLight &tl)
{
    while (!tl.isFinished)
    {
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