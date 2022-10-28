#pragma once
#include "Constants.h"
#include "Entity.h"

class PlayerController
{
public:
	PlayerController() = default;
	void getControls(); // ������� getPlayerInput -> �������� ����� ��������� -> ������� ����� ���������� � Host
	void updatePosition(Entity& host) { setCoordinates(host); };
private:
	void setCoordinates(Entity& hostEntity);
	void getPlayerInput(); // �������� ����� ���� ������ - ��������� ������ � Action
	//Action - enum � ������� ���������� �������� ���� ��������, �������� ����-��, ����� ������
	Action mAction;
};