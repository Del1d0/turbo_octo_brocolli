#pragma once
#include "ShootingEntity.h"

enum EnemyType
{
	DRONE,
	HEAVYDRONE
};

class EnemyEntity : public ShootingEntity // �����, �������� � ��������� ����������� ������ (���� �������� ������� ������)

// ���� ������������� �� EnemyEntity ��� �������� ������ ������ (�������� �����, ���������� �����, ���� ��������� � �������� � ������)
{
public:
	EnemyEntity(Vector2& pos, EnemyType type);
	void Shoot() override;
	void RecieveDamage(const double dmg) { hpVal -= dmg; };
	void Action() override;
	
	void setInitPhase(const double phase) { initPhase = phase; };
protected:
	void MovingAlgorithm() override;

private:
	EnemyType mEnType;
	double initPhase = 0;
	
};