#include "../include/Game.h"
#include <iostream>

Game::Game(int winX, int winY, double plSpeed) :
	xWindow(winX),
	yWindow(winY),
	mPlayer1(Player(Vector2(winX / 2, winY - 0.1 * winY), plSpeed))
{
}

Game::Game(int winX, int winY) :
	xWindow(winX),
	yWindow(winY),
	mPlayer1(Player(Vector2(winX / 2, winY - 0.1 * winY), 1))
{
}

void Game::initGame()
{
	//mPlayer1.setPosition(xWindow / 2, yWindow / 2); // initialize player position

	//инициализация фоновых объектов (облака для начала)
}

void Game::update()
{
	// обновить координаты игрока на основании ввода (или выстрелить)
	mPlayer1.action();
	std::cout << "Player position: x = " << mPlayer1.getPosition().x << "\t, y = " << mPlayer1.getPosition().y << std::endl;
	if (mBackgroundObjects.size() == 0)
	{
		std::cout << "New entity has been spawned!!!\n";
		spawnEntity();
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

	// враги вышли за границы поля + длина врага? -> удалить его (вызвать деструктор? или просто удалить из массива?)

	// проверяем попадание снаряда и пр. в область хитбокса игрока
	// если щит присутствует, то дамажим его, иначе дамажим игрока

	// проверяем бонусы, начисляем очки\хп\щиты\бусты\оружие (завести enum с бонусами)
}

bool Game::checkGameOver()
{
	if (mPlayer1.getHP() <= 0)
		return true;

	// пока умираем только так, в принципе, можно добавить режим, где мы защищаем союзника от волн, тогда добавится условие
	// на хп для союзника
	return false;
}

void Game::render()
{
	// отрисовка фона
	// отрисовка игрока
	// отрисовка врагов
	// отрисовка снарядов
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

