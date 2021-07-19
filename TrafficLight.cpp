#include "TrafficLight.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const int TrafficLight::yellowTimeBlinkFrequency = 1;
const int TrafficLight::yellowSwitchesMaxCount = 4;
const int TrafficLight::redTimeSwitch = 2;
const int TrafficLight::greenTimeSwitch = 3;

const std::vector<std::string> TrafficLight::emptyCircle = {
    "    ---   ",
    "  /     \\  ",
    " /       \\ ",
    "|         |",
    " \\       / ",
    "  \\     /  ",
    "    ---    "};

const std::vector<std::string> TrafficLight::redCircle = {
    "    ---   ",
    "  / RRR \\  ",
    " / RRRRR \\ ",
    "| RRRRRRR |",
    " \\ RRRRR / ",
    "  \\ RRR /  ",
    "    ---    "};

const std::vector<std::string> TrafficLight::yellowCircle = {
    "    ---   ",
    "  / YYY \\  ",
    " / YYYYY \\ ",
    "| YYYYYYY |",
    " \\ YYYYY / ",
    "  \\ YYY /  ",
    "    ---    "};

const std::vector<std::string> TrafficLight::greenCircle = {
    "    ---   ",
    "  / GGG \\  ",
    " / GGGGG \\ ",
    "| GGGGGGG |",
    " \\ GGGGG / ",
    "  \\ GGG /  ",
    "    ---    "};

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
    case States::EMPTY:
        drawEmpty();
        break;
    case States::RED:
        drawRed();
        break;
    case States::YELLOW:
        drawYellow();
        break;
    case States::GREEN:
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
    case States::EMPTY:
        if (isYellowBlinking)
        {
            trafficLightState = States::YELLOW;
            currentYellowSwitchesCount++;
        }
        else
        {
            trafficLightState = States::RED;
        }
        break;
    case States::RED:
        trafficLightState = States::YELLOW;
        currentDirection = SwitchDirection::FORWARD;
        isYellowBlinking = true;
        break;
    case States::YELLOW:
        if (isYellowBlinking && currentYellowSwitchesCount < yellowSwitchesMaxCount)
        {
            trafficLightState = States::EMPTY;
            currentYellowSwitchesCount++;
        }
        else if (currentDirection == SwitchDirection::FORWARD)
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount = 0;
            trafficLightState = States::GREEN;
        }
        else
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount = 0;
            trafficLightState = States::RED;
        }
        break;
    case States::GREEN:
        isYellowBlinking = true;
        trafficLightState = States::YELLOW;
        currentDirection = SwitchDirection::REVERSE;
        break;
    default:
        break;
    }
}