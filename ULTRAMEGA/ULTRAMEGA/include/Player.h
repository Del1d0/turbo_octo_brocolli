#pragma once
#include "ShootingEntity.h"
#include "PlayerController.h"

class Player : public ShootingEntity // (двигается, стреляет пушками, стреляет ракетами, лазерами и т.д.)
	// помимо ХП сделать какой-нибудь щит, который теряется от ударов, его можно подзаряжать
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void shoot() override;
	void onCollision() override;
	void action() override;
private:
	//завести enum с типом вооружения, чтобы знать, какое сейчас активно
	int nRockets = 0; // боезапас ракет
	int nLaserShots = 0; // боезапас 
	PlayerController pc;
	int hpVal = 100;
	int hpCapacity = 100;
	int shieldVal = 50;
	int shieldCapacity = 50;
};