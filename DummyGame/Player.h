#pragma once
#include <Windows.h>

#include "GameLoop.h"

struct Vec2 {
	int x = 1;
	int y = 1;
};

struct Player {
	int Health = 100;
	int Ammunition = 10;
	int Level = 0;
	int XP = 0;
	int LastButtonPressed; // 0 = W, 1 = S, 2 = A, 3 = D
	bool AttackStatus;
	Vec2 Position;
};

void TakeDamage(Player& p, int amount);
bool CheckPos(int FuturPlayerPosX, int FuturPlayerPosY);
void PlayerInteraction(Player& p);