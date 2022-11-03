#pragma once
#include "BaseController.h"

class EnemyController : public BaseController
{
public:
	EnemyController() {};
	~EnemyController() {};
	void getControls() override;
	// ������ ������������ ������ �������� ����?
private:
	Vector2 movingAlgorithm(Vector2& prevLocation); // ����. ���������� ������� �� hostEntity � � ���� �� ������������ �����
	// ������ �������� ������ ���������� �� ������ ���� Entity
	// ����� ���� ������� ��������� ���� � ��������� ��� �������� ���� Utils � �������� ������
};