#include "../include/ShootingEntity.h"

ShootingEntity::ShootingEntity(Vector2 coords, EntityType type, double speed) :
	Entity(coords, type, speed)
{
	// cooldown time is dependent on entity type
}

void ShootingEntity::checkCoolDown(Uint32 currTime)
{
	if ((currTime - gunLastShotTime) > gunCoolDown)
	{
		gunRDY = true;
	}
	if ((currTime - rocketLastShotTime) > rocketCoolDown)
	{
		rocketRDY = true;
	}
	if ((currTime - laserLastShotTime) > laserCoolDown)
	{
		laserRDY = true;
	}
}
