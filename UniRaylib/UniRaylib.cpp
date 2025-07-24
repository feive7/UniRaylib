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
#include "maps/testmap.h"
#define MAP testmap
void DrawPortalNormals(Portal* portal) {
    for (int i = 0; i < 2; i++) {
        Vector3 origin = Vector3Add(portal->sectors[i].getMidpoint(), { 0.0f,portal->height / 2.0f,0.0f });
        Vector2 normal = portal->sectors[i].getNormal();
        DrawLine3D(origin, origin + Vector3{normal.x, 0.0f, normal.y}, RED);
    }
}
void DrawPlayer(Player* player) {
    Vector3 headpos = Vector3Add(player->position, { 0.0f,player->height,0.0f });
    Vector3 aboveFloor = Vector3Add(player->position, { 0.0f,0.01f,0.0f });
    Vector3 facing = player->facing(); facing.y = 0.0f; facing = Vector3Normalize(facing);
    DrawCapsule(player->position, headpos, player->radius, 10, 10, RED);
    DrawLine3D(aboveFloor, Vector3Add(aboveFloor, Vector3Scale(facing, 2.0f*player->radius)), BLUE);
}
void ResetCamera(Camera* camera) {
    camera->position = MAP.playerstart.camera_position;  // Camera position
    camera->target = MAP.playerstart.camera_target;     // Camera looking at point
    camera->up = { 0.0f, 1.0f, 0.0f };         // Camera up vector (rotation towards target)
    camera->fovy = 45.0f;                      // Camera field-of-view Y
    camera->projection = CAMERA_PERSPECTIVE;   // Camera mode type
}
void ResetPlayer(Player* player) {
    player->position = MAP.playerstart.player_position;
    player->target = MAP.playerstart.player_target;
    player->height = 3.0f;
    player->radius = 1.0f;
}
int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    InitTextures();
    InitShaders();
    MAP.init();

    Camera freecam = { 0 };
    ResetCamera(&freecam);

    Player player = { 0 };
    ResetPlayer(&player);

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Keyboard input handling
        if (IsKeyDown(KEY_R)) {
            ResetPlayer(&player);
            ResetCamera(&freecam);
        }

        // Game logic
        UpdateCameraScene(&freecam,&MAP);
        player.update(&MAP);
        if (IsKeyPressed(KEY_V)) player.noClipping = !player.noClipping;
        if (!IsKeyDown(KEY_TAB)) player.attachCamera(&freecam);
        MAP.renderPortals(&freecam);
        float time = GetTime();
        testmap.lights[0].position = { sin(time)*4,3.0f,cos(time)*4 };
        for (int i = 0; i < 1; i++) {
            UpdateLight(testmap.lights[i]);
        }

        BeginDrawing();
            ClearBackground(BLACK); // Clear the background
            BeginMode3D(freecam);
                MAP.draw();
                MAP.draw_portals();
                DrawPlayer(&player);
            EndMode3D();
            Vector3 t = player.facing();
            /*DrawText(TextFormat("Camera Position: %.2f %.2f %.2f", freecam.position.x, freecam.position.y, freecam.position.z), 0, 10, 20, WHITE);
            DrawText(TextFormat("Camera Target: %.2f %.2f %.2f", freecam.target.x, freecam.target.y, freecam.target.z), 0, 30, 20, WHITE);
            DrawText(TextFormat("Player Position: %.2f %.2f %.2f", player.position.x, player.position.y, player.position.z), 0, 50, 20, WHITE);
            DrawText(TextFormat("Player Facing: %.2f %.2f %.2f", t.x, t.y, t.z), 0, 70, 20, WHITE);*/
        EndDrawing();
    }
    UnloadTextures();
    UnloadShaders();
    CloseWindow();
    return 0;
}