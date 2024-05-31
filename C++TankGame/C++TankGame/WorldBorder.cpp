#include "WorldBorder.h"

void WorldBorder::Load()
{
	BoxCollider = new AABB(MathClasses::Vector3(-800, -800, 0) + GetWorldPosition(), MathClasses::Vector3(400, 400, 0) + GetWorldPosition());
}
