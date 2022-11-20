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
	void SetDamageValue(double value) { mDamage = value; };
	
	Uint32 GetTimeOfCollision() const { return timeOfCollision; };
	
	
protected:
	void MovingAlgorithm() override;
	double mDamage = 10;
	bool isPlayerHosted = false;
	Uint32 timeOfCollision = 0;

	int GetCurrentFrame() override;
	int GetCurrentAnimationLine() override;

private:
};