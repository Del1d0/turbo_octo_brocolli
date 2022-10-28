#pragma once
#include "Constants.h"
#include "Entity.h"

class PlayerController
{
public:
	PlayerController() = default;
	void getControls(); // вызовет getPlayerInput -> вычислит новое положение -> запишет новую координату в Host
	void updatePosition(Entity& host) { setCoordinates(host); };
private:
	void setCoordinates(Entity& hostEntity);
	void getPlayerInput(); // собирает общий ввод игрока - переводим кнопки в Action
	//Action - enum в котором содержатся действия типа стрельба, движение туда-то, смена оружия
	Action mAction;
};