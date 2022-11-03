#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Renderer.h"
#include "EntityFactory.h"
#include <vector>
#include <memory>

class Game: public EntityFactory //(�������� ������, � ������ ���������)
{
public:
	Game() = delete;
	Game(int winX, int winY, double plSpeed);
	Game(int winX, int winY);

	void initGame(); // ����������� ������, ��������� ������ � ������
	
	void update(); // ��� ��������� ��������� ��������, ��� ��������, ���� ����� �������
	
	void checkCollisions(); // ��������� ������������, �������� ��, ��������� ������
	
	bool checkGameOver(); // ����� �� �����
	
	void render(); // �����-�� ���������
	

private:
	void spawnNewEnemyWave(); // ��������� ����� �����, ���� ����� ���������

	void spawnEntity();

	Player mPlayer1; // �����
	std::vector<std::shared_ptr<Entity>> mBackgroundObjects; // ������ ������� �� �����, ������� ��������� ����� (��������� �� ������ ��� ������ �� �����
											 // ������ ��������� �� ��������� �� �, ����� ���������� � ������ ������
											 // ����� ������ �������� �� ������, ����� �������� ������ ���������� (������ ������ �������)
	std::vector< std::shared_ptr<Entity>> mProjectiles; // ��� �������, ������� ������ ���� ���� � �������� ��� ������ �� ����� / ��������� � ������

	//����� �������� ������ �������, � �� ����� ������ ����� �����, ���� ������ �� ��������
	std::vector<std::shared_ptr<EnemyEntity>> mEnemies; // �����, ��������� \ �������, ����� �����
	//std::vector<BonusEntity*> mBonuses; // �����-������ ������, ������� �������� ������ � �� ����� ������� (������� ��������, ����� �����-������)


	int xWindow;
	int yWindow; // ������� �������� ���� (���� ���������), �� ������� ������ �������� (��������� � ��������� �����)
				 // ����� ������� ��� ������ �� yWindow + ����� �������� (����� �� ���� �����, ��� ��� ���������)

	int nEnemies = 0;
	
};