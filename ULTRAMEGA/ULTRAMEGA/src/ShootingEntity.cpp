#include "../include/ShootingEntity.h"

ShootingEntity::ShootingEntity(Vector2 coords, EntityType type, Vector2 velocity) :
	Entity(coords, type, velocity)
{
	bulletCoolDown = 10;
	// cooldown time is dependent on entity type
}
