#include "TrafficLight.h"

const int TrafficLight::yellowTimeBlinkFrequency = 1;
const int TrafficLight::yellowSwitchesMaxCount = 4;
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
            currentYellowSwitchesCount++;
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
            currentSwitchTime = greenTimeSwitch;
        }
        else
        {
            isYellowBlinking = false;
            currentYellowSwitchesCount = 0;
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

void TrafficLight::onStartButtonPressed()
{
    isPaused = false;
}

void TrafficLight::onPauseButtonPressed()
{
    isPaused = true;
}

void TrafficLight::onExitButtonPressed()
{
    isFinished = true;
}