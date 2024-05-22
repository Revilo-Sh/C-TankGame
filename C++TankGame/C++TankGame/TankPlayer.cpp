#include <iostream>
#include "TankPlayer.h"



void TankPlayer::OnUpdate(float deltaTime)
{
	const float Movespeed = 150.0f;
	const float RotateSpeed = 3.0f;
	// Checking For Player Inputs
	float yMove = 0.0f;
	float xMove = 0.0f;
	
	float finalrotate;

	//Checking For W,S inputs
	if (IsKeyDown(KeyboardKey::KEY_W)) {
		yMove += Movespeed;
		std::cout << "Up" << std :: endl;
	}
	if (IsKeyDown(KeyboardKey::KEY_S)) {
		yMove -= Movespeed;
		std::cout << "Down" << std::endl;
	}
	if (IsKeyDown(KeyboardKey::KEY_A)) {
		xMove -= RotateSpeed;
		std::cout << "Turn L" << std::endl;
	}
	if (IsKeyDown(KeyboardKey::KEY_D)) {
		xMove += RotateSpeed;
		std::cout << "Turn R" << std::endl;
	}

	MathClasses::Vector3 finalMove = GetForwards() * (yMove * deltaTime);
	Translate(finalMove);

	finalrotate = (xMove * deltaTime);
	Rotate(finalrotate);
}
