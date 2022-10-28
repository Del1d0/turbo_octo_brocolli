#include "../include/Entity.h"

Entity::Entity(Vector2 coords, EntityType type, double speed) :
	mPos(coords),
	mSpeed(speed),
	mType(type)
{
	mDirection = Direction::NONE;
}
