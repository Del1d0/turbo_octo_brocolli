#include "../include/ShootingEntity.h"

ShootingEntity::ShootingEntity(Vector2 coords, EntityType type, double speed) :
	Entity(coords, type, speed)
{
	// cooldown time is dependent on entity type
}

void ShootingEntity::CheckCoolDown(Uint32 currTime)
{
	if (!gunRDY && (currTime - gunLastShotTime) > gunCoolDown)
	{
		gunRDY = true;
	}
	if (!rocketRDY && (currTime - rocketLastShotTime) > rocketCoolDown)
	{
		rocketRDY = true;
		isLeft = !isLeft;
	}
	if ((currTime - laserLastShotTime) > laserCoolDown)
	{
		laserRDY = true;
	}
}
