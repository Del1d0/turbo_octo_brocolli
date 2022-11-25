#pragma once
#include <random>
const int FPS = 60;
const int REFRESH_RATE = static_cast<int>(1000 / FPS); //refresh rate in ms

const int CLOUDS_MAX_SPEED = 9;
const int CLOUDS_MIN_SPEED = 2;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

const int SLUG_EXPOLION_LIFETIME = 1850;
const int ROCKET_ANIMATION_INCREMENT = 30;

const int ENEMY_WAVE_COOLDOWN = 1500; // time between enemy waves

inline int GenRandomNumber(const int a, const int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);
	
	return dist(gen);
}