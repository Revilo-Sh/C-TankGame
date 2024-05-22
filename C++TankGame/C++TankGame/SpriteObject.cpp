#include "SpriteObject.h"
#include "Utils.h"

SpriteObject::SpriteObject()
{
	sprite = nullptr;
	Origin = MathClasses::Vector3(0.5f, 0.5f, 0.5f);
	Tint = MathClasses::Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	MathClasses::Vector3 pos = GetWorldPosition();
	float rot = GetWorldRotation();
	MathClasses::Vector3 scl = Getworldscale();
	sprite->Draw(
		raylib::Rectangle(0, 0, (float)sprite->width, (float)sprite->height),
		raylib::Rectangle(pos.x, pos.y, sprite->width * scl.x, sprite->height * scl.y),
		raylib::Vector2(sprite->width * Origin.x * scl.x, sprite->height * Origin.y * scl.y),
		rot,
		raylib::Color(Tint.colour));

}

