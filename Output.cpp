#include <iostream>

#include "Output.h"

using std::cout;

void Output::showControllInfo()
{
    cout << "The Traffic Light @kust\n";
    cout << "Press P to pause\n";
    cout << "Press S to start\n";
    cout << "Press E to exit\n";
    cout << "Enjoy!\n";
    cout << "\n";
}

void Output::clearConsole()
{
    system("cls");
}

const std::vector<std::string_view> Output::emptyCircle_ = {
    "    ---   ",
    "  /     \\  ",
    " /       \\ ",
    "|         |",
    " \\       / ",
    "  \\     /  ",
    "    ---    "};

const std::vector<std::string_view> Output::redCircle_ = {
    "    ---   ",
    "  / RRR \\  ",
    " / RRRRR \\ ",
    "| RRRRRRR |",
    " \\ RRRRR / ",
    "  \\ RRR /  ",
    "    ---    "};

const std::vector<std::string_view> Output::yellowCircle_ = {
    "    ---   ",
    "  / YYY \\  ",
    " / YYYYY \\ ",
    "| YYYYYYY |",
    " \\ YYYYY / ",
    "  \\ YYY /  ",
    "    ---    "};

const std::vector<std::string_view> Output::greenCircle_ = {
    "    ---   ",
    "  / GGG \\  ",
    " / GGGGG \\ ",
    "| GGGGGGG |",
    " \\ GGGGG / ",
    "  \\ GGG /  ",
    "    ---    "};

void Output::showLight(const std::vector<std::string_view> &circle)
{
    for (auto line : circle)
    {
        cout << line << "\n";
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