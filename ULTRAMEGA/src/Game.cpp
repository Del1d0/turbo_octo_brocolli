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
			mPlayer1(Player(Vector2(winX / 2, winY + 0.1 * winY), 1))
{
	Initialize();
}

void Game::Initialize()
{


	render::LoadResource("resources/images/player.png"); // player
	render::LoadResource("resources/images/slug.png"); // slug
	render::LoadResource("resources/images/apple.png"); // enemy
}

void Game::Render()
{
	auto pos = mPlayer1.getPosition();
	render::DrawImage("player.png", pos.x, pos.y, 64, 64);

	for (auto ent : mBackgroundObjects)
	{
		auto ePos = ent->getPosition();
		render::DrawImage("apple.png", ePos.x, ePos.y, 64, 64);
	}
}

void Game::ProcessInput(const Uint8* keyboard)
{
	double speed = mPlayer1.getSpeed();
	auto prevPos = mPlayer1.getPosition();

	if (keyboard[SDL_SCANCODE_RIGHT] && !keyboard[SDL_SCANCODE_LEFT] && !(prevPos.x >= xWindow - 2*mPlayer1.getSpriteSize())) {
		prevPos.x += speed * 1;
	}
	if (keyboard[SDL_SCANCODE_LEFT] && !keyboard[SDL_SCANCODE_RIGHT] && !(prevPos.x <= 0)) {
		prevPos.x -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_UP] && !keyboard[SDL_SCANCODE_DOWN] && !(prevPos.y <= 0)) {
		prevPos.y -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_DOWN] && !keyboard[SDL_SCANCODE_UP] && !(prevPos.y >= yWindow - 2*mPlayer1.getSpriteSize())) {
		prevPos.y += speed * 1;
	}
	if (keyboard[SDL_SCANCODE_SPACE])
	{
		mPlayer1.shoot();
	}



	//assigning new position
	mPlayer1.setPosition(prevPos);
}

void Game::Update(Uint32 millis)
{
	// �������� ���������� ������ �� ��������� ����� (��� ����������)
	mPlayer1.action();
	std::cout << "Player position: x = " << mPlayer1.getPosition().x << "\t, y = " << mPlayer1.getPosition().y << std::endl;
	if (mBackgroundObjects.size() == 0)
	{
		std::cout << "New entity has been spawned!!!\n";
		spawnEntity();
	}

	CheckCollisions();
	
	if (CheckGameOver())
		GameOver();
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

void Game::CheckCollisions()
{
	auto plPos = mPlayer1.getPosition();

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

bool Game::CheckGameOver()
{
	if (mPlayer1.getHP() <= 0)
		return true;

	// ���� ������� ������ ���, � ��������, ����� �������� �����, ��� �� �������� �������� �� ����, ����� ��������� �������
	// �� �� ��� ��������
	return false;
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

