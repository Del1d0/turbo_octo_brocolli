#include "../include/Projectile.h"
#include <iostream>

Projectile::Projectile(Vector2& pos, double speed, bool plHost) :
	Entity(pos, BULLET, speed), isPlayerHosted(plHost)
{
	mSpawnTime = SDL_GetTicks();
	hpVal = 0;
	hpCapacity = 0;
	shieldCapacity = 0;
	shieldVal = 0;
	spriteSize = 40;
	mHitboxSize = 40;

	framesInLine = 9;
	totalLines = 8;
	frameTime = SLUG_EXPOLION_LIFETIME / (framesInLine * totalLines);

}

void Projectile::collide(double dmg)
{
	if (onCollision)
	{
		mIsCollided = true;
		mSpeed = EXPLOSION_BLOW_AWAY_SPEED;
		timeOfCollision = SDL_GetTicks();
		onCollision(dmg);
		spriteSize *= 2;
		framesInLine = 9;
		totalLines = 8;
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
	if ((curTime - timeOfLastFrame) > frameTime)
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
	mSpeed = 0.0001;
	acceleration = 0.001;
	textureName = "missile0";
	framesInLine = 6;
	totalLines = 1;
	double scale = 0.58;
	spriteDim.x = 33*scale;
	spriteDim.y = 98*scale;
	frameTime = ROCKET_ANIMATION_INCREMENT;
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
		mPos.y += EXPLOSION_BLOW_AWAY_SPEED;
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

///
//====================================================== L A S E R =================================================== 
///

Laser::Laser(Vector2& spawnPos, bool plHosted):
	Projectile(spawnPos, 0, plHosted)
{	
	lifespan = LASER_ACTIVE_PHASE_TIME + initTime;
	mType = LASER;
	spriteDim.x = 400;
	spriteDim.y = 96;
	mDamage = 20;
	mHitboxDim = spriteDim;

	totalLines = 1;
	framesInLine = 9;
	frameTime = initTime / (totalLines * framesInLine);
}

void Laser::Action()
{
	if (isInitializing)
	{
		mPos.y += mPos.y - 15; // костылек, чтобы спавнился где надо во время инициализации
		spriteDim.x = 400;
		spriteDim.y = 96;
		mHitboxDim.x = 1;
		mHitboxDim.y = 1;
	}
	if (isActive)
	{
		spriteDim.x = 50;
		spriteDim.y = 2 * (mPos.y);
		mHitboxDim = spriteDim;
	}
	CheckLifetime();
}

void Laser::CheckLifetime()
{
	auto cTime = SDL_GetTicks();
	if ((cTime - mSpawnTime > lifespan) && !isItTimeToDie)
	{
		isItTimeToDie = true;
		isActive = false;
		std::cout << "laser dying\n";
	}
	if (isInitializing && (cTime - mSpawnTime) > initTime && !isActive)
	{
		isInitializing = false;
		isActive = true;
		isUsingAnimation = false; // поменять на тру когда будет анимация луча
		textureName = "laserBeam";
		std::cout << "laser done initializing\n";
	}
}

void Laser::MovingAlgorithm()
{

}

void Laser::CheckInitEnd()
{
	
}
