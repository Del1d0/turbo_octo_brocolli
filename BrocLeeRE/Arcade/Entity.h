#pragma once
#include "EntityController.h"

struct Coords
{
	Coords(int X, int Y) : x(X), y(Y) {};
	~Coords() {};
	int x;
	int y;
};

struct Velocity
{
	Velocity(int Vx, int Vy) : vx(Vx), vy(Vy) {};
	~Velocity() {};
	int vx;
	int vy;
};

struct HitboxDimensions
{
	HitboxDimensions(int width, int height) :
		width(width), height(height) {};
	~HitboxDimensions() {};
	int width = 1;
	int height = 1;
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
	NONE
};

enum EntityType
{
	PLAYER,
	ENEMY,
	BULLET,
	ROCKET,
	OBSTACLE
};

class Entity
{
public:
	Entity(Coords coords, EntityType type, Velocity velocity);
	~Entity() {};
	virtual Coords move() = 0; //��������� ������������ (�������, ��������)
				 //������� ����� �� ������, ������ ����� ���������� (?), ������ �� ������, ����� ����� ����� (������ ������� ��� ��������)
	virtual void OnCollision() = 0; //�������������� � ������� Entity ��� ��������?
			 //�� �������, ��� ������� �������������� (���������� ������� ������ ������ (Coords) Entity ��� ���-�� ���� ����)?
	
protected:
	Direction mDirection;
	EntityType mType;
	EntityController mController;
	Coords mPos; //�������
	Velocity mVel; //�������� (�������� ������ ��� ������ ����)

};