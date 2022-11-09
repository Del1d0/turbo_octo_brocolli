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
	int cloud = genRandomNumber(0, 3);
	int width = genRandomNumber(250, 290);
	int height = genRandomNumber(90, 110);
	
	auto bcEnt = std::make_shared<Entity>(position, EntityType::BACKGROUND, speed);
	bcEnt->setSpriteDimensions(Vector2(width, height));
	bcEnt->setTextureID(cloud);
	return bcEnt;
}
