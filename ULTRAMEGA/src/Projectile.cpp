#include "../include/Projectile.h"

Projectile::Projectile(Vector2& pos, double speed) :
	Entity(pos, BULLET, speed)
{
	hpVal = 0;
	hpCapacity = 0;
	shieldCapacity = 0;
	shieldVal = 0;
	spriteSize = 20;
	mHitboxSize = 20;
}

void Projectile::movingAlgorithm()
{
	// basic background object behavior
	mAction = MOVE_UP;
}