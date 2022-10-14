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
	virtual void shoot() = 0; //�������� �� ������ ������� ����������� (�������, ��������)
protected:
	int bulletCoolDown; // ���������������� �����(�� ������� ��� ����������� ����� ����� ����������)
						// �������� ������ ���� ����� (�������, �������, �������� � �.�.)
};