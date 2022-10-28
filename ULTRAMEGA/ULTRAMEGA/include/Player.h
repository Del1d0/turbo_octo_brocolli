#pragma once
#include "ShootingEntity.h"
#include "PlayerController.h"

class Player : public ShootingEntity // (���������, �������� �������, �������� ��������, �������� � �.�.)
	// ������ �� ������� �����-������ ���, ������� �������� �� ������, ��� ����� �����������
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void shoot() override;
	void action() override;
	void recieveDamage();
	int getHP() const { return hpVal; };
private:
	//������� enum � ����� ����������, ����� �����, ����� ������ �������
	int nRockets = 0; // �������� �����
	int nLaserShots = 0; // �������� 
	PlayerController pc;
	int hpVal = 100;
	int hpCapacity = 100;
	int shieldVal = 50;
	int shieldCapacity = 50;
};