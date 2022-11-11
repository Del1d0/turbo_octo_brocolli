#include "../include/EnemyEntity.h"
#include <iostream>

EnemyEntity::EnemyEntity(Vector2& pos, EnemyType type) :
	ShootingEntity(pos, ENEMY, 1)
{
	mEnType = type;
	switch (mEnType)
	{
	case DRONE:
		hpCapacity = 50;
		hpVal = hpCapacity;
		mDamage = 10;
		mSpeed = 6;
		break;
	case HEAVYDRONE:
		hpCapacity = 150;
		hpVal = hpCapacity;
		mDamage = 20;
		mSpeed = 2;
		break;
	default:
		hpCapacity = 50;
		hpVal = hpCapacity;
		mDamage = 10;
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
	double amplitude = WINDOW_HEIGHT / 2.2;
	double period = 8000;
	mPos.x = WINDOW_WIDTH / 2.0 + amplitude* cos(2 * M_PI * time / period + initPhase);
	mPos.y = -100*(2*initPhase/(2*M_PI)) + mSpeed * time / 500.0;
}
