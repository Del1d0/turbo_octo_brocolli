#pragma once
#include <vector>
#include <string>
#include "Entity.h"
#include "Player.h"

class Renderer
{
public:
	Renderer(int nX = 50, int nY = 100);
	void render(Player &pl, std::vector<Entity*> &jk);
private:
	void initMap();
	int winX;
	int winY;
	std::vector<std::string> mMap;
};