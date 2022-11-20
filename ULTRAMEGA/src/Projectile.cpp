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

int Projectile::GetCurrentFrame()
{
	auto curTime = SDL_GetTicks();
	if (mIsCollided && (curTime - timeOfLastFrame) > SLUG_EXPOLION_LIFETIME / 72.0)
	{
		timeOfLastFrame = curTime;
		int frame = currentFrame;
		currentFrame++;
		if (currentFrame == framesInLine)
			currentFrame = 0;
		return frame;
	}
	return currentFrame;
}

int Projectile::GetCurrentAnimationLine()
{
	if (mIsCollided)
	{
		if (currentFrame + 1 == framesInLine)
		{
			int line = animationLine;
			animationLine++;
			if (animationLine + 1 == totalLines)
				animationLine = 0;
			currentFrame = 0;
			return line;
		}
		return animationLine;
	}
	return animationLine;
}