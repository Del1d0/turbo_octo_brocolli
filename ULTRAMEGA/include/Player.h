#pragma once
#include "ShootingEntity.h"
#include <memory>

class Player : public ShootingEntity // (двигается, стреляет пушками, стреляет ракетами, лазерами и т.д.)
	// помимо ХП сделать какой-нибудь щит, который теряется от ударов, его можно подзаряжать
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void shoot() override;
	void action() override;
	
	bool checkCollidedHitboxes(const std::shared_ptr<Entity> other) const;
private:
	//завести enum с типом вооружения, чтобы знать, какое сейчас активно
	int nRockets = 0; // боезапас ракет
	int nLaserShots = 0; // боезапас
};