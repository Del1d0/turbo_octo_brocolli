#include "../include/Renderer.h"
#include <iostream>

Renderer::Renderer(int nX, int nY) :
	winX(nX),
	winY(nY)
{
	mMap = std::vector<std::string>(nY);
	initMap();
}

void Renderer::render(Player& pl, std::vector<Entity*>& jk)
{
	for (size_t i = 0; i < winY; i++)
	{
		std::cout << mMap[i];
	}
}

void Renderer::initMap()
{
	for (size_t i = 0; i < winY; i++)
	{
		std::string line;
		for (size_t j = 0; j < winX; j++)
		{
			char ch = ' ';
			if(j == 0 || j == winX - 1)
				ch = '#';
			line.push_back(ch);
		}
		line.push_back('\n');
		mMap[i] = line;
	}
}
