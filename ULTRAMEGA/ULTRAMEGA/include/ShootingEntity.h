#pragma once
#include "Entity.h"

//enum WeaponType
//{
//	CANNON,
//	LASER,
//	ROCKET,
//	MINE
//};

class ShootingEntity : public Entity // управляемая стреляющая штука (враги, игрок)
{
public:
	ShootingEntity(Vector2 coords, EntityType type, double speed);
	virtual ~ShootingEntity() {};
	virtual void shoot() = 0; //стреляет на основе решения контроллера (человек, алгоритм)
protected:
	int bulletCoolDown = 10; // скорострельность пушки(не понятно как отсчитывать время между выстрелами)
						// добавить разные виды пушек (обычная, быстрая, взрывная и т.д.)
};