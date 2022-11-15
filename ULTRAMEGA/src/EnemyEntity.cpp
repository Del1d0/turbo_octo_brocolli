#include "../include/EnemyEntity.h"
#include <iostream>

EnemyEntity::EnemyEntity(Vector2& pos, EnemyType type) :
	ShootingEntity(pos, ENEMY, 1)
{
	mEnType = type;
	double shrinkFactor = 3;
	switch (mEnType)
	{
	case DRONE:
		hpCapacity = 500;
		hpVal = hpCapacity;
		mBulletDamage = 10;
		mSpeed = 0.03;
		spriteDim.x = 190 / shrinkFactor;
		spriteDim.y = 220 / shrinkFactor;
		mHitboxDim.x = (spriteDim.x)/shrinkFactor;
		mHitboxDim.y = (spriteDim.y)/shrinkFactor;
 		break;
	case HEAVYDRONE:
		hpCapacity = 150;
		hpVal = hpCapacity;
		mBulletDamage = 20;
		mSpeed = 2;
		break;
	default:
		hpCapacity = 50;
		hpVal = hpCapacity;
		mBulletDamage = 10;
		mSpeed = 6;
		break;
	}
}

void EnemyEntity::Shoot()
{
}

void EnemyEntity::Action()
{
	MovingAlgorithm();
}

void EnemyEntity::MovingAlgorithm()
{
	Uint32 time = SDL_GetTicks(); // time in seconds
	if (time - gunLastShotTime > 1000)
	{
		gunRDY = true;
	}
	double amplitude = WINDOW_HEIGHT / 2.2;
	double period = 8000;
	mPos.x = WINDOW_WIDTH / 2.0 + amplitude* cos(2 * M_PI * (time - mSpawnTime) / period + initPhase);
	mPos.y = -50 -200*(2*initPhase/(2*M_PI)) + mSpeed * (time - mSpawnTime);
}
