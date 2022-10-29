#include "../include/Player.h"
#include <iostream>

//Direction Player::checkController()
//{
//    
//    return dir;
//}
//
//bool Player::isPaused()
//{
//    if (_kbhit())
//    {
//        char userInput = _getch();
//        switch (userInput)
//        {
//        case 'p':
//            mPause = !mPause;
//        }
//    }
//    return mPause;
//}

Player::Player(Vector2 coords, double speed) :
	ShootingEntity(coords, EntityType::PLAYER, speed)
{
	pc = PlayerController();
}

void Player::shoot()
{
	return;
}

void Player::action()
{
	pc.getControls();
	pc.updatePosition(*this);
	return;
}

bool Player::checkCollidedHitboxes(const Entity* other) const
{
	// check whether the player's hitbox crosses other's hitbox
	auto entPos = other->getPosition();
	double hitBox = other->getHitboxSize();

	if ((mPos.x + mHitboxSize >= entPos.x - hitBox) &&
		(mPos.x - mHitboxSize <= entPos.x + hitBox) &&
		(mPos.y + mHitboxSize >= entPos.y - hitBox) &&
		(mPos.y - mHitboxSize <= entPos.y + hitBox))
		return true;
	else
		return false;
}
