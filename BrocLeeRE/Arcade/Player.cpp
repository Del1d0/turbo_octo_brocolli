#include "Player.h"
#include <conio.h>
#include <iostream>

//Direction Player::checkController()
//{
//    Direction dir = mDirection;
//    if (_kbhit())
//    {
//        char userInput = _getch();
//        std::cout << "uInput: " << userInput << std::endl;
//        switch (userInput)
//        {
//        case 'w':
//            dir = UP;
//            break;
//        case 's':
//            dir = DOWN;
//            break;
//        case 'a':
//            dir = LEFT;
//            break;
//        case 'd':
//            dir = RIGHT;
//            break;
//        case 'p':
//            dir = NONE;
//            break;
//        default:
//            dir = NONE;
//            break;
//        }
//    }
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

Player::Player()
{
	mController = PlayerController();
}

void Player::move()
{

}
