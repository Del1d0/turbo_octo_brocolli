#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Renderer.h"
#include "EntityFactory.h"
#include <vector>

class Game: public EntityFactory //(содержит игрока, и вектор сущностей)
{
public:
	Game() = delete;
	Game(int winX, int winY, double plSpeed);
	Game(int winX, int winY);

	void initGame(); // расставляем игрока, начальные облака и прочее
	
	void update(); // тут обновляем положения объектов, все стреляют, если время подошло
	
	void checkCollisions(); // проверяем столкновения, отнимаем ХП, подбираем бонусы
	
	bool checkGameOver(); // помер ли игрок
	
	void render(); // какая-то отрисовка
	

private:
	bool spawnNewEnemyWave(); // запускаем новую волну, если враги кончились

	Player mPlayer1; // игрок
	std::vector<Entity*> mBackgroundObjects; // всякие объекты на карте, которые пролетают фоном (зациклить их просто при вылете за карту
											 // менять положение на рандомное по х, чтобы появлялись с разных сторон
											 // можно менять скорость на разную, чтобы возникал эффект параллакса (разная высота облаков)
	std::vector<Entity*> mProjectiles; // это снаряды, которые летают туда сюда и помирают при вылете за карту / попадании в игрока

	//будем подавать врагов волнами, и не будем делать новую волну, пока старая не погибнет
	std::vector<EnemyEntity*> mEnemies; // враги, добавляем \ убираем, когда нужно
	//std::vector<BonusEntity*> mBonuses; // какие-нибудь бонусы, которые медленно плывут и их можно поднять (быстрая стрельба, лазер какой-нибудь)


	int xWindow;
	int yWindow; // размеры игрового поля (поле отрисовки), за которое нельзя вылетать (упираемся в невидимые стены)
				 // враги умирают при вылете за yWindow + длина хитбокса (чтобы не было видно, как они удаляются)

	int nEnemies = 0;
	
};