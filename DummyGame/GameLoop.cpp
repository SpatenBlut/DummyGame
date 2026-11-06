#include "GameLoop.h"

void GameLoop() {
    system("cls");

    Player p;

    while (true) {
        PlayerInteraction(p);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (grid[y][x] == 1) {
                    std::cout << "#";
                }
                else if (y == p.Position.y && x == p.Position.x) {
                    std::cout << "@";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "HP: " << p.Health << "\n" << "AMMO: " << p.Ammunition;
        p.AttackStatus = false;

        Sleep(1);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }
}