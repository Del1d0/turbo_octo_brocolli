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
	virtual void Shoot() = 0; //стреляет на основе решения контроллера (человек, алгоритм)
	
	void CheckCoolDown(Uint32 currTime);

	bool IsGunRDY() const { return gunRDY; };
	bool IsRocketRDY() const { return rocketRDY; };
	bool IsLaserRDY() const { return laserRDY; };

	void SetGunRDY(const bool status) { gunRDY = status; };
	void SetRocketRDY(const bool status) { rocketRDY = status; };
	void SetLaserRDY(const bool status) { laserRDY = status; };

	bool GetGunCoolDown() const { return gunCoolDown; };
	bool GetRocketCoolDown() const { return rocketCoolDown; };
	bool GetLaserCoolDown() const { return laserCoolDown; };

	void SetGunTime(const Uint32 time) { gunLastShotTime = time; };
	void SetRocketTime(const Uint32 time) { rocketLastShotTime = time; };
	void SetLaserTime(const Uint32 time) { laserLastShotTime = time; };

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