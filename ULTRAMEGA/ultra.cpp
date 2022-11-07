#include "src/baseapp.h"
#include "include/Game.h"
#include <iostream>

#undef main
int main() {
	try {
		Game(800, 800, 10).Run();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}