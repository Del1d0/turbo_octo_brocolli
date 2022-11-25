#pragma once
#include "ShootingEntity.h"
#include <memory>


class Player : public ShootingEntity // (���������, �������� �������, �������� ��������, �������� � �.�.)
	// ������ �� ������� �����-������ ���, ������� �������� �� ������, ��� ����� �����������
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void Shoot() override;
	void Action() override;
	virtual int GetCurrentFrame() override;
	virtual int GetCurrentAnimationLine() override;
	void AddScore(const int sc) { score += sc; };

private:
	//������� enum � ����� ����������, ����� �����, ����� ������ �������
	int nRockets = 0; // �������� �����
	int nLaserShots = 0; // ��������
	
	int score = 0;
};