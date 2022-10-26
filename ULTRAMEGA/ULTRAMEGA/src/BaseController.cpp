#include "../include/BaseController.h"

void BaseController::setCoordinates(Entity& hostEntity)
{
	Vector2 vel1;
	switch (mAction)
	{
	case MOVE_UP:
		vel1 = Vector2(0, 1);
		break;
	case MOVE_DOWN:
		vel1 = Vector2(0, -1);
		break;
	case MOVE_RIGHT:
		vel1 = Vector2(1, 0);
		break;
	case MOVE_LEFT:
		vel1 = Vector2(-1, 0);
		break;
	default:
		return;
	}
	
	Vector2 newCoord = hostEntity.getPosition() + vel1 * REFRESH_RATE;
	
	hostEntity.setPosition(newCoord);
	
	return;
}

