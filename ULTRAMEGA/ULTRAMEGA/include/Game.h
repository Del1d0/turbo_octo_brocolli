#pragma once
#include "Player.h"
#include "EnemyEntity.h"
#include "Renderer.h"
#include "EntityFactory.h"
#include <vector>

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
	bool spawnNewEnemyWave(); // ��������� ����� �����, ���� ����� ���������

	Player mPlayer1; // �����
	std::vector<Entity*> mBackgroundObjects; // ������ ������� �� �����, ������� ��������� ����� (��������� �� ������ ��� ������ �� �����
											 // ������ ��������� �� ��������� �� �, ����� ���������� � ������ ������
											 // ����� ������ �������� �� ������, ����� �������� ������ ���������� (������ ������ �������)
	std::vector<Entity*> mProjectiles; // ��� �������, ������� ������ ���� ���� � �������� ��� ������ �� ����� / ��������� � ������

	//����� �������� ������ �������, � �� ����� ������ ����� �����, ���� ������ �� ��������
	std::vector<EnemyEntity*> mEnemies; // �����, ��������� \ �������, ����� �����
	//std::vector<BonusEntity*> mBonuses; // �����-������ ������, ������� �������� ������ � �� ����� ������� (������� ��������, ����� �����-������)


	int xWindow;
	int yWindow; // ������� �������� ���� (���� ���������), �� ������� ������ �������� (��������� � ��������� �����)
				 // ����� ������� ��� ������ �� yWindow + ����� �������� (����� �� ���� �����, ��� ��� ���������)

	int nEnemies = 0;
	
};