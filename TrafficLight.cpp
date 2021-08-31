#include "TrafficLight.h"

#include <iostream>
#include <string>

const int TrafficLight::yellowTimeBlinkFrequency = 1;
const int TrafficLight::yellowSwitchesMaxCount_ = 4;
const int TrafficLight::redTimeSwitch = 2;
const int TrafficLight::greenTimeSwitch = 3;

void TrafficLight::runTrafficLight()
{
    while (!isFinished)
    {
        if (!isStopped && !myTimer.isTimerRunning())
        {
            trafficLightDrawer_.clearConsole();
            trafficLightDrawer_.showControllInfo();
            drawTL(trafficLightState);
            if (timeRemainingUntilSwitch == std::chrono::milliseconds(0))
            {
                myTimer.runTimer(std::chrono::milliseconds(currentSwitchTime * 1000), [&]
                                 { updateTLState(); });
            }
            else
            {
                myTimer.runTimer(std::chrono::milliseconds(timeRemainingUntilSwitch), [&]
                                 { updateTLState(); });
                timeRemainingUntilSwitch = std::chrono::milliseconds(0);
            }
        }
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
            currentYellowSwitchesCount_++;
        }
        else
        {
            trafficLightState = States::RED;
            currentSwitchTime = redTimeSwitch;
        }
        break;
    case States::RED:
        trafficLightState = States::YELLOW;
        currentDirection = SwitchDirection::FORWARD;
        isYellowBlinking = true;
        currentSwitchTime = yellowTimeBlinkFrequency;
        break;
    case States::YELLOW:
        if (isYellowBlinking && currentYellowSwitchesCount_ < yellowSwitchesMaxCount_)
        {
            trafficLightState = States::EMPTY;
            currentYellowSwitchesCount_++;
        }
        else if (currentDirection == SwitchDirection::FORWARD)
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount_ = 0;
            trafficLightState = States::GREEN;
            currentSwitchTime = greenTimeSwitch;
        }
        else
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount_ = 0;
            trafficLightState = States::RED;
            currentSwitchTime = redTimeSwitch;
        }
        break;
    case States::GREEN:
        isYellowBlinking = true;
        trafficLightState = States::YELLOW;
        currentDirection = SwitchDirection::REVERSE;
        currentSwitchTime = yellowTimeBlinkFrequency;
        break;
    default:
        break;
    }
}

void TrafficLight::drawTL(TrafficLight::States currentState)
{
    switch (currentState)
    {
    case TrafficLight::States::EMPTY:
        trafficLightDrawer_.drawEmpty();
        break;
    case TrafficLight::States::RED:
        trafficLightDrawer_.drawRed();
        break;
    case TrafficLight::States::YELLOW:
        trafficLightDrawer_.drawYellow();
        break;
    case TrafficLight::States::GREEN:
        trafficLightDrawer_.drawGreen();
        break;
    default:
        break;
    }
}

void TrafficLight::handlePressedKey(char pressedKey)
{
    switch (pressedKey)
    {
    case 'S':
    case 's':
        onStartButtonPressed();
        break;
    case 'P':
    case 'p':
        onPauseButtonPressed();
        break;
    case 'E':
    case 'e':
        onExitButtonPressed();
        break;
    default:
        break;
    }
}

void TrafficLight::onStartButtonPressed()
{
    isStopped = false;
}

void TrafficLight::onPauseButtonPressed()
{
    if (myTimer.isTimerRunning())
    {
        isStopped = true;
        timeRemainingUntilSwitch = myTimer.stopTimer();
        std::cout << "Paused. Time remaining: " + std::to_string(timeRemainingUntilSwitch.count()) + "ms" << std::endl;
    }
}

void TrafficLight::onExitButtonPressed()
{
    isFinished = true;
}