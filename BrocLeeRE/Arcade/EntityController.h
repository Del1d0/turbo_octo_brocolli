#pragma once
#include "BaseController.h"

class EntityController : public BaseController
{
public:
	void getControls() override;
	// ������ ������������ ������ �������� ����?
private:
	Coords movingAlgorithm(Coords& prevLocation); // ����. ���������� ������� �� hostEntity � � ���� �� ������������ �����
	// ������ �������� ������ ���������� �� ������ ���� Entity
	// ����� ���� ������� ��������� ���� � ��������� ��� �������� ���� Utils � �������� ������
};