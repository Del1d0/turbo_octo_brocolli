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
	for (size_t i = 0; i < 4; i++)
	{
		render::LoadResource("resources/images/cloud" + std::to_string(i) + ".png");
	}
	render::LoadResource("resources/images/water.jpg");
	render::LoadResource("resources/images/player.png"); // player
	render::LoadResource("resources/images/slug.png"); // slug
	render::LoadResource("resources/images/apple.png"); // enemy
	
	int numOfClouds = genRandomNumber(16, 32);
	
	std::vector<int> speeds(numOfClouds);
	
	for (size_t i = 0; i < numOfClouds; i++)
		speeds[i] = genRandomNumber(CLOUDS_MIN_SPEED, CLOUDS_MAX_SPEED);
	
	std::sort(speeds.begin(), speeds.end());
	
	for (size_t i = 0; i < numOfClouds; i++)
	{
		auto pos = Vector2(genRandomNumber(-10, xWindow+10), genRandomNumber(-150, -50));
		mBackgroundObjects.push_back(spawnBackgroundObject(pos, speeds[i]));
	}
}

void Game::Render()
{
	render::DrawImage("water.jpg", 0, 0, xWindow, yWindow);
	
	for (auto ent : mBackgroundObjects)
	{
		auto ePos = ent->getPosition();
		auto dim = ent->getSpriteDimensions(); // sprite size
		render::DrawImage("cloud"+std::to_string(ent->getTextureID())+".png", ePos.x, ePos.y, dim.x, dim.y);
	}

	for (auto proj : mProjectiles)
	{
		auto ePos = proj->getPosition();
		render::DrawImage("slug.png", ePos.x, ePos.y, proj->getSpriteSize(), proj->getSpriteSize());
	}
	auto pos = mPlayer1.getPosition();
	render::DrawImage("player.png", pos.x, pos.y, mPlayer1.getSpriteSize(), mPlayer1.getSpriteSize());
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
	if (keyboard[SDL_SCANCODE_SPACE] && mPlayer1.isGunRDY()) // косячно работает (нельзя лететь по диагонали и стрелять)
	{
		auto pnt = std::make_shared<Entity>(static_cast<Entity>(mPlayer1));
		mProjectiles.push_back(spawnProjectile(pnt));
		// cool down
		mPlayer1.setGunTime(SDL_GetTicks()); // setting time of last shot
		mPlayer1.setGunRDY(false);
	}

	//assigning new position
	mPlayer1.setPosition(prevPos);
}

void Game::Update(Uint32 millis)
{
	//std::cout << "Player position: x = " << mPlayer1.getPosition().x << "\t, y = " << mPlayer1.getPosition().y << std::endl;
	Uint32 curTime = SDL_GetTicks();

	mPlayer1.checkCoolDown(curTime);

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

	// reposition clouds after they reach the edge of the screen
	for (auto ent : mBackgroundObjects)
	{
		auto prev_pos = ent->getPosition();
		auto spSize = ent->getSpriteDimensions();
		if (prev_pos.y > yWindow + 2 * spSize.y)
		{
			ent->setPosition(genRandomNumber(0, xWindow), genRandomNumber(-2*spSize.y, -spSize.y));
			int cloud = genRandomNumber(0, 3);
			double factor = ent->getSpeed() / CLOUDS_MAX_SPEED;
			int width = static_cast<int>(factor * genRandomNumber(250, 290));
			int height = static_cast<int>(factor*genRandomNumber(90, 110));
			
			ent->setSpriteDimensions(Vector2(width, height));
			ent->setTextureID(cloud);
		}
	}
	
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		auto pos = mProjectiles[i]->getPosition();
		if (checkBoundaryExit(pos, mProjectiles[i]->getHitboxSize()))
		{
			auto it = mProjectiles.begin() + i;
			mProjectiles.erase(it);
			--i;
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

bool Game::checkBoundaryExit(Vector2& pos, double hitbox)
{
	if (pos.x + hitbox >= xWindow ||
		pos.x - hitbox <= 0       ||
		pos.y + hitbox >= yWindow ||
		pos.y - hitbox <= 0)
	{
		return true;
	}
	else
		return false;
}
