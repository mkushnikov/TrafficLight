#include "TrafficLight.h"

#include <iostream>

using std::cout;
using std::endl;

TrafficLight::TrafficLight()
{
    isStarted = true;
    isFinished = false;

    trafficLightState = TrafficLightStates::EMPTY;
    currentDirection = ColorChangeDirection::FORWARD;

    isYellowBlinking = false;
    currentYellowSwitchesCount = 0;
}

TrafficLight::~TrafficLight()
{
}

void TrafficLight::showLight(vector<string> circle)
{
    for (auto line : circle)
    {
        cout << line << endl;
    }
}

void TrafficLight::drawEmpty()
{
    showLight(emptyCircle);
    showLight(emptyCircle);
    showLight(emptyCircle);
}

void TrafficLight::drawRed()
{
    showLight(redCircle);
    showLight(emptyCircle);
    showLight(emptyCircle);
}

void TrafficLight::drawYellow()
{
    showLight(emptyCircle);
    showLight(yellowCircle);
    showLight(emptyCircle);
}

void TrafficLight::drawGreen()
{
    showLight(emptyCircle);
    showLight(emptyCircle);
    showLight(greenCircle);
}

void TrafficLight::clearConsole()
{
    system("cls");
}

void TrafficLight::showControllInfo()
{
    cout << "The Traffic Light @kust" << endl;
    cout << "Press P to pause" << endl;
    cout << "Press S to start" << endl;
    cout << "Press E to exit" << endl;
    cout << "Enjoy!" << endl;
    cout << endl;
}

void TrafficLight::drawTL()
{
    switch (trafficLightState)
    {
    case TrafficLightStates::EMPTY:
        drawEmpty();
        break;
    case TrafficLightStates::RED:
        drawRed();
        break;
    case TrafficLightStates::YELLOW:
        drawYellow();
        break;
    case TrafficLightStates::GREEN:
        drawGreen();
        break;
    default:
        break;
    }
}

void TrafficLight::updateTLState()
{
    switch (trafficLightState)
    {
    case TrafficLightStates::EMPTY:
        if (isYellowBlinking)
        {
            trafficLightState = TrafficLightStates::YELLOW;
            currentYellowSwitchesCount++;
        }
        else
        {
            trafficLightState = TrafficLightStates::RED;
        }
        break;
    case TrafficLightStates::RED:
        trafficLightState = TrafficLightStates::YELLOW;
        currentDirection = ColorChangeDirection::FORWARD;
        isYellowBlinking = true;
        break;
    case TrafficLightStates::YELLOW:
        if (isYellowBlinking && currentYellowSwitchesCount < yellowSwitchesMaxCount)
        {
            trafficLightState = TrafficLightStates::EMPTY;
            currentYellowSwitchesCount++;
        }
        else if (currentDirection == ColorChangeDirection::FORWARD)
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount = 0;
            trafficLightState = TrafficLightStates::GREEN;
        }
        else
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount = 0;
            trafficLightState = TrafficLightStates::RED;
        }
        break;
    case TrafficLightStates::GREEN:
        isYellowBlinking = true;
        trafficLightState = TrafficLightStates::YELLOW;
        currentDirection = ColorChangeDirection::REVERSE;
        break;
    default:
        break;
    }
}