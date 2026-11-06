#include "Player.h"

void TakeDamage(Player& p, int amount) {
	p.Health = p.Health - amount;
}

bool CheckPos(int FuturPlayerPosX, int FuturPlayerPosY) {
    if (grid[FuturPlayerPosY][FuturPlayerPosX] == 0) {
        return true;
    }
    else {
        return false;
    }
}

void PlayerInteraction(Player& p) {
    if (GetAsyncKeyState('W') & 0x8000) {
        if (CheckPos(p.Position.x, p.Position.y - 1)) {
            p.Position.y -= 1;
            p.LastButtonPressed = 0;
        }
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        if (CheckPos(p.Position.x, p.Position.y + 1)) {
            p.Position.y += 1;
            p.LastButtonPressed = 1;
        }
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        if (CheckPos(p.Position.x - 1, p.Position.y)) {
            p.Position.x -= 1;
            p.LastButtonPressed = 2;
        }
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        if (CheckPos(p.Position.x + 1, p.Position.y)) {
            p.Position.x += 1;
            p.LastButtonPressed = 3;
        }
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        p.AttackStatus = true;
    }
}