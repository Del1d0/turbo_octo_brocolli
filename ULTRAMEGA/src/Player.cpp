#include "../include/Player.h"
#include <iostream>

Player::Player(Vector2 coords, double speed) :
	ShootingEntity(coords, EntityType::PLAYER, speed)
{
	mHitboxSize = 90;
	spriteSize = mHitboxSize;
	onCollision =
		[this](double dmg)
		{
			std::cout << dmg << " Player damage recieved\t HP = " << this->GetHP() << std::endl;
			this->RecieveDamage(dmg);
		};

	hpVal = 100;
	hpCapacity = 100;
	shieldVal = 40;
	shieldCapacity = 40;
	mBulletDamage = 40;
}

void Player::Shoot()
{

}

void Player::Action()
{

	return;
}

int Player::GetCurrentFrame()
{
	return 0;
}

int Player::GetCurrentAnimationLine()
{
	return 0;
}
