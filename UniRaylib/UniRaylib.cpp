#include <iostream>
#include <string>
#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"
#include "rlgl.h"
#include "Textures.h"
#include "Shaders.h"
#include "MapElements.h"
#include "Player.h"
#include "testmap.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Camera freecam = { 0 };
    freecam.position = { 0.0f, 2.0f, 10.0f };  // Camera position
    freecam.target = { 0.0f, 0.0f, 0.0f };     // Camera looking at point
    freecam.up = { 0.0f, 1.0f, 0.0f };         // Camera up vector (rotation towards target)
    freecam.fovy = 45.0f;                      // Camera field-of-view Y
    freecam.projection = CAMERA_PERSPECTIVE;   // Camera mode type

    InitTextures();
    InitShaders();
    InitTestMap();
    testmap.portals[0].InitPortals();

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Keyboard input handling

        // Game logic
        UpdateCameraScene(&freecam,&testmap);
        testmap.renderPortals(&freecam);

        BeginDrawing();
            ClearBackground(RAYWHITE); // Clear the background
            BeginMode3D(freecam);
                testmap.draw();
                testmap.draw_portals();
                //DrawCube(testmap.portals[0].RTCameras[0].position, 1.0f, 1.0f, 1.0f, RED);
            EndMode3D();
            if (IsKeyDown(KEY_TAB)) {
                Texture* texture = &testmap.portals[0].RTextures[0].texture;
                DrawTextureRec(*texture, { 0,0,(float)texture->width,(float)-texture->height }, { 0,0 }, WHITE);
            }
        EndDrawing();
    }
    UnloadTextures();
    UnloadShaders();
    CloseWindow();
    return 0;
}