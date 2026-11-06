#pragma once

struct Vec2 {
	float x = 1;
	float y = 1;
};

struct Player {
	int Health = 100;
	int Ammunition = 10;
	int Level = 0;
	int XP = 0;


	Vec2 Position;

	void TakeDamage(int amount);
};