#include "TrafficLight.h"
#include "Timer.h"
#include "Input.h"

#include <thread>

using std::thread;

TrafficLight myTL;
Timer myTimer;
Input myInput;

// Чистка консоли
// Кажется платформо-зависимое, но для начала сойдёт))
void clearConsole()
{
    system("cls");
}

// Основная функция для вывода
// Контролирует отрисовку, реагируя на ввод
void displayTL()
{
    // Отрисовка пока не нажали "выход"
    while (!myTL.isFinished)
    {
        // Обновляем, если не "пауза"
        if (myTL.isStarted)
        {
            clearConsole();
            myTL.showControllInfo();
            myTL.updateTLState();
            myTL.drawTL();
            myTimer.runTimer(myTL);
        }
    }
}

int main()
{
    // Запускаем потоки на ввод/вывод
    thread input([]
                 { myInput.handleInput(myTL); });
    thread output(displayTL);

    // Освобождаем основной поток
    input.join();
    output.join();
}
