#include "../include/Entity.h"
#include <iostream>

Entity::Entity(Vector2 coords, EntityType type, double speed) :
	mPos(coords),
	mSpeed(speed),
	mType(type)
{
	mAction = ActionType::IDLE;
	mDirection = Direction::NONE;
}

void Entity::Action()
{
	MovingAlgorithm();
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

void Entity::SetOnCollision(CollideCallback onCollide)
{
	this->onCollision = onCollide;
}

void Entity::collide(double dmg)
{
	if (onCollision)
	{
		mIsCollided = true;
		onCollision(dmg);
	}
}

void Entity::RecieveDamage(int dmg)
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

void Entity::MovingAlgorithm()
{
	// basic background object behavior
	mAction = MOVE_DOWN;
}

bool Entity::CheckCollidedHitboxes(const std::shared_ptr<Entity> other) const
{
	// check whether the player's hitbox crosses other's hitbox
	auto entPos = other->GetPosition();
	double hitBox = other->GetHitboxSize();

	if ((mPos.x + mHitboxSize >= entPos.x - hitBox) &&
		(mPos.x - mHitboxSize <= entPos.x + hitBox) &&
		(mPos.y + mHitboxSize >= entPos.y - hitBox) &&
		(mPos.y - mHitboxSize <= entPos.y + hitBox))
		return true;
	else
		return false;
}