#include "Entity.h"

Entity::Entity(Vector2& coords, EntityType& type, Vector2& velocity) :
	mPos(coords),
	mVel(velocity),
	mType(type)
{
	
}
