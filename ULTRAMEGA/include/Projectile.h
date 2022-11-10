#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(Vector2& pos, double speed, bool plHost = false);
	~Projectile() {};
	bool IsShotByPlayer() const { return isPlayerHosted; };
	double GetDamageValue() const { return mDamage; };
protected:
	void MovingAlgorithm() override;
	double mDamage = 50;
	bool isPlayerHosted = false;
private:
};