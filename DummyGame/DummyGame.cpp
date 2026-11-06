#include <iostream>
#include <Windows.h>
#include "GameLoop.h"
#include "Player.h"

Player p;

int main()
{
    std::cout << "Press W to start Game";

    while (true) {   
        
        if (GetAsyncKeyState('W') & 0x8000) {
            break;
        }

        Sleep(100);
    }

    GameLoop();
}