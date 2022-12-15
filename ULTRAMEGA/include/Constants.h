#pragma once
#include <random>
const int FPS = 60;
const int REFRESH_RATE = static_cast<int>(1000 / FPS); //refresh rate in ms

const int CLOUDS_MAX_SPEED = 9;
const int CLOUDS_MIN_SPEED = 2;
const int EXPLOSION_BLOW_AWAY_SPEED = 10;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

const int SLUG_EXPOLION_LIFETIME = 1850;
const int ROCKET_ANIMATION_INCREMENT = 30;
const int LASER_ACTIVE_PHASE_TIME = 1000;

// COOLDOWNS

const int ENEMY_WAVE_COOLDOWN = 1500; // time between enemy waves

// PLAYER WEAPON COOLDOWNS
const int P_CD_GUN = 100;
const int P_CD_ROCKET = 100;
const int P_CD_LASER = 4000;

// ENEMY WEAPON COOLDOWNS
const int EN_CD_GUN = 200;
const int EN_CD_ROCKET = 400;
const int EN_CD_LASER = 1000000;

// WEAPONS DAMAGE
const int P_DMG_GUN = 10;
const int P_DMG_ROCKET = 100;
const int P_DMG_LASER = 1000;

// вывести все кулдауны в константы!!!

inline int GenRandomNumber(const int a, const int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);
	
	return dist(gen);
}