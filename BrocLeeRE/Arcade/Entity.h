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
	virtual Coords move() = 0; //двигается контроллером (человек, алгоритм)
				 //снаряды летят по прямой, ракеты могут наводиться (?), лазеры по прямой, враги всяко разно (задать синусом или сплайном)
	virtual void OnCollision() = 0; //взаимодействие с другими Entity при контакте?
			 //не понятно, как сделать взаимодействие (квадратный хитбокс вокруг центра (Coords) Entity или что-то типа того)?
	
protected:
	Direction mDirection;
	EntityType mType;
	EntityController mController;
	Coords mPos; //позиция
	Velocity mVel; //скорость (возможно разная для разных осей)

};