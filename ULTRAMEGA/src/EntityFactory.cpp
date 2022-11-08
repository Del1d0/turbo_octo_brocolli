#pragma once
#include "../include/EntityFactory.h"

std::shared_ptr<Projectile> EntityFactory::spawnProjectile(std::shared_ptr<Entity> host)
{
	if (host->getType() == PLAYER)
	{

	}
	auto projectile = std::make_shared<Projectile>(Vector2(host->getPosition().x, host->getPosition().y - 2), 10);
	
	projectile->setOnCollision(
		[this]()
		{
			// put functional here
		}
	);

	return projectile;
}

std::shared_ptr<Entity> EntityFactory::spawnBackgroundObject(Vector2& position, double speed)
{
	auto bcEnt = std::make_shared<Entity>(position, EntityType::BACKGROUND, speed);
	return bcEnt;
}
