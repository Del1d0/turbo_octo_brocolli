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
	void shoot() override;

protected:
	int mDamage;
};