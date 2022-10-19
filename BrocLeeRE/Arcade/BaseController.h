#pragma once
#include "Entity.h"

enum Action
{
	MOVE,
	SHOOT
};

class BaseController
{
public:
	virtual void getControls() = 0;
	void setCoordinates(Entity& hostEntity); // ставит координаты своему Entity на основании решения Controller
protected:
	Action mAction;
};