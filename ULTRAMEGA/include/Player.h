#pragma once
#include "ShootingEntity.h"
#include <memory>

class Player : public ShootingEntity // (���������, �������� �������, �������� ��������, �������� � �.�.)
	// ������ �� ������� �����-������ ���, ������� �������� �� ������, ��� ����� �����������
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void shoot() override;
	void action() override;
	
	bool checkCollidedHitboxes(const std::shared_ptr<Entity> other) const;
private:
	//������� enum � ����� ����������, ����� �����, ����� ������ �������
	int nRockets = 0; // �������� �����
	int nLaserShots = 0; // ��������
};