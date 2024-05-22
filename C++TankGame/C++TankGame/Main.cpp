#include <iostream>
#include "raylib-cpp.hpp"

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "Raylib Template");

    SetTargetFPS(60);


    while (!window.ShouldClose()) {

        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
        }
        EndDrawing();
    }
    return 0;

}
