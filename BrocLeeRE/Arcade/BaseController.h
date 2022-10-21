#pragma once
#include "Entity.h"
#include "Constants.h"

enum Action
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	SHOOT,
	WEP_CHANGE,
	USE_BONUS,
	PAUSE,
	IDLE
};

class BaseController
{
public:
	virtual ~BaseController() {};
	virtual void getControls() = 0;
protected:
	Action mAction;
	void setCoordinates(Entity& hostEntity); // ставит координаты своему Entity на основании решения Controller
	void actionToMovement();

};