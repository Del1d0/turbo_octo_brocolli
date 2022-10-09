#include "Game.h"

Game::Game(Player& pl, Renderer& rnd, std::vector<Entity*>& ents) :
	mPlayer(pl),
	mRenderer(rnd),
	mEntities(ents)
{}

void Game::render()
{

}
