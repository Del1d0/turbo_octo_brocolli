#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(Vector2& pos, double speed);
protected:
	void movingAlgorithm() override;
};