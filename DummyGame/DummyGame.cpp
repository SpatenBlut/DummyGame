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

    int grid[HEIGHT][WIDTH] = {
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    };

    while (true) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (grid[y][x] == 1) {
                    std::cout << "#";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        

        Sleep(100);
    }
}


int main()
{
    std::thread t(PlayerInput);
    std::thread t1(GameLoop);

    t.join();
    t1.join();

    std::cout << "Press W to start Game";

    while (true) {   
        
        if (GetAsyncKeyState('W') & 0x8000) {
            break;
        }

        Sleep(100);
    }

    system("cls");
    
    while (true) {
    }
}


