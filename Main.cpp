#include "TrafficLight.h"
#include "Input.h"
#include "Output.h"

#include <thread>

using std::thread;

int main()
{
    TrafficLight myTL;
    Input myInput;
    Output myOutput;

    myInput.addSub([&](char k)
                   { myTL.handlePressedKey(k); });

    thread input(&Input::handleInput, myInput);

    while (!myTL.isFinished)
    {
        if (!myTL.isStopped && !myTL.myTimer.isRunning)
        {
            myOutput.clearConsole();
            myOutput.showControllInfo();
            myOutput.drawTL(myTL.trafficLightState);
            if (myTL.timeRemainingUntilSwitch == std::chrono::milliseconds(0))
            {
                myTL.myTimer.runTimer(std::chrono::milliseconds(myTL.currentSwitchTime * 1000), [&]
                                      { myTL.updateTLState(); });
            }
            else
            {
                myTL.myTimer.runTimer(std::chrono::milliseconds(myTL.timeRemainingUntilSwitch), [&]
                                      { myTL.updateTLState(); });
                myTL.timeRemainingUntilSwitch = std::chrono::milliseconds(0);
            }
        }
    }

    input.detach();
}
