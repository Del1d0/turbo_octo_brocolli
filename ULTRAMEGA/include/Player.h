#pragma once
#include "ShootingEntity.h"
#include <memory>


class Player : public ShootingEntity // (двигается, стреляет пушками, стреляет ракетами, лазерами и т.д.)
	// помимо ХП сделать какой-нибудь щит, который теряется от ударов, его можно подзаряжать
{
public:
	Player(Vector2 coords, double speed);
	~Player() {};
	void Shoot() override;
	void Action() override;
	virtual int GetCurrentFrame() override;
	virtual int GetCurrentAnimationLine() override;
	void AddScore(const int sc) { score += sc; };

private:
	//завести enum с типом вооружения, чтобы знать, какое сейчас активно
	int nRockets = 0; // боезапас ракет
	int nLaserShots = 0; // боезапас
	
	int score = 0;
};