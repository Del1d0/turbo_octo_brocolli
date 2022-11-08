#include "../include/Projectile.h"

Projectile::Projectile(Vector2& pos, double speed) :
	Entity(pos, BULLET, speed)
{
}

void Projectile::movingAlgorithm()
{
	// basic background object behavior
	mAction = MOVE_UP;
}