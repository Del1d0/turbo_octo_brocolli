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

class ShootingEntity : public Entity // ����������� ���������� ����� (�����, �����)
{
public:
	ShootingEntity(Vector2 coords, EntityType type, double speed);
	virtual ~ShootingEntity() {};
	virtual void Shoot() {}; //�������� �� ������ ������� ����������� (�������, ��������)
	
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
		if (newActiveWep > 1)
			mActiveWeapon = 0;
		else
			mActiveWeapon = newActiveWep;
		std::cout << "ACTIVE WEP: " << mActiveWeapon << "\n";
		return;
	};
	bool GetSideFromWhichToShoot() const { return isLeft; };

protected:
	// cool down times in ms
	int gunCoolDown = 200;
	int rocketCoolDown = 400;
	int laserCoolDown = 1000;
						// �������� ������ ���� ����� (�������, �������, �������� � �.�.)

	// ticks since last shot of every weapon
	Uint32 gunLastShotTime = 0;
	Uint32 rocketLastShotTime = 0;
	Uint32 laserLastShotTime = 0;
	
	// flags for different weapons
	bool gunRDY = true;
	bool rocketRDY = true;
	bool laserRDY = true;

	int mBulletDamage = 20;
	int mRocketDamage = 100;
	int mLaserDamage = 100;

	int mActiveWeapon = 0; // 0 -gun, 1 - rocket (���������� � enum �����)
	bool isLeft = false; // from which side to shoot next projectile
};