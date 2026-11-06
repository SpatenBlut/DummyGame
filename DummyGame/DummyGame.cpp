#include <iostream>
#include <Windows.h>

#include "Player.h"

// Game Variabls
const int WIDTH = 40;
const int HEIGHT = 20;

int LastButtonPressed; // 0 = W, 1 = S, 2 = A, 3 = D
bool AttackStatus;

Player p;

int grid[HEIGHT][WIDTH] = {
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

bool CheckPos(int FuturPlayerPosX, int FuturPlayerPosY) {
    if (grid[FuturPlayerPosY][FuturPlayerPosX] == 0) {
        return true;
    }
    else {
        return false;
    }
}

void PlayerInteraction() {
    if (GetAsyncKeyState('W') & 0x8000) {
        if (CheckPos(p.Position.x, p.Position.y - 1)) {
            p.Position.y -= 1;
            LastButtonPressed = 0;
        }
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        if (CheckPos(p.Position.x, p.Position.y + 1)) {
            p.Position.y += 1;
            LastButtonPressed = 1;
        }
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        if (CheckPos(p.Position.x - 1, p.Position.y)) {
            p.Position.x -= 1;
            LastButtonPressed = 2;
        }
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        if (CheckPos(p.Position.x + 1, p.Position.y)) {
            p.Position.x += 1;
            LastButtonPressed = 3;
        }
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        AttackStatus = true;
    }
}

void GameLoop() {
    system("cls");

    while (true) {

        PlayerInteraction();

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (grid[y][x] == 1) {
                    std::cout << "#";
                }
                else if(y == p.Position.y && x == p.Position.x){
                    std::cout << "@";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "HP: " << p.Health << "\n" << "AMMO: " << p.Ammunition;
        AttackStatus = false;

        Sleep(100);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
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

    GameLoop();
}