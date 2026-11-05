#pragma once

struct Vec2 {
	float x;
	float y;
};

struct Player {
	int Health;
	int Ammunition;

	Vec2 Position;
	char Name[16];

	void TakeDamage(int amount);
};