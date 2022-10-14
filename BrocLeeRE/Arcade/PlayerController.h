#pragma once
#include "BaseController.h"
#include "Player.h"

class PlayerController : public BaseController
{
public:
	void getControls() override; // ������� getPlayerInput -> �������� ����� ��������� -> ������� ����� ���������� � Host
	void setCoordinates(Player& hPlayer) override; // �������� � private ������ � �������� ������ �� getControls()
private:
	Action getPlayerInput(); // �������� ����� ���� ������ - ��������� ������ � Action
	//Action - enum � ������� ���������� �������� ���� ��������, �������� ����-��, ����� ������
};