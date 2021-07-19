#include "Timer.h"

void Timer::runTimer(const TrafficLight &tl)
{
    float waitTime = 0;

    time(&lastSwitchTime);

    switch (tl.trafficLightState)
    {
    case TrafficLight::States::EMPTY:
        if (tl.isYellowBlinking)
        {
            waitTime = float(tl.yellowTimeBlinkFrequency);
        }
        break;
    case TrafficLight::States::RED:
        waitTime = float(tl.redTimeSwitch);
        break;
    case TrafficLight::States::YELLOW:
        if (tl.isYellowBlinking)
        {
            waitTime = float(tl.yellowTimeBlinkFrequency);
        }
        break;
    case TrafficLight::States::GREEN:
        waitTime = float(tl.greenTimeSwitch);
        break;
    default:
        break;
    }

    while (difftime(time(&nextSwitchCounter), lastSwitchTime) != waitTime)
    {
    }
}