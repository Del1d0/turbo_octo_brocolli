#include "../include/Entity.h"

Entity::Entity(Vector2 coords, EntityType type, double speed) :
	mPos(coords),
	mSpeed(speed),
	mType(type)
{
	mDirection = Direction::NONE;
}

void Entity::action()
{

}

void Entity::setOnCollision(std::function<void()> onCollide)
{
	this->onCollision = onCollide;
}

void Entity::collide()
{
	if (onCollision)
	{
		isCollided = true;
		onCollision();
	}
}
