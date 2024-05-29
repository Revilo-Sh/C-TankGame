#pragma once
#include "SpriteObject.h"
#include "TankBullet.h"


class TankTurret : public SpriteObject
{
public:
	TankBullet* bullet[100];
protected:
	

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	float ShootTime = 1.0f;
};

