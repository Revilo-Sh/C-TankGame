#pragma once
#include "SpriteObject.h"
class TankBullet : public SpriteObject
{
public:
	float timer = 0.0f;
	float maxtimer = 10.0f;

protected:
	const float Speed = 750.0f;
	void OnUpdate(float deltaTime) override;
};

