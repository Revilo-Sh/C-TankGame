#include "Box.h"

void Box::Load()
{
	BoxCollider = new AABB(MathClasses::Vector3(-27, -27, 0) + GetWorldPosition(), MathClasses::Vector3(27, 27, 0) + GetWorldPosition());
}
