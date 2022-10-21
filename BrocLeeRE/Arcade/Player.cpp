#include "Player.h"

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

Player::Player()
{

}

void Player::action()
{
	mController.getControls();
}
