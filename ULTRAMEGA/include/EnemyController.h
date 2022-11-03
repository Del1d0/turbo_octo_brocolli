#pragma once
#include "BaseController.h"

class EnemyController : public BaseController
{
public:
	EnemyController() {};
	~EnemyController() {};
	void getControls() override;
	// логику отслеживания игрока запихать сюда?
private:
	Vector2 movingAlgorithm(Vector2& prevLocation); // пред. координаты берутся из hostEntity и в него же записываются новые
	// способ движения должен выбираться на основе типа Entity
	// может быть сделать отдельный файл с функциями для движения типа Utils и вызывать нужную
};