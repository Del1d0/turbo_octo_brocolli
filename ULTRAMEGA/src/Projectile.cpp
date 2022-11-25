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
		framesInLine = 9;
		totalLines = 8;
		spriteDim.x = 91;
		spriteDim.y = 93;
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
	// обобщить для всех анимаций (условие только для взрыва стоит, надо поменять)
	if (mIsCollided && (curTime - timeOfLastFrame) > SLUG_EXPOLION_LIFETIME / 72.0 || (!mIsCollided && (curTime - timeOfLastFrame) > ROCKET_ANIMATION_INCREMENT))
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
///
//====================================================== R O C K E T =================================================== 
///

Rocket::Rocket(Vector2& spawnPos, double speed, bool plHosted) :
	Projectile(spawnPos, speed, plHosted)
{
	spawnPosition = spawnPos;
	mSpeed = 0.0015;
	acceleration = 0.0007;
	textureName = "missile0";
	framesInLine = 6;
	totalLines = 1;
	double scale = 0.6;
	spriteDim.x = 33*scale;
	spriteDim.y = 98*scale;
}

void Rocket::Action()
{
	if (!mIsCollided)
	{
		int dir = (isPlayerHosted) ? -1 : 1;
		double dt = (SDL_GetTicks() - mSpawnTime);
		mPos.y = spawnPosition.y + dir*mSpeed*dt + dir*acceleration*dt*dt/2.0;
	}
	else
	{
		mPos.y += 10;
	}
}

void Rocket::MovingAlgorithm()
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
