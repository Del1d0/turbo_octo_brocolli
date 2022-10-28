#pragma once
#include "Constants.h"
#include "Entity.h"



class BaseController
{
public:
	virtual ~BaseController() {};
	virtual void getControls() = 0;
protected:
	Action mAction;
	void setCoordinates(Entity& hostEntity); // ������ ���������� ������ Entity �� ��������� ������� Controller
};