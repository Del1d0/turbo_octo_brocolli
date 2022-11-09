#pragma once
#include <random>
const int FPS = 60;
const int REFRESH_RATE = static_cast<int>(1000 / FPS); //refresh rate in ms

const int CLOUDS_MAX_SPEED = 10;
const int CLOUDS_MIN_SPEED = 2;

inline int genRandomNumber(const int a, const int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);
	
	return dist(gen);
}