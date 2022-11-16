#include "../include/Projectile.h"

Projectile::Projectile(Vector2& pos, double speed, bool plHost) :
	Entity(pos, BULLET, speed), isPlayerHosted(plHost)
{
	hpVal = 0;
	hpCapacity = 0;
	shieldCapacity = 0;
	shieldVal = 0;
	spriteSize = 40;
	mHitboxSize = 40;

	framesInLine = 9;
	totalLines = 8;
}

void Projectile::collide(double dmg)
{
	if (onCollision)
	{
		mIsCollided = true;
		mSpeed /= 2;
		timeOfCollision = SDL_GetTicks();
		onCollision(dmg);
		spriteSize *= 2;
	}
}

void Projectile::MovingAlgorithm()
{
	if (!mIsCollided)
	{
		if (isPlayerHosted)
			mAction = MOVE_UP;
		else
			mAction = MOVE_DOWN;
	}
	else
	{
		mAction = MOVE_DOWN;
	}

}