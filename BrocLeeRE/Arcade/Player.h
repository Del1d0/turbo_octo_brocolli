#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	void mainFire();
	Direction checkController();
	bool isPaused();
private:
	bool mPause = false;
};