#include "src/baseapp.h"
#include "include/Game.h"
#include <iostream>

#undef main
int main() {
	try {
		Game(WINDOW_WIDTH, WINDOW_HEIGHT, 5).Run();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}