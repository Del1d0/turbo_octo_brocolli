#pragma once
#include "ShootingEntity.h"

class Player : public ShootingEntity // (���������, �������� �������, �������� ��������, �������� � �.�.)
	// ������ �� ������� �����-������ ���, ������� �������� �� ������, ��� ����� �����������
{
public:
	Player() = default;
	void shoot() override;
private:
	//������� enum � ����� ����������, ����� �����, ����� ������ �������
	int nRockets = 0; // �������� �����
	int nLaserShots = 0; // �������� �������

	int hpVal = 100;
	int hpCapacity = 100;
	int shieldVal = 50;
	int shieldCapacity = 50;
};