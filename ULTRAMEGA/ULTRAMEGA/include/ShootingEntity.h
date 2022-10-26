#pragma once
#include "Entity.h"

//enum WeaponType
//{
//	CANNON,
//	LASER,
//	ROCKET,
//	MINE
//};

class ShootingEntity : public Entity // ����������� ���������� ����� (�����, �����)
{
public:
	ShootingEntity(Vector2 coords, EntityType type, Vector2 velocity);
	virtual ~ShootingEntity() {};
	virtual void shoot() = 0; //�������� �� ������ ������� ����������� (�������, ��������)
	//virtual void onCollision() = 0;
protected:
	int bulletCoolDown = 10; // ���������������� �����(�� ������� ��� ����������� ����� ����� ����������)
						// �������� ������ ���� ����� (�������, �������, �������� � �.�.)
};