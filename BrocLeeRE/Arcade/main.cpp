#include <iostream>
#include <chrono>

#include "Player.h"
#include "Game.h"
#include "Renderer.h"

using namespace std;

int main()
{
	int FPS = 10;
	int refreshRate = static_cast<int>(1000/FPS); //refresh rate in ms
	
	Player p1;
	bool isPaused = false;
	auto begin = std::chrono::steady_clock::now();
	while (true)
	{
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		if (elapsed_ms.count() == refreshRate)
		{
			//isPaused = p1.isPaused();
			cout << "Doing something\n";
			auto dir = p1.checkController();
			
			
			begin = end;
		}
	}


	
	return 0;
}