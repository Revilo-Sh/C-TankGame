#include "WorldBorder.h"

void WorldBorder::Load()
{
	BoxCollider = new AABB(MathClasses::Vector3(0, 0, 1), MathClasses::Vector3(800, 450, 1));
}
