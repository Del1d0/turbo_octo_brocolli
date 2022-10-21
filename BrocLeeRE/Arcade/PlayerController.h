#pragma once
#include "BaseController.h"
#include "Player.h"

class PlayerController : public BaseController
{
public:
	void getControls() override; // вызовет getPlayerInput -> вычислит новое положение -> запишет новую координату в Host
private:
	void getPlayerInput(); // собирает общий ввод игрока - переводим кнопки в Action
	//Action - enum в котором содержатся действия типа стрельба, движение туда-то, смена оружия
};