#include "Player.h"

void Player::TakeDamage(int amount) {
	Player::Health = Player::Health - amount;
}