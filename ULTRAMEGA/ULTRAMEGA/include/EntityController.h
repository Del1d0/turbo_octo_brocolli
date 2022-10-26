#pragma once
#include "BaseController.h"

class EntityController : public BaseController
{
public:
	EntityController() {};
	~EntityController() {};
	void getControls() override;
	// ������ ������������ ������ �������� ����?
private:
	Vector2 movingAlgorithm(Vector2& prevLocation); // ����. ���������� ������� �� hostEntity � � ���� �� ������������ �����
	// ������ �������� ������ ���������� �� ������ ���� Entity
	// ����� ���� ������� ��������� ���� � ��������� ��� �������� ���� Utils � �������� ������
};