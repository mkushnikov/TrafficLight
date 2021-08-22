#include "TrafficLight.h"

#include <iostream>
#include <string>

const int TrafficLight::yellowTimeBlinkFrequency = 1;
const int TrafficLight::yellowSwitchesMaxCount_ = 4;
const int TrafficLight::redTimeSwitch = 2;
const int TrafficLight::greenTimeSwitch = 3;

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
    isStopped = true;
    timeRemainingUntilSwitch = myTimer.stopTimer();
    std::cout << "Paused. Time remaining: " + std::to_string(timeRemainingUntilSwitch.count()) + "ms" << std::endl;
}

void TrafficLight::onExitButtonPressed()
{
    isFinished = true;
}