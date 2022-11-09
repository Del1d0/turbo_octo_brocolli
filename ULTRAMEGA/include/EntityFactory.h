#pragma once
#include "EnemyEntity.h"
#include "Projectile.h"
#include "Constants.h"

class Game;

class EntityFactory
{
public:
	std::shared_ptr<Projectile> SpawnProjectile(std::shared_ptr<Entity> host);
	std::shared_ptr<Entity> SpawnBackgroundObject(Vector2& position, double speed);
	std::shared_ptr<EnemyEntity> SpawnEnemy(Vector2& position, EnemyType type);
private:
	Game* game;
};