#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Projectile.h"
#include "atlas.h"
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

	void Update(Uint32 millis) override; // ��� ��������� ��������� ��������, ��� ��������, ���� ����� �������
	
	void CheckCollisions(); // ��������� ������������, �������� ��, ��������� ������
	
	bool CheckGameOver(); // ����� �� �����
	

private:
	void BakeTextureAtlas(std::string path, std::string shortName, int width, int height, int lines, int framesInLine);
	void SpawnNewEnemyWave(); // ��������� ����� �����, ���� ����� ���������

	Player mPlayer1; // �����
	std::vector<std::shared_ptr<Entity>> mBackgroundObjects; // ������ ������� �� �����, ������� ��������� ����� (��������� �� ������ ��� ������ �� �����
											 // ������ ��������� �� ��������� �� �, ����� ���������� � ������ ������
											 // ����� ������ �������� �� ������, ����� �������� ������ ���������� (������ ������ �������)
	std::vector< std::shared_ptr<Projectile>> mProjectiles; // ��� �������, ������� ������ ���� ���� � �������� ��� ������ �� ����� / ��������� � ������

	//����� �������� ������ �������, � �� ����� ������ ����� �����, ���� ������ �� ��������
	std::vector<std::shared_ptr<EnemyEntity>> mEnemies; // �����, ��������� \ �������, ����� �����
	//std::vector<BonusEntity*> mBonuses; // �����-������ ������, ������� �������� ������ � �� ����� ������� (������� ��������, ����� �����-������)


	int xWindow;
	int yWindow; // ������� �������� ���� (���� ���������), �� ������� ������ �������� (��������� � ��������� �����)
				 // ����� ������� ��� ������ �� yWindow + ����� �������� (����� �� ���� �����, ��� ��� ���������)

	std::pair<int,EnemyType> EnemyWaveLogic(); // decides what enemy wave should be next
	int nEnemies = 0;
	int nLightDroneWaves = 0;
	int nHeavyDroneWaves = 0;
	Uint32 mTimeOfLastEnemyWave = 0;

	bool CheckBoundaryExit(Vector2& pos, double hitbox);

	std::shared_ptr<Projectile> SpawnProjectile(std::shared_ptr<ShootingEntity> host, EntityType prjType);
	std::shared_ptr<Entity> SpawnBackgroundObject(Vector2& position, double speed);
	std::shared_ptr<EnemyEntity> SpawnEnemy(Vector2& position, EnemyType type);

	Uint32 mTimeOfLastUserInput = 0;
};