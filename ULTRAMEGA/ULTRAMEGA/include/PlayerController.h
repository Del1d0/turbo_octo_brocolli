#pragma once
#include "BaseController.h"
#include "Player.h"

class PlayerController : public BaseController
{
public:
	PlayerController(){};
	void getControls() override; // ������� getPlayerInput -> �������� ����� ��������� -> ������� ����� ���������� � Host
	void updatePosition(Entity& host) { setCoordinates(host); };
private:
	void getPlayerInput(); // �������� ����� ���� ������ - ��������� ������ � Action
	//Action - enum � ������� ���������� �������� ���� ��������, �������� ����-��, ����� ������
};