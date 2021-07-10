#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::runTimer(const TrafficLight &tl)
{
    float waitTime = 0;

    time(&lastSwitchTime);

    switch (tl.trafficLightState)
    {
    case TrafficLightStates::EMPTY:
        if (tl.isYellowBlinking)
        {
            waitTime = float(tl.yellowTimeBlinkFrequency);
        }
        break;
    case TrafficLightStates::RED:
        waitTime = float(tl.redTimeSwitch);
        break;
    case TrafficLightStates::YELLOW:
        if (tl.isYellowBlinking)
        {
            waitTime = float(tl.yellowTimeBlinkFrequency);
        }
        break;
    case TrafficLightStates::GREEN:
        waitTime = float(tl.greenTimeSwitch);
        break;
    default:
        break;
    }

    while (difftime(time(&nextSwitchCounter), lastSwitchTime) != waitTime)
    {
    }
}