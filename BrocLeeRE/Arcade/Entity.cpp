#include "Entity.h"

Entity::Entity(Coords& coords, EntityType& type, Velocity& velocity) :
	mPos(coords),
	mVel(velocity),
	mType(type)
{
	
}
