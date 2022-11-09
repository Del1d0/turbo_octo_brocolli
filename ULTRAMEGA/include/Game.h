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

	void Update(Uint32 millis) override; // ��� ��������� ��������� ��������, ��� ��������, ���� ����� �������
	
	void CheckCollisions(); // ��������� ������������, �������� ��, ��������� ������
	
	bool CheckGameOver(); // ����� �� �����
	

private:
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

	int nEnemies = 0;

	bool CheckBoundaryExit(Vector2& pos, double hitbox);

	std::shared_ptr<Projectile> SpawnProjectile(std::shared_ptr<Entity> host);
	std::shared_ptr<Entity> SpawnBackgroundObject(Vector2& position, double speed);
	std::shared_ptr<EnemyEntity> SpawnEnemy(Vector2& position, EnemyType type);
};