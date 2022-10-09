#pragma once

struct Coordinats
{
	int x;
	int y;
};
struct HitboxDimensions
{
	HitboxDimensions(int width, int height) :
		width(width), height(height) {};
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
	~Entity() {};
protected:
	Coordinats mPosition;
	Direction mDirection;
	EntityType mType;
	int mVertSpeed = 1;
	int mHorSpeed = 1;

};