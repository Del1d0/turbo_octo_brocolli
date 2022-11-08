#include "../include/Player.h"
#include <iostream>

Player::Player(Vector2 coords, double speed) :
	ShootingEntity(coords, EntityType::PLAYER, speed)
{
}

void Player::shoot()
{

}

void Player::action()
{

	return;
}

bool Player::checkCollidedHitboxes(const std::shared_ptr<Entity> other) const
{
	// check whether the player's hitbox crosses other's hitbox
	auto entPos = other->getPosition();
	double hitBox = other->getHitboxSize();

	if ((mPos.x + mHitboxSize >= entPos.x - hitBox) &&
		(mPos.x - mHitboxSize <= entPos.x + hitBox) &&
		(mPos.y + mHitboxSize >= entPos.y - hitBox) &&
		(mPos.y - mHitboxSize <= entPos.y + hitBox))
		return true;
	else
		return false;
}
