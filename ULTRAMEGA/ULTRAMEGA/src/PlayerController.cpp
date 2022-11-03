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
		//std::cout << "USER INPUT: " << userInput << std::endl;
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
	else
		mAction = Action::IDLE;
	return;
}

void PlayerController::setCoordinates(Entity* hostEntity)
{
	Vector2 vel1;
	
	switch (mAction)
	{
	case MOVE_UP:
		//std::cout << "UP\n";
		vel1 = Vector2(0, 1);
		break;
	case MOVE_DOWN:
		//std::cout << "DOWN\n";
		vel1 = Vector2(0, -1);
		break;
	case MOVE_RIGHT:
		//std::cout << "RIGHT\n";
		vel1 = Vector2(1, 0);
		break;
	case MOVE_LEFT:
		//std::cout << "LEFT\n";
		vel1 = Vector2(-1, 0);
		break;
	case IDLE:
		//std::cout << "IDLE\n";
		return;
	default:
		return;
	}

	Vector2 newCoord = hostEntity->getPosition() + vel1*hostEntity->getSpeed();

	hostEntity->setPosition(newCoord);

	return;
}