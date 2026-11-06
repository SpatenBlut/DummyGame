#pragma once

struct Vec2 {
	float x = 1;
	float y = 1;
};

struct Player {
	int Health = 100;
	int Ammunition = 10;

	Vec2 Position;
	char Name[16];

	void TakeDamage(int amount);
};