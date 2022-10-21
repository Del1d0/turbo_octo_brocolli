#pragma once
#include "BaseController.h"
#include "Player.h"

class PlayerController : public BaseController
{
public:
	void getControls() override; // ������� getPlayerInput -> �������� ����� ��������� -> ������� ����� ���������� � Host
private:
	void getPlayerInput(); // �������� ����� ���� ������ - ��������� ������ � Action
	//Action - enum � ������� ���������� �������� ���� ��������, �������� ����-��, ����� ������
};