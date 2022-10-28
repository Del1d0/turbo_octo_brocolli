#include <iostream>
#include <chrono>
#include "../ULTRAMEGA/include/Constants.h"
#include "../ULTRAMEGA/include/Player.h"
#include "../ULTRAMEGA/include/Entity.h"
#include "../ULTRAMEGA/include/Game.h"

using namespace std;
int main()
{
	//Renderer randy(50, 100);
	bool isPaused = false;
	int winX = 100;
	int winY = 100;
	Game game(winX, winY, 1);
	game.initGame();

	auto begin = std::chrono::steady_clock::now();
	while (true)
	{
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		if (elapsed_ms.count() == REFRESH_RATE)
		{
			//cout << "Doing something\n";

			game.update();
			game.checkCollisions();
			game.checkGameOver();
			//game.render();

			begin = end;
			TIME_PASSED += (REFRESH_RATE / 1000.0);
		}
	}



	return 0;
}