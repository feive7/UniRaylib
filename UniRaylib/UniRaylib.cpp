#include <iostream>
#include <string>
#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"
#include "rlgl.h"
#include "Textures.h"
#include "MapElements.h"
#include "testmap.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Camera freecam = { 0 };
    freecam.position = { 0.0f, 2.0f, 10.0f };  // Camera position
    freecam.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    freecam.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    freecam.fovy = 45.0f;                                // Camera field-of-view Y
    freecam.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    InitTextures();
    InitTestMap();

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Keyboard input handling

        // Game logic
        UpdateCamera(&freecam, CAMERA_FREE);

        BeginDrawing();
            ClearBackground(RAYWHITE); // Clear the background
            BeginMode3D(freecam);
                testmap.draw();
            EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}