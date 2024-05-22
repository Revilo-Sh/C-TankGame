#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h" 


int main()
{
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "Raylib Template");

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");

    TankPlayer Player;
    Player.sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
 

    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        Player.update(deltaTime);



        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            Player.Draw();
        }
        EndDrawing();
    }
    return 0;

}
