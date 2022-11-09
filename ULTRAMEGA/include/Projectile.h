#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(Vector2& pos, double speed, bool plHost = false);
	~Projectile() {};
	bool IsShotByPlayer() const { return isPlayerHosted; };
protected:
	void MovingAlgorithm() override;
private:
	bool isPlayerHosted = false;
};