#include <iostream>
#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h" 
#include "TankTurret.h"
#include "TankBullet.h"
#include "Box.h"
#include "WorldBorder.h"



int main()
{
    // Setting Up All the Roots
    GameObject root;
    GameObject::SetRoot(&root);
    
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
    Player.Setparent(&root);


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
    // World Render
    ///////////////////////////////

    raylib::Texture2D BoxSprite("res/crateWood.png");
    Box WorldBox;
    WorldBox.sprite = &BoxSprite;
   
    WorldBox.SetLocalPosition(150,150);
    WorldBox.Setparent(&root);
    WorldBox.Load();

    raylib::Rectangle GrayCollider(WorldBox.GetLocalPosition().x-WorldBox.Origin.x -29,WorldBox.GetLocalPosition().y - WorldBox.Origin.y -29, 60, 60);
  
    
    // World Render Setting Up The World Border
    
    WorldBorder worldborder;
    worldborder.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    worldborder.Setparent(&root);
    worldborder.Load();




    ///////////////////////////////
    // Settng Up Timing Data
    ///////////////////////////////

    while (!window.ShouldClose()) {
        float deltaTime = window.GetFrameTime();
        Playerturret.update(deltaTime);
        Player.update(deltaTime);

        /////////////////////////////////////////////
        // Checking To See If the Bullet Htis The box And to See if bullet go off screen
        /////////////////////////////////////////////
        for (int i = 0; i < 100; i++) {
            if (Playerturret.bullet[i] != nullptr) {
                AABB* col = root.GetColliderofchiled(Playerturret.bullet[i]->BoxCollider);

                if (col != worldborder.BoxCollider) {
                    if (col != nullptr && col != Playerturret.bullet[i]->BoxCollider || col != Player.BoxCollider || col != Playerturret.BoxCollider || col != worldborder.BoxCollider) {
                        delete Playerturret.bullet[i]->sprite;
                        Playerturret.bullet[i]->sprite = nullptr;
                        delete Playerturret.bullet[i];
                        Playerturret.bullet[i] = nullptr;
                        std :: cout << "[BULLET] DERENDER" << std::endl;
                    }
                }
            }
        }


        //////////////////////////////////////
        // Updating Each Darw For the Textures
        //////////////////////////////////////

        BeginDrawing();
        {
            window.ClearBackground(DARKGREEN);
            Player.Draw();
            Playerturret.Draw();
            WorldBox.Draw();
            //GrayCollider.Draw(GRAY);
        }
        EndDrawing();
    }
    return 0;
}
