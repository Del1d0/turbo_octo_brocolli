#pragma once
#include <functional>

enum Action
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	SHOOT,
	WEP_CHANGE,
	USE_BONUS,
	PAUSE,
	IDLE
};

struct Vector2
{
	Vector2(double X = 0, double Y = 0) : x(X), y(Y) {};
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

	double x = 0;
	double y = 0;
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
	OBSTACLE,
	BACKGROUND
};

class Entity
{
public:
	Entity() = delete;
	Entity(Vector2 coords, EntityType type, double speed = 0.1);
	virtual ~Entity() {};
	virtual void action(); //двигается контроллером (человек, алгоритм)
	//снаряды летят по прямой, ракеты могут наводиться (?), лазеры по прямой, враги всяко разно (задать синусом или сплайном)
	void setOnCollision(std::function<void()> onCollide);
	void collide(); //взаимодействие с другими Entity при контакте
	void setPosition(Vector2& coords) { mPos = coords; };
	void setPosition(const int x, const int y) { mPos.x = x; mPos.y = y; };
	Vector2 getPosition() const { return mPos; };
	double getSpeed() const { return mSpeed; };
	double getHitboxSize() const { return mHitboxSize; };
	int getSpriteSize() const { return spriteSize; };
	Vector2 getSpriteDimensions() const { return spriteDim; };
	void setSpriteDimensions(const Vector2& newDim) { spriteDim = newDim; };

	void setTextureID(const int id) { textureID = id; };
	int getTextureID() const { return textureID; };

	int getHP() const { return hpVal; };
	EntityType getType() const { return mType; };
	void recieveDamage(const int dmg);

protected:
	Direction mDirection;
	EntityType mType = BACKGROUND;
	Vector2 mPos; //позиция
	Action mAction;
	double mSpeed = 0; //скорость (возможно разная для разных осей)
	double mHitboxSize = 32;
	int spriteSize = 32;
	Vector2 spriteDim = Vector2(32, 32);
	//for clouds
	int textureID = 0;

	int hpVal = 100;
	int hpCapacity = 100;
	int shieldVal = 50;
	int shieldCapacity = 50;

	virtual void movingAlgorithm();

private:
	std::function<void()> onCollision;
	bool isCollided = false;

};