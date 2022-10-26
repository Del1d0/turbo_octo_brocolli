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

Player::Player(Vector2 coords, Vector2 velocity) :
	ShootingEntity(coords, EntityType::PLAYER, velocity)
{

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
	/*pc.getControls();
	pc.updatePosition(*this);*/
	return;
}
