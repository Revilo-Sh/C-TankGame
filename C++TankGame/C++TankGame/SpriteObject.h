#pragma once
#include "raylib-cpp.hpp"

#include "Colour.h"
#include "GameObject.h"


class SpriteObject : public GameObject
{
public:
	raylib::Texture2D* sprite;
	MathClasses::Vector3 Origin;
	MathClasses::Colour Tint;
	

	SpriteObject();

protected:
	void OnDraw() override;
};

