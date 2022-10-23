#pragma once
#include "EntityController.h"

struct Vector2
{
	Vector2(int X = 0, int Y = 0) : x(X), y(Y) {};
	Vector2(const Vector2& other) : x(other.x), y(other.y) {};
	~Vector2() {};

	Vector2 operator+(Vector2 other)
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 operator*(double a)
	{
		return Vector2(a * this->x, a * this->y);
	}

	int x = 0;
	int y = 0;
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
	Entity(Vector2& coords, EntityType& type, Vector2& velocity);
	virtual ~Entity() {};
	virtual void action() = 0; //двигается контроллером (человек, алгоритм)
				 //снаряды летят по прямой, ракеты могут наводиться (?), лазеры по прямой, враги всяко разно (задать синусом или сплайном)
	virtual void onCollision() = 0; //взаимодействие с другими Entity при контакте?
			 //не понятно, как сделать взаимодействие (квадратный хитбокс вокруг центра (Vector2) Entity или что-то типа того)?
	void setPosition(Vector2& coords) { mPos = coords; };
	void setPosition(int x, int y) { mPos.x = x; mPos.y = y; };
	Vector2 getPosition() const { return mPos; }; 
protected:
	Direction mDirection;
	EntityType mType;
	EntityController mController = EntityController();
	Vector2 mPos; //позиция
	Vector2 mVel; //скорость (возможно разная для разных осей)

};