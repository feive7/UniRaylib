#include <iostream>
#include <string>
#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"
#include "rlgl.h"
#include "Textures.h"
#include "Shaders.h"
#include "Lighting.h"
#include "MapElements.h"
#include "Player.h"
#include "testmap.h"
#define MAP testmap
void DrawPortalNormals(Portal* portal) {
    for (int i = 0; i < 2; i++) {
        Vector3 origin = Vector3Add(portal->sectors[i].getMidpoint(), { 0.0f,portal->height / 2.0f,0.0f });
        Vector2 normal = portal->sectors[i].getNormal();
        DrawLine3D(origin, origin + Vector3{normal.x, 0.0f, normal.y}, RED);
    }
}
void ResetCamera(Camera* camera) {
    camera->position = MAP.playerstart.position;  // Camera position
    camera->target = MAP.playerstart.target;     // Camera looking at point
    camera->up = { 0.0f, 1.0f, 0.0f };         // Camera up vector (rotation towards target)
    camera->fovy = 45.0f;                      // Camera field-of-view Y
    camera->projection = CAMERA_PERSPECTIVE;   // Camera mode type
}
int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    InitTextures();
    InitShaders();
    InitTestMap();
    MAP.portals[0].InitPortals();

    Light playerlight = CreateLight({ 0.0f,0.0f,0.0f }, 2.0f);
    LightPortal lightPortal = CreateLightPortal({ 0.0f,0.0f,0.0f }, { 0.0f,0.0f,24.0f });

    Camera freecam = { 0 };
    ResetCamera(&freecam);

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Keyboard input handling
        if (IsKeyDown(KEY_R)) {
            ResetCamera(&freecam);
        }

        // Game logic
        UpdateCameraScene(&freecam,&MAP);
        MAP.renderPortals(&freecam);
        playerlight.position = freecam.position;
        UpdateLight(playerlight);

        BeginDrawing();
            ClearBackground(BLACK); // Clear the background
            BeginMode3D(freecam);
                MAP.draw();
                MAP.draw_portals();
                //DrawPortalNormals(&MAP.portals[0]);
            EndMode3D();
            if (IsKeyDown(KEY_TAB)) {
                Texture* texture = &MAP.portals[0].RTextures[1].texture;
                DrawTextureRec(*texture, { 0,0,(float)texture->width,(float)-texture->height }, { 0,0 }, WHITE);
            }
        EndDrawing();
    }
    UnloadTextures();
    UnloadShaders();
    CloseWindow();
    return 0;
}