#ifndef INPUT_H_
#define INPUT_H_

#include <functional>

class Input
{
private:
    char pressedKey;

    struct tlCallbacks
    {
        std::function<void()> startCallback;
        std::function<void()> pauseCallback;
        std::function<void()> exitCallback;
    };

    struct timerCallbacks
    {
        std::function<void()> startCallback;
        std::function<void()> pauseCallback;
        std::function<void()> exitCallback;
    };
    
    tlCallbacks tlCb;
    timerCallbacks timerCb;

public:
    // Основная функция для ввода
    // Реагирует только на латинские буквы
    void handleInput();

    Input(std::function<void()> tlStartFunc, std::function<void()> tlPauseFunc, std::function<void()> tlExitFunc,
          std::function<void()> timerStartFunc, std::function<void()> timerPauseFunc, std::function<void()> timerExitFunc)
        : tlCb{tlStartFunc, tlPauseFunc, tlExitFunc},
          timerCb{timerStartFunc, timerPauseFunc, timerExitFunc}
    {
    }
};
#endif