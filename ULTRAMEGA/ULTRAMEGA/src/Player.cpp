#include "../include/Player.h"

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

void Player::onCollision()
{
	return;
}

void Player::action()
{
	pc.getControls();
	pc.updatePosition(*this);
	return;
}
