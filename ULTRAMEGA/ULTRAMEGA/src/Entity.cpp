#include "../include/Entity.h"
#include <iostream>

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

void Entity::recieveDamage(int dmg)
{
	if (shieldVal > 0)
	{
		std::cout << "shield damaged\n";
		shieldVal -= dmg;
	}
	else
	{
		std::cout << "damage recieved\n";
		hpVal -= dmg;
	}
}
