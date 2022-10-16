#pragma once
#include "BaseController.h"

class EntityController : public BaseController
{
public:
	void getControls() override;
	// логику отслеживания игрока запихать сюда?
private:
	Coords movingAlgorithm(Coords& prevLocation); // пред. координаты берутся из hostEntity и в него же записываются новые
	// способ движения должен выбираться на основе типа Entity
	// может быть сделать отдельный файл с функциями для движения типа Utils и вызывать нужную
};