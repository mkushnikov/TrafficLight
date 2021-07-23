#include <iostream>

#include "Output.h"

using std::cout;
using std::endl;
using std::vector;

void Output::showControllInfo()
{
    cout << "The Traffic Light @kust" << endl;
    cout << "Press P to pause" << endl;
    cout << "Press S to start" << endl;
    cout << "Press E to exit" << endl;
    cout << "Enjoy!" << endl;
    cout << endl;
}

void Output::clearConsole()
{
    system("cls");
}

const std::vector<std::string> Output::emptyCircle = {
    "    ---   ",
    "  /     \\  ",
    " /       \\ ",
    "|         |",
    " \\       / ",
    "  \\     /  ",
    "    ---    "};

const std::vector<std::string> Output::redCircle = {
    "    ---   ",
    "  / RRR \\  ",
    " / RRRRR \\ ",
    "| RRRRRRR |",
    " \\ RRRRR / ",
    "  \\ RRR /  ",
    "    ---    "};

const std::vector<std::string> Output::yellowCircle = {
    "    ---   ",
    "  / YYY \\  ",
    " / YYYYY \\ ",
    "| YYYYYYY |",
    " \\ YYYYY / ",
    "  \\ YYY /  ",
    "    ---    "};

const std::vector<std::string> Output::greenCircle = {
    "    ---   ",
    "  / GGG \\  ",
    " / GGGGG \\ ",
    "| GGGGGGG |",
    " \\ GGGGG / ",
    "  \\ GGG /  ",
    "    ---    "};

void Output::showLight(std::vector<std::string> circle)
{
    for (auto line : circle)
    {
        cout << line << endl;
    }
}

void Output::drawEmpty()
{
    showLight(emptyCircle);
    showLight(emptyCircle);
    showLight(emptyCircle);
}

void Output::drawRed()
{
    showLight(redCircle);
    showLight(emptyCircle);
    showLight(emptyCircle);
}

void Output::drawYellow()
{
    showLight(emptyCircle);
    showLight(yellowCircle);
    showLight(emptyCircle);
}

void Output::drawGreen()
{
    showLight(emptyCircle);
    showLight(emptyCircle);
    showLight(greenCircle);
}

void Output::drawTL(TrafficLight::States currentState)
{
    switch (currentState)
    {
    case TrafficLight::States::EMPTY:
        drawEmpty();
        break;
    case TrafficLight::States::RED:
        drawRed();
        break;
    case TrafficLight::States::YELLOW:
        drawYellow();
        break;
    case TrafficLight::States::GREEN:
        drawGreen();
        break;
    default:
        break;
    }
}