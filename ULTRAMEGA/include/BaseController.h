#pragma once
#include "Constants.h"
#include "Entity.h"
#include <memory>


class BaseController
{
public:
	virtual ~BaseController() {};
	virtual void getControls() = 0;
protected:
	Action mAction;
	void setCoordinates(std::shared_ptr<Entity> hostEntity); // ставит координаты своему Entity на основании решения Controller
};