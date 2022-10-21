#include <iostream>
#include <chrono>
#include "Constants.h"
#include "Player.h"
#include "Entity.h"
#include "Game.h"
#include "Renderer.h"

using namespace std;

int main()
{	
	Renderer randy(50, 100);
	bool isPaused = false;
	int winX = 100;
	int winY = 100;
	Game game(winX, winY);
	game.initGame();
	
	auto begin = std::chrono::steady_clock::now();
	while (true)
	{
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		if (elapsed_ms.count() == refreshRate)
		{
			cout << "Doing something\n";
			
			game.update();
			game.checkCollisions();
			game.checkGameOver();
			game.render();

			begin = end;
		}
	}


	
	return 0;
}