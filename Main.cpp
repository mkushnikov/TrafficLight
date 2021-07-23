#include "TrafficLight.h"
#include "Timer.h"
#include "Input.h"
#include "Output.h"

#include <thread>

using std::thread;

int main()
{
    TrafficLight myTL;
    Timer myTimer;
    // Input myInput;
    Output myOutput;

    while (true)
    {
        myOutput.showControllInfo();
        myOutput.drawTL(myTL.trafficLightState);
        myTimer.runTimer(std::chrono::seconds(myTL.currentSwitchTime), std::bind(&TrafficLight::updateTLState, &myTL), false);
        myOutput.clearConsole();
    }
}
