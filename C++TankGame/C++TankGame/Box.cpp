#include "Box.h"

void Box::Load()
{
	BoxCollider = new AABB(MathClasses::Vector3(-8, -8, 0) + GetWorldPosition(), MathClasses::Vector3(8, 8, 0) + GetWorldPosition());
	// Setting The Size of the Box
	//BoxCollider->min = MathClasses::Vector3(-8, -8, 0) + GetWorldPosition();
	//BoxCollider->max = MathClasses::Vector3(8, 8, 0) + GetWorldPosition();
}
