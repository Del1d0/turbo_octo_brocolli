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

void Player::recieveDamage()
{
	if (shieldVal > 0)
	{
		std::cout << "shield damaged\n";
		shieldVal -= 10;
	}
	else
	{
		std::cout << "damage recieved\n";
		hpVal -= 10;
	}
}
