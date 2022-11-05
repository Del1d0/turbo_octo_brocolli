#include "../include/Game.h"
#include <iostream>

Game::Game(int winX, int winY, double plSpeed) :
			xWindow(winX),
			yWindow(winY),
			app::GameApp(winX, winY),
			mPlayer1(Player(Vector2(winX / 2, winY - 0.1 * winY), plSpeed))
{
	Initialize();
}

Game::Game(int winX, int winY) :
			xWindow(winX),
			yWindow(winY),
			app::GameApp(winX, winY),
			mPlayer1(Player(Vector2(winX / 2, winY - 0.1 * winY), 1))
{
	Initialize();
}

void Game::Initialize()
{
	render::LoadResource("resources/images/player.png");
}

void Game::Render()
{
	auto pos = mPlayer1.getPosition();
	render::DrawImage("player.png", pos.x, pos.y, 64, 64);
}

void Game::ProcessInput(const Uint8* keyboard)
{
	double speed = mPlayer1.getSpeed();
	auto prevPos = mPlayer1.getPosition();
	
	if (keyboard[SDL_SCANCODE_RIGHT] && !keyboard[SDL_SCANCODE_LEFT]) {
		prevPos.x += speed * 1;
	}
	if (keyboard[SDL_SCANCODE_LEFT] && !keyboard[SDL_SCANCODE_RIGHT]) {
		prevPos.x -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_UP] && !keyboard[SDL_SCANCODE_DOWN]) {
		prevPos.y -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_DOWN] && !keyboard[SDL_SCANCODE_UP]) {
		prevPos.y += speed * 1;
	}

	//assigning new position
	mPlayer1.setPosition(prevPos);
}

void Game::initGame()
{
	//mPlayer1.setPosition(xWindow / 2, yWindow / 2); // initialize player position

	//������������� ������� �������� (������ ��� ������)
}

void Game::update()
{
	// �������� ���������� ������ �� ��������� ����� (��� ����������)
	mPlayer1.action();
	std::cout << "Player position: x = " << mPlayer1.getPosition().x << "\t, y = " << mPlayer1.getPosition().y << std::endl;
	if (mBackgroundObjects.size() == 0)
	{
		std::cout << "New entity has been spawned!!!\n";
		spawnEntity();
	}
	// �������� ���������� ������ �� ��������� �� ������������
	// ����� ��������������� ������, �� ������� ��� ���������, ����� ��� ��� ���� �� ������ ����������� �� �������
	// ��������� ������� ��� ��� ���, � ����������� �� ���� �����

	// �������� ��������� ��������, ����� � �������

	// ����������� ������ � ������ ������� ������� ����
	// ������������ � ���� ������ �� ������
	// ������ ����������� ������������ ������ ������ �� ���������, ���� �������� � ������� (����� �� ������� ����� �����)

	// ����������� ������

	// ����������� ���� ���� ����� (������ � ������� ���� ����� ������ ������ � ����������������, �������������,
	// ����� ���-�� �����������, ��� � ����� ���� �� (�����������) (�������� ��������� ������ ��� ������� ���� ������?)
}

void Game::checkCollisions()
{
	auto plPos = mPlayer1.getPosition();
	auto plHB = mPlayer1.getHitboxSize();
	
	// boundary crossing check
	if (plPos.x > xWindow)
		mPlayer1.setPosition(xWindow, plPos.y);
	else if(plPos.x < 0)
		mPlayer1.setPosition(0, plPos.y);
	else if(plPos.y > yWindow)
		mPlayer1.setPosition(plPos.x, yWindow);
	else if(plPos.y < 0)
		mPlayer1.setPosition(plPos.x, 0);

	// test of collisions with objects
	for (auto ent : mBackgroundObjects)
	{
		if (mPlayer1.checkCollidedHitboxes(ent))
		{
			ent->collide();
		}
	}

	// ����� ����� �� ������� ���� + ����� �����? -> ������� ��� (������� ����������? ��� ������ ������� �� �������?)

	// ��������� ��������� ������� � ��. � ������� �������� ������
	// ���� ��� ������������, �� ������� ���, ����� ������� ������

	// ��������� ������, ��������� ����\��\����\�����\������ (������� enum � ��������)
}

bool Game::checkGameOver()
{
	if (mPlayer1.getHP() <= 0)
		return true;

	// ���� ������� ������ ���, � ��������, ����� �������� �����, ��� �� �������� �������� �� ����, ����� ��������� �������
	// �� �� ��� ��������
	return false;
}

void Game::render()
{
	// ��������� ����
	// ��������� ������
	// ��������� ������
	// ��������� ��������
}

void Game::spawnNewEnemyWave()
{
	if (mEnemies.size() == 0)
	{

	}
	else
	{
		return;
	}
}

void Game::spawnEntity()
{
	auto bcEnt = std::make_shared<Entity>(Vector2(mPlayer1.getPosition().x + 10, 10), EntityType::OBSTACLE, 0);

	bcEnt->setOnCollision(
		[this]()
		{
			std::cout << "collision occured with right one\n";
			mPlayer1.recieveDamage(10);
		}
	);
	mBackgroundObjects.push_back(bcEnt);
}

