#include "TrafficLight.h"
#include "Input.h"

#include <thread>

int main()
{
    TrafficLight myTL;
    Input myInput;

    myInput.addSub([&](char k)
                   { myTL.handlePressedKey(k); });

    std::thread input(&Input::handleInput, myInput);

    myTL.runTrafficLight();

    input.detach();
    return 0;
}
