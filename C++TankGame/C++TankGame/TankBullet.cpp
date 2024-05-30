#include "TankBullet.h"
#include <iostream>
void TankBullet::OnUpdate(float deltaTime)
{
	timer += deltaTime;
	float yMove = 0.0f;
	yMove += Speed;

	// Getting Speed And + it by GetFwards Each Delta
	MathClasses::Vector3 Movebullet = GetForwards() * (yMove * deltaTime);
	Translate(Movebullet);


	// Setting the Size of the ColliderBox Size
	BoxCollider->min = MathClasses::Vector3(-5, -5, 0) + GetWorldPosition();
	BoxCollider->max = MathClasses::Vector3(5, 5, 0) + GetWorldPosition();
}
