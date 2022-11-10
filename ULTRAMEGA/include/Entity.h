#pragma once
#include <functional>

enum ActionType
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
using CollideCallback = std::function<void(double)>;
class Entity
{
public:
	Entity() = delete;
	Entity(Vector2 coords, EntityType type, double speed = 0.1);
	virtual ~Entity() {};
	virtual void Action();
	
	void SetOnCollision(CollideCallback onCollide);
	void collide(double dmg);
	
	void SetPosition(Vector2& coords) { mPos = coords; };
	void SetPosition(const int x, const int y) { mPos.x = x; mPos.y = y; };
	Vector2 GetPosition() const { return mPos; };
	
	double GetSpeed() const { return mSpeed; };
	
	double GetHitboxSize() const { return mHitboxSize; };
	int GetSpriteSize() const { return spriteSize; };
	Vector2 GetSpriteDimensions() const { return spriteDim; };
	void SetSpriteDimensions(const Vector2& newDim) { spriteDim = newDim; };

	void SetTextureID(const int id) { textureID = id; };
	int GetTextureID() const { return textureID; };
	void SetTextureName(const std::string newName) { textureName = newName; };
	std::string GetTextureName() const { return textureName; };

	bool IsCollided() const { return mIsCollided; };

	int GetHP() const { return hpVal; };
	EntityType GetType() const { return mType; };
	void RecieveDamage(const int dmg);
	
	bool CheckCollidedHitboxes(const std::shared_ptr<Entity> other) const;

protected:
	Direction mDirection;
	EntityType mType = BACKGROUND;
	Vector2 mPos; //позиция
	ActionType mAction;
	double mSpeed = 0;
	double mHitboxSize = 32;
	int spriteSize = 32;
	Vector2 spriteDim = Vector2(32, 32);
	
	int textureID = 0; //for clouds
	std::string textureName;

	int hpVal = 50;
	int hpCapacity = 50;
	int shieldVal = 0;
	int shieldCapacity = 0;

	virtual void MovingAlgorithm();

	bool mIsCollided = false;
private:
	CollideCallback onCollision;

};