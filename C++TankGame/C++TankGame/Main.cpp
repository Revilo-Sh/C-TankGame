#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h" 
#include "TankTurret.h"
#include "TankBullet.h"


int main()
{
    ///////////////////////////////
    // Basic Setup
    ///////////////////////////////

    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "Raylib Template");

    SetTargetFPS(60);

    ///////////////////////////////
    // Setting Up the Player Tank
    ///////////////////////////////

    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");

 



    TankPlayer Player;
    Player.sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    
    ///////////////////////////////
    // Settng Up The Tank Turret
    ///////////////////////////////

    raylib::Texture2D tankTurretSprite("res/tankBlue_barrel2_outline.png");

    TankTurret Playerturret;
    Playerturret.sprite = &tankTurretSprite;
    Playerturret.SetLocalPosition(0,0);
    Playerturret.Setparent(&Player);
    Playerturret.Origin = MathClasses::Vector3(0, 0.5, 0);

    ///////////////////////////////
    // Settng Up The Tank Bullet
    ///////////////////////////////



    ///////////////////////////////
    // Settng Up Timing Data
    ///////////////////////////////

    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        Playerturret.update(deltaTime);
        Player.update(deltaTime);
        

        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            Player.Draw();
            Playerturret.Draw();
        }
        EndDrawing();
    }
    return 0;
}
