#include "../include/Player.h"
#include <iostream>

Player::Player(Vector2 coords, double speed) :
	ShootingEntity(coords, EntityType::PLAYER, speed)
{
	mHitboxSize = 32;
	spriteSize = 32;
}

void Player::Shoot()
{

}

void Player::Action()
{

	return;
}
