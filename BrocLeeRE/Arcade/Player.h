#pragma once
#include "ShootingEntity.h"

class Player : public ShootingEntity // (двигается, стреляет пушками, стреляет ракетами, лазерами и т.д.)
	// помимо ХП сделать какой-нибудь щит, который теряется от ударов, его можно подзаряжать
{
public:
	Player() = default;
	void shoot() override;
private:
	//завести enum с типом вооружения, чтобы знать, какое сейчас активно
	int nRockets = 0; // боезапас ракет
	int nLaserShots = 0; // боезапас лазеров

	int hpVal = 100;
	int hpCapacity = 100;
	int shieldVal = 50;
	int shieldCapacity = 50;
};