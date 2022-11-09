#pragma once
#include "Entity.h"
#include "../src/baseapp.h"

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
	
	void checkCoolDown(Uint32 currTime);

	bool isGunRDY() const { return gunRDY; };
	bool isRocketRDY() const { return rocketRDY; };
	bool isLaserRDY() const { return laserRDY; };

	void setGunRDY(const bool status) { gunRDY = status; };
	void setRocketRDY(const bool status) { rocketRDY = status; };
	void setLaserRDY(const bool status) { laserRDY = status; };

	bool getGunCoolDown() const { return gunCoolDown; };
	bool getRocketCoolDown() const { return rocketCoolDown; };
	bool getLaserCoolDown() const { return laserCoolDown; };

	void setGunTime(const Uint32 time) { gunLastShotTime = time; };
	void setRocketTime(const Uint32 time) { rocketLastShotTime = time; };
	void setLaserTime(const Uint32 time) { laserLastShotTime = time; };

protected:
	// cool down times in ms
	int gunCoolDown = 200;
	int rocketCoolDown = 500;
	int laserCoolDown = 1000;
						// добавить разные виды пушек (обычная, быстрая, взрывная и т.д.)

	// ticks since last shot of every weapon
	Uint32 gunLastShotTime = 0;
	Uint32 rocketLastShotTime = 0;
	Uint32 laserLastShotTime = 0;
	
	// flags for different weapons
	bool gunRDY = true;
	bool rocketRDY = true;
	bool laserRDY = true;
};