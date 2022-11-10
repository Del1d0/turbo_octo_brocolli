#include "../include/Projectile.h"

Projectile::Projectile(Vector2& pos, double speed, bool plHost) :
	Entity(pos, BULLET, speed)
{
	hpVal = 0;
	hpCapacity = 0;
	shieldCapacity = 0;
	shieldVal = 0;
	spriteSize = 20;
	mHitboxSize = 20;
}

void Projectile::collide(double dmg)
{
	if (onCollision)
	{
		mIsCollided = true;
		mSpeed /= 2;
		timeOfCollision = SDL_GetTicks();
		onCollision(dmg);
	}
}

void Projectile::MovingAlgorithm()
{
	if (!mIsCollided)
	{
		mAction = MOVE_UP;
	}
	else
	{
		mAction = MOVE_DOWN;
	}
}