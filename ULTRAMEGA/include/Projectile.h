#pragma once
#include "Entity.h"
#include "../src/baseapp.h"
class Projectile : public Entity
{
public:
	Projectile(Vector2& pos, double speed, bool plHost = false);
	~Projectile() {};

	void collide(double dmg) override;

	bool IsShotByPlayer() const { return isPlayerHosted; };
	double GetDamageValue() const { return mDamage; };
	
	Uint32 GetTimeOfCollision() const { return timeOfCollision; };
	
	int GetCurrentFrame();
	int GetCurrentAnimationLine();
protected:
	void MovingAlgorithm() override;
	double mDamage = 50;
	bool isPlayerHosted = false;
	Uint32 timeOfCollision = 0;
	
	// for animation
	int currentFrame = 0; // 0 - 8
	int animationLine = 0;
	Uint32 timeOfLastFrame = 0;
private:
};