#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Renderer.h"
#include "EntityFactory.h"
#include "../src/baseapp.h"
#include <vector>
#include <memory>

class Game: public EntityFactory, public app::GameApp //(содержит игрока, и вектор сущностей)
{
public:
	Game() = delete;
	Game(int winX, int winY, double plSpeed);
	Game(int winX, int winY);

	void Initialize() override;

	void Render() override;
	
	void ProcessInput(const Uint8* keyboard) override;

	void initGame(); // расставляем игрока, начальные облака и прочее
	
	void update(); // тут обновляем положения объектов, все стреляют, если время подошло
	
	void checkCollisions(); // проверяем столкновения, отнимаем ХП, подбираем бонусы
	
	bool checkGameOver(); // помер ли игрок
	
	void render(); // какая-то отрисовка
	

private:
	void spawnNewEnemyWave(); // запускаем новую волну, если враги кончились

	void spawnEntity();

	Player mPlayer1; // игрок
	std::vector<std::shared_ptr<Entity>> mBackgroundObjects; // всякие объекты на карте, которые пролетают фоном (зациклить их просто при вылете за карту
											 // менять положение на рандомное по х, чтобы появлялись с разных сторон
											 // можно менять скорость на разную, чтобы возникал эффект параллакса (разная высота облаков)
	std::vector< std::shared_ptr<Entity>> mProjectiles; // это снаряды, которые летают туда сюда и помирают при вылете за карту / попадании в игрока

	//будем подавать врагов волнами, и не будем делать новую волну, пока старая не погибнет
	std::vector<std::shared_ptr<EnemyEntity>> mEnemies; // враги, добавляем \ убираем, когда нужно
	//std::vector<BonusEntity*> mBonuses; // какие-нибудь бонусы, которые медленно плывут и их можно поднять (быстрая стрельба, лазер какой-нибудь)


	int xWindow;
	int yWindow; // размеры игрового поля (поле отрисовки), за которое нельзя вылетать (упираемся в невидимые стены)
				 // враги умирают при вылете за yWindow + длина хитбокса (чтобы не было видно, как они удаляются)

	int nEnemies = 0;
	
};