#pragma once
#include "Entity.h"

enum WeaponType
{
	CANNON,
	LASER,
	ROCKET,
	MINE
};

class ShootingEntity : public Entity // ����������� ���������� ����� (�����, �����)
{
public:
	ShootingEntity()
	{

	}
	virtual void shoot() = 0; //�������� �� ������ ������� ����������� (�������, ��������)
	virtual void OnCollision() = 0;
	virtual void move() = 0;
protected:
	int bulletCoolDown; // ���������������� �����(�� ������� ��� ����������� ����� ����� ����������)
						// �������� ������ ���� ����� (�������, �������, �������� � �.�.)
};