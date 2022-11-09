#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "Constants.h"


class EntityFactory
{
public:
	std::shared_ptr<Projectile> spawnProjectile(std::shared_ptr<Entity> host);
	std::shared_ptr<Entity> spawnBackgroundObject(Vector2& position, double speed);
};