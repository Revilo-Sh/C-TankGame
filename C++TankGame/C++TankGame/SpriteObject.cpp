#include "SpriteObject.h"


SpriteObject::SpriteObject()
{
	sprite = nullptr;
	Origin = MathClasses::Vector3(0.5f, 0.5f, 0.5f);
	Tint = Color(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
}
