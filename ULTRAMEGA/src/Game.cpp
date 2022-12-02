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
	render::LoadResource("resources/images/player1.png"); // player
	render::LoadResource("resources/images/slug.png"); // slug
	render::LoadResource("resources/images/explosion0.png");
	render::LoadResource("resources/images/lightDrone.png"); // enemy
	render::LoadResource("resources/images/apple.png", "rocket"); // rocket
	render::LoadResource("resources/images/laserBeam.png", "laserBeam"); // laser
	
	BakeTextureAtlas("resources/images/explosions_sprite0.png", "explosion0", 90, 93, 9, 9);
	BakeTextureAtlas("resources/images/missile_sprite0.png", "missile0", 91, 33, 0, 6);
	BakeTextureAtlas("resources/images/laserInit.png", "laserInit", 96, 400, 0, 10);

	int numOfClouds = GenRandomNumber(16, 32);
	std::vector<int> speeds(numOfClouds);
	for (size_t i = 0; i < numOfClouds; i++)
		speeds[i] = GenRandomNumber(CLOUDS_MIN_SPEED, CLOUDS_MAX_SPEED);
	
	std::sort(speeds.begin(), speeds.end());
	
	for (size_t i = 0; i < numOfClouds; i++)
	{
		auto pos = Vector2(GenRandomNumber(-10, xWindow+10), GenRandomNumber(-150, -50));
		mBackgroundObjects.push_back(SpawnBackgroundObject(pos, speeds[i]));
	}
	//SpawnNewEnemyWave();
}

void Game::Render()
{
	render::DrawImage("water.jpg", 0, 0, xWindow, yWindow);
	
	for (auto ent : mBackgroundObjects)
	{
		auto ePos = ent->GetPosition();
		auto dim = ent->GetSpriteDimensions(); // sprite size
		render::DrawImage("cloud"+std::to_string(ent->GetTextureID())+".png", ePos.x - 0.5*dim.x, ePos.y - 0.5*dim.y, dim.x, dim.y);
	}

	for (auto enemy : mEnemies)
	{
		auto pos = enemy->GetPosition();
		auto spDim = enemy->GetSpriteDimensions();
		render::DrawImage("lightDrone.png", pos.x - 0.5*spDim.x, pos.y - 0.5*spDim.y, spDim.x, spDim.y);
	}

	auto pos = mPlayer1.GetPosition();
	double spSize = mPlayer1.GetSpriteSize();
	
	for (auto proj : mProjectiles)
	{
		auto ePos = proj->GetPosition();
		// std::cout << "y: " << ePos.y << "\n";
		auto sp = proj->GetSpriteDimensions(); 
		if (proj->GetUsingAnimation())
		{
			render::DrawImageFromAtlas(proj->GetTextureName(), std::to_string(proj->GetCurrentAnimationLine()),
				proj->GetCurrentFrame(), ePos.x - 0.5 * sp.x, ePos.y - 0.5 * sp.y, sp.x, sp.y);
		}
		else
		{
			render::DrawImage(proj->GetTextureName(), ePos.x - 0.5 * sp.x, ePos.y - 0.5 * sp.y, sp.x, sp.y);
		}

	}
	render::DrawImage("player1.png", pos.x - spSize/2.0, pos.y - spSize/2.0, spSize, spSize);
}

