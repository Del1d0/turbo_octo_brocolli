#include "../include/Entity.h"
#include <iostream>

Entity::Entity(Vector2 coords, EntityType type, double speed) :
	mPos(coords),
	mSpeed(speed),
	mType(type)
{
	mSpawnTime = SDL_GetTicks();
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

int Entity::GetCurrentFrame()
{
	auto curTime = SDL_GetTicks();
	if (mIsCollided && (curTime - timeOfLastFrame) > SLUG_EXPOLION_LIFETIME / 72.0)
	{
		timeOfLastFrame = curTime;
		int frame = currentFrame;
		currentFrame++;
		if (currentFrame == framesInLine)
			currentFrame = 0;
		return frame;
	}
	return currentFrame;
}

int Entity::GetCurrentAnimationLine()
{
	if (mIsCollided)
	{
		if (currentFrame + 1 == framesInLine)
		{
			int line = animationLine;
			animationLine++;
			if (animationLine + 1 == totalLines)
				animationLine = 0;
			currentFrame = 0;
			return line;
		}
		return animationLine;
	}
	return animationLine;
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
	auto hb = other->GetHitboxDimensions();

	if ((mPos.x + mHitboxDim.x/2 >= entPos.x - hb.x/2) &&
		(mPos.x - mHitboxDim.x/2 <= entPos.x + hb.x/2) &&
		(mPos.y + mHitboxDim.y/2 >= entPos.y - hb.y/2) &&
		(mPos.y - mHitboxDim.y/2 <= entPos.y + hb.y/2))
		return true;
	else
		return false;
}
