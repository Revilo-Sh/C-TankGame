#include "TankBullet.h"
#include <iostream>
void TankBullet::OnUpdate(float deltaTime)
{
	timer += deltaTime;
	float yMove = 0.0f;
	yMove += Speed;

	MathClasses::Vector3 Movebullet = GetForwards() * (yMove * deltaTime);
	Translate(Movebullet);
}