void Game::ProcessInput(const Uint8* keyboard)
{
	double speed = mPlayer1.GetSpeed();
	auto prevPos = mPlayer1.GetPosition();
	
	if (keyboard[SDL_SCANCODE_RIGHT] && !keyboard[SDL_SCANCODE_LEFT] && !(prevPos.x >= xWindow)) {
		prevPos.x += speed * 1;
	}
	if (keyboard[SDL_SCANCODE_LEFT] && !keyboard[SDL_SCANCODE_RIGHT] && !(prevPos.x <= 0)) {
		prevPos.x -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_UP] && !keyboard[SDL_SCANCODE_DOWN] && !(prevPos.y <= 0)) {
		prevPos.y -= speed * 1;
	}
	if (keyboard[SDL_SCANCODE_DOWN] && !keyboard[SDL_SCANCODE_UP] && !(prevPos.y >= yWindow)) {
		prevPos.y += speed * 1;
	}
	if (keyboard[SDL_SCANCODE_SPACE]) // косячно работает (нельзя лететь по диагонали и стрелять)
	{
		auto pnt = std::make_shared<ShootingEntity>(mPlayer1);
		if(mPlayer1.IsGunRDY() && mPlayer1.GetActiveWeapon() == 0) {
			auto prj = SpawnProjectile(pnt, BULLET);
			prj->SetDamageValue(mPlayer1.GetBulletDamage());
			mProjectiles.push_back(prj);
			// cool down
			mPlayer1.SetGunTime(SDL_GetTicks()); // Setting time of last shot
			mPlayer1.SetGunRDY(false);
		}
		else if (mPlayer1.IsRocketRDY() && mPlayer1.GetActiveWeapon() == 1) {
			auto rkt = SpawnProjectile(pnt, ROCKET);
			rkt->SetDamageValue(mPlayer1.GetRocketDamage());
			mProjectiles.push_back(rkt);
			// cool down
			mPlayer1.SetRocketTime(SDL_GetTicks()); // Setting time of last shot
			mPlayer1.SetRocketRDY(false);
		}
		else if (mPlayer1.IsLaserRDY() && mPlayer1.GetActiveWeapon() == 2) {
			auto lsr = SpawnProjectile(pnt, LASER);
			lsr->SetDamageValue(mPlayer1.GetLaserDamage());
			mProjectiles.push_back(lsr);
			// cool down
			mPlayer1.SetLaserTime(SDL_GetTicks()); // Setting time of last shot
			mPlayer1.SetLaserRDY(false);
		}
	}
	if (keyboard[SDL_SCANCODE_K] && (SDL_GetTicks() - mTimeOfLastUserInput > 500)) {
		mPlayer1.SetActiveWeapon(mPlayer1.GetActiveWeapon() + 1);
		mTimeOfLastUserInput = SDL_GetTicks();
	}
	//assigning new position
	mPlayer1.SetPosition(prevPos);
}

