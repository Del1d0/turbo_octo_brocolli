#include "../include/PlayerController.h"
#include <conio.h>
#include <iostream>

void PlayerController::getControls()
{
	getPlayerInput(); // recieve player input and set mAction
	return;
}

void PlayerController::getPlayerInput()
{
	if (_kbhit())
	{
		char userInput = _getch();
		switch (userInput)
		{
		case 'w':
			mAction = Action::MOVE_UP;
			break;
		case 's':
			mAction = Action::MOVE_DOWN;
			break;
		case 'a':
			mAction = Action::MOVE_LEFT;
			break;
		case 'd':
			mAction = Action::MOVE_RIGHT;
			break;
		case 'p':
			mAction = Action::PAUSE;
			break;
		case 'k':
			mAction = Action::SHOOT;
			break;
		case 'c':
			mAction = Action::WEP_CHANGE;
			break;
		default:
			mAction = Action::IDLE;
			break;
		}
	}

	return;
}
