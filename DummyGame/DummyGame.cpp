#include <iostream>
#include <Windows.h>
#include <thread>

#include "Player.h"

void PlayerInput(){

}

void GameLoop() {

    // Game Variabls
    const int WIDTH = 20;
    const int HEIGHT = 10;

    int playerX = 5;
    int playerY = 4;

    while (true) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        for (int x = 0; x < WIDTH + 2; x++)
            std::cout << "#";
        std::cout << std::endl;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (x == 0) {
                    std::cout << "#";
                }

                if (playerX == x && playerY == y) {
                    std::cout << "@";
                }
                else {
                    std::cout << " ";
                }

                if (x == WIDTH - 1) {
                    std::cout << "#";
                }
            }
            std::cout << std::endl;
        }

        for (int x = 0; x < WIDTH + 2; x++)
            std::cout << "#";
        std::cout << std::endl;

        Sleep(100);
    }
}


int main()
{
    std::cout << "Press W to start Game";

    while (true) {   
        
        if (GetAsyncKeyState('W') & 0x8000) {
            break;
        }

        Sleep(100);
    }

    std::thread t(PlayerInput);
    std::thread t1(GameLoop);

    system("cls");
    // Game Loop
    
    while (true) {
        t.join();
        t1.join();
    }
}


