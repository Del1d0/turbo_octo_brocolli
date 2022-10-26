#pragma once
#include "ShootingEntity.h"

enum EnemyType
{
	DRONE,
	HEAVYDRONE
};

class EnemyEntity : public ShootingEntity // враги, стреляют в примерном направлении игрока (надо передать позицию игрока)

// буду наследоваться от EnemyEntity для создания разных врагов (ракетные дроны, стреляющие дроны, босс ракетовоз с лазерами и прочим)
{
public:
	void shoot() override;
	virtual void onCollision() override;
};