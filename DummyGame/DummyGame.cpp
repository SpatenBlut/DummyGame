#include <iostream>
#include <Windows.h>
#include "GameLoop.h"
#include "Player.h"

int main()
{
    std::cout << "Press W to start Game";

    while (true) {   
        
        if (GetAsyncKeyState('W') & 0x8000) {
            break;
        }

        Sleep(100);
    }
    system("cls");

    //game loop
    using clock = std::chrono::steady_clock;
    constexpr auto TICK = std::chrono::milliseconds(50); // 20 Ticks/s

    auto nextTick = clock::now();

	while (true) {
        //revert the bool
        doubleTick = !doubleTick;

		update();
		render();
        
        nextTick += TICK;
        std::this_thread::sleep_until(nextTick);

	}
}