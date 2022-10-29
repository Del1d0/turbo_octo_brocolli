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
	
	bool checkCollidedHitboxes(const Entity* other) const;
private:
	//������� enum � ����� ����������, ����� �����, ����� ������ �������
	int nRockets = 0; // �������� �����
	int nLaserShots = 0; // �������� 
	PlayerController pc;
};