#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "EntityFactory.h"
#include "../src/baseapp.h"
#include <vector>
#include <memory>

class Game: public EntityFactory, public app::GameApp //(�������� ������, � ������ ���������)
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
	void spawnNewEnemyWave(); // ��������� ����� �����, ���� ����� ���������

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

	int genRandomNumber(int a, int b);
};