void Game::Update(Uint32 millis)
{
	if (mEnemies.size() == 0)
	{
 		//SpawnNewEnemyWave();
		auto en = SpawnEnemy(Vector2(xWindow / 2.0, 400), DRONE);
		en->setInitPhase(0);
		mEnemies.push_back(en);
	}
	Uint32 curTime = SDL_GetTicks();

	mPlayer1.CheckCoolDown(curTime);

	for (auto ent : mBackgroundObjects)
	{
		ent->Action();
	}

	for (auto prj : mProjectiles)
	{
		// laser position
		if (prj->GetType() == LASER)
		{
			Vector2 newPos = { mPlayer1.GetPosition().x, (mPlayer1.GetPosition().y - 2*mPlayer1.GetHitboxDimensions().y / 2.0) / 2.0 };
			prj->SetPosition(newPos);
		}
		prj->Action();
	}

	for (auto enm : mEnemies)
	{
		enm->Action();
		if (enm->IsGunRDY())
		{
			enm->SetGunRDY(false);
			enm->SetGunTime(SDL_GetTicks());
			auto ptr = SpawnProjectile(enm, BULLET);
			ptr->SetDamageValue(enm->GetBulletDamage());
			mProjectiles.push_back(ptr);
		}
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
	auto plPos = mPlayer1.GetPosition();
	auto ptr = std::make_shared<Entity>(mPlayer1);
	for (auto prj : mProjectiles)
	{
		// collision with player
		if (!prj->IsShotByPlayer())
		{
			if (!prj->IsCollided() && prj->CheckCollidedHitboxes(ptr))
			{
				prj->collide(0);
				ptr->collide(prj->GetDamageValue());
			}
		}
		else
		{
			auto prjPos = prj->GetPosition();
			for (int i = 0; i < mEnemies.size(); i++)
			{
				auto enemyPos = mEnemies[i]->GetPosition();
				if (!prj->IsCollided() && prj->CheckCollidedHitboxes(mEnemies[i]) ||
					(prj->GetType() == LASER && (SDL_GetTicks() - mEnemies[i]->GetTimeOfLastCollision()) > 50) && prj->CheckCollidedHitboxes(mEnemies[i])) // specially for laser because it can damage multiple times
				{
					prj->collide(0);
					mEnemies[i]->collide(prj->GetDamageValue());
					if (mEnemies[i]->GetHP() <= 0)
					{
						auto it = mEnemies.begin() + i;
						mEnemies.erase(it);
						--i;
					}
					break;
				}
			}
		}
	}

	// reposition clouds after they reach the edge of the screen
	for (auto ent : mBackgroundObjects)
	{
		auto prev_pos = ent->GetPosition();
		auto spSize = ent->GetSpriteDimensions();
		if (prev_pos.y > yWindow + 2 * spSize.y)
		{
			ent->SetPosition(GenRandomNumber(0, xWindow), GenRandomNumber(-2*spSize.y, -spSize.y));
			int cloud = GenRandomNumber(0, 3);
			double factor = ent->GetSpeed() / CLOUDS_MAX_SPEED;
			int width = static_cast<int>(factor * GenRandomNumber(250, 290));
			int height = static_cast<int>(factor*GenRandomNumber(90, 110));
			
			ent->SetSpriteDimensions(Vector2(width, height));
			ent->SetTextureID(cloud);
		}
	}
	
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		auto pos = mProjectiles[i]->GetPosition();
		auto curTime = SDL_GetTicks();

		if (CheckBoundaryExit(pos, mProjectiles[i]->GetHitboxSize()) ||
			(mProjectiles[i]->IsCollided() && (curTime - mProjectiles[i]->GetTimeOfCollision()) > SLUG_EXPOLION_LIFETIME) ||
			mProjectiles[i]->GetIsItTimeToDie())
		{
			auto it = mProjectiles.begin() + i;
			mProjectiles.erase(it);
			--i;
		}
	}

	for (int i = 0; i < mEnemies.size(); i++)
	{
		auto pos = mEnemies[i]->GetPosition();
		if (pos.y - 2 * mEnemies[i]->GetHitboxSize() > yWindow)
		{
			auto it = mEnemies.begin() + i;
			mEnemies.erase(it);
			std::cout << "DIED\n";
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
	if (mPlayer1.GetHP() <= 0)
		return true;

	// пока умираем только так, в принципе, можно добавить режим, где мы защищаем союзника от волн, тогда добавится условие
	// на хп для союзника
	return false;
}


void Game::BakeTextureAtlas(std::string path, std::string shortName, int width, int height, int lines, int framesInLine)
{
	auto atlas = render::Atlas::Create(path, shortName);
	
	for (size_t i = 0; i <= lines; i++)
	{
		atlas.AddAnimationLine(std::to_string(i)).SetFramesCount(framesInLine, false).SetFrameHeight(width).SetFrameWidth(height);
	}
	render::BakeAtlas(atlas);
}

void Game::SpawnNewEnemyWave()
{
	auto logic = EnemyWaveLogic(); // number of enemies in wave and the type of enemy
	for (size_t i = 0; i < logic.first; i++)
	{
		auto en = SpawnEnemy(Vector2(xWindow / 2.0, -100 * (1 + i)), logic.second);
		en->setInitPhase(2 * M_PI * i / logic.first);
		mEnemies.push_back(en);
	}
	return;
}

std::pair<int, EnemyType> Game::EnemyWaveLogic()
{
	std::pair<int, EnemyType> waveParams;
	if (nLightDroneWaves < 5)
	{
		waveParams.second = DRONE;
		waveParams.first = 2 + nLightDroneWaves*(nLightDroneWaves - 1); // 
		nLightDroneWaves += 1;
	}
	else if (nHeavyDroneWaves == 0 && nLightDroneWaves > 5)
	{
		waveParams.second = HEAVYDRONE;
		waveParams.first = 1; // 
		nHeavyDroneWaves += 1;
	}
	else if (nHeavyDroneWaves < 5 && nLightDroneWaves < 10)
	{
		int type = GenRandomNumber(0, 1);
		switch (type)
		{
		case 0:
			waveParams.second = DRONE;
			waveParams.first = 1; // 
			nLightDroneWaves += 1;
			break;
		case 1:
			waveParams.second = HEAVYDRONE;
			waveParams.first = 1; // 
			nHeavyDroneWaves += 1;
			break;
		default:
			waveParams.second = DRONE;
			waveParams.first = 1; // 
			nLightDroneWaves += 1;
			break;
		}
	}
	else
	{
		waveParams.second = DRONE;
		waveParams.first = 1; // 
		nLightDroneWaves += 1;
	}
	return waveParams;
}

bool Game::CheckBoundaryExit(Vector2& pos, double hitbox)
{
	if (pos.x - 2*hitbox >= xWindow ||
		pos.x + 2*hitbox <= 0       ||
		pos.y - 3*hitbox >= yWindow ||
		pos.y + 2*hitbox <= 0)
	{
		return true;
	}
	else
		return false;
}












//////////////////////////////////
//         EntityFactory        //
//////////////////////////////////
std::shared_ptr<Projectile> Game::SpawnProjectile(std::shared_ptr<ShootingEntity> host, EntityType prjType)
{
	bool owner = (host->GetType() == PLAYER) ? true : false; // is player shot it -> true
	switch (prjType)
	{
	case BULLET:
	{
		auto projectile = std::make_shared<Projectile>(Vector2(host->GetPosition().x, host->GetPosition().y - 2), 10, owner);
		projectile->SetTextureName("slug.png");
		projectile->SetUsingAnimation(false);
		projectile->SetOnCollision(
			[projectile](double dmg)
			{
				std::cout << "SLUG has COLLIDED\n";
				projectile->SetTextureName("explosion0");
				projectile->SetUsingAnimation(true);
				projectile->SetSpriteDimensions({ 60, 60 });
				double frameTime = SLUG_EXPOLION_LIFETIME / 72.0;
				projectile->SetFrameTime(frameTime);
			}
		);
		return projectile;
	}
	case ROCKET:
	{
		auto sp = host->GetHitboxDimensions();
		int side = (host->GetSideFromWhichToShoot()) ? 1 : -1;
		auto rkt = std::make_shared<Rocket>(Vector2(host->GetPosition().x + owner*side*sp.x/1.20, host->GetPosition().y + 16), 10, owner);
		
		rkt->SetTextureName("missile0");
		rkt->SetUsingAnimation(true);
		rkt->SetOnCollision(
			[rkt](double dmg)
			{
				rkt->SetTextureName("explosion0");
				rkt->SetUsingAnimation(true);
				rkt->SetSpriteDimensions({ 150, 150 });
			}
		);
		return rkt;
	}
	case LASER:
	{
		Vector2 newPos = { mPlayer1.GetPosition().x, mPlayer1.GetPosition().y - 15 };
		auto lsr = std::make_shared<Laser>(newPos, owner);
		lsr->SetTextureName("laserInit");
		lsr->SetUsingAnimation(true);
		lsr->SetOnCollision(
			[lsr](double dmg)
			{
				std::cout << "LASER has COLLIDED\n";
				//lsr->SetTextureName("explosion0");
				//lsr->SetUsingAnimation(true);
				//lsr->SetSpriteDimensions({ 60, 60 });
			}
		);
		return lsr;
	}
	}
	

}

std::shared_ptr<Entity> Game::SpawnBackgroundObject(Vector2& position, double speed)
{
	int cloud = GenRandomNumber(0, 3);
	int width = GenRandomNumber(250, 290);
	int height = GenRandomNumber(90, 110);

	auto bcEnt = std::make_shared<Entity>(position, EntityType::BACKGROUND, speed);
	bcEnt->SetSpriteDimensions(Vector2(width, height));
	bcEnt->SetTextureID(cloud);
	return bcEnt;
}

std::shared_ptr<EnemyEntity> Game::SpawnEnemy(Vector2& position, EnemyType type)
{
	auto enemy = std::make_shared<EnemyEntity>(position, type);

	enemy->SetOnCollision(
		[enemy](double dmg)
		{
			std::cout << dmg << " damage recieved\t HP = " << enemy->GetHP() << std::endl;
			enemy->RecieveDamage(dmg);
		}
	);
	return enemy;
}