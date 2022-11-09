#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Projectile.h"
//#include "EntityFactory.h"
#include "../src/baseapp.h"
#include "Constants.h"
#include <vector>
#include <memory>

class Game: public app::GameApp //, public EntityFactory
{
public:
	Game() = delete;
	Game(int winX, int winY, double plSpeed);
	Game(int winX, int winY);

	void Initialize() override;

	void Render() override;
	
	void ProcessInput(const Uint8* keyboard) override;

	void Update(Uint32 millis) override; // тут обновляем положения объектов, все стреляют, если время подошло
	
	void CheckCollisions(); // проверяем столкновения, отнимаем ХП, подбираем бонусы
	
	bool CheckGameOver(); // помер ли игрок
	

private:
	void SpawnNewEnemyWave(); // запускаем новую волну, если враги кончились

	Player mPlayer1; // игрок
	std::vector<std::shared_ptr<Entity>> mBackgroundObjects; // всякие объекты на карте, которые пролетают фоном (зациклить их просто при вылете за карту
											 // менять положение на рандомное по х, чтобы появлялись с разных сторон
											 // можно менять скорость на разную, чтобы возникал эффект параллакса (разная высота облаков)
	std::vector< std::shared_ptr<Projectile>> mProjectiles; // это снаряды, которые летают туда сюда и помирают при вылете за карту / попадании в игрока

	//будем подавать врагов волнами, и не будем делать новую волну, пока старая не погибнет
	std::vector<std::shared_ptr<EnemyEntity>> mEnemies; // враги, добавляем \ убираем, когда нужно
	//std::vector<BonusEntity*> mBonuses; // какие-нибудь бонусы, которые медленно плывут и их можно поднять (быстрая стрельба, лазер какой-нибудь)


	int xWindow;
	int yWindow; // размеры игрового поля (поле отрисовки), за которое нельзя вылетать (упираемся в невидимые стены)
				 // враги умирают при вылете за yWindow + длина хитбокса (чтобы не было видно, как они удаляются)

	int nEnemies = 0;

	bool CheckBoundaryExit(Vector2& pos, double hitbox);

	std::shared_ptr<Projectile> SpawnProjectile(std::shared_ptr<Entity> host);
	std::shared_ptr<Entity> SpawnBackgroundObject(Vector2& position, double speed);
	std::shared_ptr<EnemyEntity> SpawnEnemy(Vector2& position, EnemyType type);
};