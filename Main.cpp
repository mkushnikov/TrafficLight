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
    Input myInput(
        std::bind(&TrafficLight::onStartButtonPressed, &myTL),
        std::bind(&TrafficLight::onPauseButtonPressed, &myTL),
        std::bind(&TrafficLight::onExitButtonPressed, &myTL),
        std::bind(&Timer::onStartButtonPressed, &myTimer),
        std::bind(&Timer::onPauseButtonPressed, &myTimer),
        std::bind(&Timer::onExitButtonPressed, &myTimer));
    Output myOutput;

    thread input(&Input::handleInput, myInput);

    while (!myTL.isFinished)
    {
        if (!myTL.isPaused && !myTimer.isRunning)
        {
            myOutput.clearConsole();
            myOutput.showControllInfo();
            myOutput.drawTL(myTL.trafficLightState);
            myTimer.runTimer(std::chrono::milliseconds(myTL.currentSwitchTime * 1000), std::bind(&TrafficLight::updateTLState, &myTL));
        }
    }

    input.detach();
}
