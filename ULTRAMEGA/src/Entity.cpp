#include "../include/Entity.h"
#include <iostream>

Entity::Entity(Vector2 coords, EntityType type, double speed) :
	mPos(coords),
	mSpeed(speed),
	mType(type)
{
	mAction = Action::IDLE;
	mDirection = Direction::NONE;
}

void Entity::action()
{
	movingAlgorithm();
	switch (mAction)
	{
	case MOVE_UP:
		mPos.y -= mSpeed;
		break;
	case MOVE_DOWN:
		mPos.y += mSpeed;
		break;
	case MOVE_RIGHT:
		mPos.x += mSpeed;
		break;
	case MOVE_LEFT:
		mPos.x -= mSpeed;
		break;
	default:
		return;
	}

	return;
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

void Entity::movingAlgorithm()
{
	// basic background object behavior
	mAction = MOVE_DOWN;
}
