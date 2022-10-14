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
	virtual void setCoordinates(Entity& hostEntity) = 0; // ������ ���������� ������ Entity �� ��������� ������� Controller
};