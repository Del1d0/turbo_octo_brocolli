#include "../include/ShootingEntity.h"

ShootingEntity::ShootingEntity(Vector2 coords, EntityType type, double speed) :
	Entity(coords, type, speed)
{
	bulletCoolDown = 10;
	// cooldown time is dependent on entity type
}
