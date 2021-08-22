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

const std::vector<std::string> Output::emptyCircle_ = {
    "    ---   ",
    "  /     \\  ",
    " /       \\ ",
    "|         |",
    " \\       / ",
    "  \\     /  ",
    "    ---    "};

const std::vector<std::string> Output::redCircle_ = {
    "    ---   ",
    "  / RRR \\  ",
    " / RRRRR \\ ",
    "| RRRRRRR |",
    " \\ RRRRR / ",
    "  \\ RRR /  ",
    "    ---    "};

const std::vector<std::string> Output::yellowCircle_ = {
    "    ---   ",
    "  / YYY \\  ",
    " / YYYYY \\ ",
    "| YYYYYYY |",
    " \\ YYYYY / ",
    "  \\ YYY /  ",
    "    ---    "};

const std::vector<std::string> Output::greenCircle_ = {
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
    showLight(emptyCircle_);
    showLight(emptyCircle_);
    showLight(emptyCircle_);
}

void Output::drawRed()
{
    showLight(redCircle_);
    showLight(emptyCircle_);
    showLight(emptyCircle_);
}

void Output::drawYellow()
{
    showLight(emptyCircle_);
    showLight(yellowCircle_);
    showLight(emptyCircle_);
}

void Output::drawGreen()
{
    showLight(emptyCircle_);
    showLight(emptyCircle_);
    showLight(greenCircle_);
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