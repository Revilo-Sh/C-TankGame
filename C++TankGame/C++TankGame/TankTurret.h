#pragma once
#include "SpriteObject.h"
#include "TankBullet.h"


class TankTurret : public SpriteObject
{
protected:
	TankBullet *bullet[100];

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

};

