#include "TankTurret.h"
#include <iostream>

void TankTurret::OnUpdate(float deltaTime)
{
	const float RotateSpeed = 5.0f;
	float xMove = 0.0f;

	float FinelRoate;

	if (IsKeyDown(KeyboardKey::KEY_SPACE)) {
		std::cout << "Shoot" << std::endl;

		for (int i = 0; i < 100; i++) {
			if (bullet[i] == nullptr) {
				bullet[i] = new TankBullet;
				bullet[i]->sprite = new raylib::Texture2D("res/bulletDark1_outline.png");
				bullet[i]->SetLocalRotation(GetWorldRotation());
				bullet[i]->SetLocalPosition(GetWorldPosition() + (GetForwards() * 72));
				std::cout << "Spawn" << std::endl;
				break;
			}
		}
	}

	if (IsKeyDown(KeyboardKey::KEY_E)) {
		std::cout << "INPUT [E] Turret Move Right ->" << std::endl;
		xMove += RotateSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_Q)) {
		std::cout << "INPUT [Q] Turret Move Left <-" << std::endl;
		xMove -= RotateSpeed;
	}

	FinelRoate = (xMove * deltaTime);
	Rotate(FinelRoate);



	for (int i = 0; i < 100; i++) {
		if (bullet[i] != nullptr) {
			// despawn timer if statement here
			if (bullet[i]->timer >= bullet[i]->maxtimer) {
				delete bullet[i]->sprite;
				bullet[i]->sprite = nullptr;

				delete bullet[i];
				bullet[i] = nullptr;
			}


			else if (bullet[i]->GetWorldPosition().x <= -10 || bullet[i]->GetWorldPosition().y <= -10 || bullet[i]->GetWorldPosition().x >= GetScreenWidth() + 10 || bullet[i]->GetWorldPosition().y >= GetScreenHeight() + 10) {
				delete bullet[i]->sprite;
				bullet[i]->sprite = nullptr;

				delete bullet[i];
				bullet[i] = nullptr;
			}
				

		
			else {
				bullet[i]->update(deltaTime);
			}
		}
	}
}

void TankTurret::OnDraw()
{
	float rot = GetWorldRotation() * (180.0f / 3.14159265358979323846f);
	MathClasses::Vector3 pos = GetWorldPosition();
	MathClasses::Vector3 scl = Getworldscale();


	sprite->Draw(
		raylib::Rectangle(0, 0, (float)sprite->width, (float)sprite->height),
		raylib::Rectangle(pos.x, pos.y, sprite->width * scl.x, sprite->height * scl.y),
		raylib::Vector2(sprite->width * Origin.x * scl.x, sprite->height * Origin.y * scl.y),
		rot,
		raylib::Color(Tint.colour));
	
	for (int i = 0; i < 100; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
}
