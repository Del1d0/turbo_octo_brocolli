#pragma once
#include "Player.h"
#include "Renderer.h"
#include <vector>

class Game
{
public:
	Game(Player &pl, Renderer &rnd, std::vector<Entity*> &ents);
	void render();
private:
	const Player mPlayer;
	const Renderer mRenderer;
	std::vector<Entity*> mEntities;
	
	int winX = 50;
	int winY = 100;

};