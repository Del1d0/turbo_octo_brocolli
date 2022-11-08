#include "../include/Game.h"
#include <iostream>
#include <random>

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
	
	int numOfClouds = genRandomNumber(1, 8);
	
	for (size_t i = 0; i < numOfClouds; i++)
	{
		auto pos = Vector2(genRandomNumber(5, xWindow), genRandomNumber(-50, -30));
		mBackgroundObjects.push_back(spawnBackgroundObject(pos, genRandomNumber(1, 5)));
	}
}

void Game::Render()
{

	for (auto ent : mBackgroundObjects)
	{
		auto ePos = ent->getPosition();
		render::DrawImage("apple.png", ePos.x, ePos.y, 64, 64);
	}

	for (auto proj : mProjectiles)
	{
		auto ePos = proj->getPosition();
		render::DrawImage("slug.png", ePos.x, ePos.y, 16, 16);
	}
	auto pos = mPlayer1.getPosition();
	render::DrawImage("player.png", pos.x, pos.y, 64, 64);
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
	if (keyboard[SDL_SCANCODE_SPACE]) // косячно работает (нельзя лететь по диагонали и стрелять)
	{
		auto pnt = std::make_shared<Entity>(static_cast<Entity>(mPlayer1));
		mProjectiles.push_back(spawnProjectile(pnt));
	}

	//assigning new position
	mPlayer1.setPosition(prevPos);
}

void Game::Update(Uint32 millis)
{
	//std::cout << "Player position: x = " << mPlayer1.getPosition().x << "\t, y = " << mPlayer1.getPosition().y << std::endl;

	for (auto ent : mBackgroundObjects)
	{
		ent->action();
	}

	for (auto prj : mProjectiles)
	{
		prj->action();
	}

	CheckCollisions();
	
	if (CheckGameOver())
	{
		GameOver();
	}
	// обновить координаты врагов на основании их контроллеров
	// можно параметризовать кривую, по которой они двигаются, чтобы они шли друг за другом паровозиком по зигзагу
	// шахматный порядок или еще что, в зависимости от типа врага

	// обновить положения снарядов, ракет и прочего

	// передвинуть облака и прочие фоновые объекты вниз
	// столкновения с ними ничего не делают
	// вообще проверяется столкновение только игрока со снарядами, либо снарадов с врагами (враги не наносят урона своим)

	// передвинуть бонусы

	// прострелять всем кому можно (вообще у каждого типа врага разное оружие и скорострельность, соответсвенно,
	// нужно как-то отслеживать, что у врага идет КД (перезарядка) (заводить отдельный таймер для каждого типа оружия?)
}

void Game::CheckCollisions()
{
	auto plPos = mPlayer1.getPosition();

	// test of collisions with objects
	/*for (auto ent : mBackgroundObjects)
	{
		if (mPlayer1.checkCollidedHitboxes(ent))
		{
			ent->collide();
		}
	}*/

	for (auto ent : mBackgroundObjects)
	{
		auto prev_pos = ent->getPosition();
		auto spSize = ent->getSpriteSize();
		if (prev_pos.y > yWindow + 2 * spSize)
		{
			ent->setPosition(genRandomNumber(0, xWindow), genRandomNumber(-2*spSize, -spSize));
		}
	}

	// враги вышли за границы поля + длина врага? -> удалить его (вызвать деструктор? или просто удалить из массива?)

	// проверяем попадание снаряда и пр. в область хитбокса игрока
	// если щит присутствует, то дамажим его, иначе дамажим игрока

	// проверяем бонусы, начисляем очки\хп\щиты\бусты\оружие (завести enum с бонусами)
}

bool Game::CheckGameOver()
{
	if (mPlayer1.getHP() <= 0)
		return true;

	// пока умираем только так, в принципе, можно добавить режим, где мы защищаем союзника от волн, тогда добавится условие
	// на хп для союзника
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

int Game::genRandomNumber(int a, int b)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);

	return dist(gen);
}

