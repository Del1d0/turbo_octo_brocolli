#pragma once
#include "Entity.h"
#include "../src/baseapp.h"
#include <iostream>
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
	virtual void Shoot() {}; //стреляет на основе решения контроллера (человек, алгоритм)
	
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

	int GetBulletDamage() const { return mBulletDamage; };
	int GetRocketDamage() const { return mRocketDamage; };
	int GetLaserDamage() const { return mLaserDamage; };

	int GetActiveWeapon() const { return mActiveWeapon; };
	void SetActiveWeapon(const int newActiveWep) {
		if (newActiveWep > 2) // MAXIMUM NUMBER OF WEAPONS
			mActiveWeapon = 0;
		else
			mActiveWeapon = newActiveWep;
		std::cout << "ACTIVE WEP: " << mActiveWeapon << "\n";
		return;
	};
	bool GetSideFromWhichToShoot() const { return isLeft; }; // for rockets (and bullets possibly)

protected:
	// cool down times in ms
	int gunCoolDown = P_CD_GUN;
	int rocketCoolDown = P_CD_ROCKET;
	int laserCoolDown = P_CD_LASER;
						// добавить разные виды пушек (обычная, быстрая, взрывная и т.д.)

	// ticks since last shot of every weapon
	Uint32 gunLastShotTime = 0;
	Uint32 rocketLastShotTime = 0;
	Uint32 laserLastShotTime = 0;
	
	// flags for different weapons
	bool gunRDY = true;
	bool rocketRDY = true;
	bool laserRDY = true;

	int mBulletDamage = P_DMG_GUN;
	int mRocketDamage = P_DMG_ROCKET;
	int mLaserDamage = P_DMG_GUN;

	int mActiveWeapon = 0; // 0 -gun, 1 - rocket, 2 - laser beam (переделать в enum потом)
	bool isLeft = false; // from which side to shoot next projectile
};