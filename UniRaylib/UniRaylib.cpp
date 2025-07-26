#include <iostream>
#include <string>
#include <functional>
#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"
#include "rlgl.h"
#include "Extrafunctions.h"
#include "Textures.h"
#include "Shaders.h"
#include "Models.h"
#include "Lighting.h"
#include "MapElements.h"
#include "Ball.h"
#include "Player.h"
#include "maps/testmap.h"
#define MAP testmap
bool debug = true;
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
    Vector3 facing = player->getForward(); facing.y = 0.0f; facing = Vector3Normalize(facing);
    DrawCapsule(player->position, headpos, player->radius, 10, 10, RED);
    DrawLine3D(aboveFloor, Vector3Add(aboveFloor, Vector3Scale(facing, 2.0f*player->radius)), BLUE);
    DrawCircle3D(player->position, player->radius, { 1.0f, 0.0f, 0.0f }, 90.0f, GRAY); // Draw player as a circle on the ground
    DrawCircle3D(player->position + Vector3{ 0.0f,player->height,0.0f }, player->radius, { 1.0f, 0.0f, 0.0f }, 90.0f, GRAY);
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
    player->velocity = { 0.0f,0.0f,0.0f };
    player->height = 3.0f;
    player->maxHeight = player->height;
    player->radius = 1.0f;
}
void AddLine(const char* text, bool reset = false) {
    static int y = 0;
    if (reset) {
        y = 0;
    }
    DrawText(text, 5, 20 * y + 5, 20, WHITE);
    y++;
}
int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    InitTextures();
    InitShaders();
    InitModels();
    MAP.init();

    Camera freecam = { 0 };
    ResetCamera(&freecam);

    Player player = { 0 };
    ResetPlayer(&player);

    int ballcount = 0;
    Ball balls[100] = {0};

    TransformableVector3 t({ 0.0f,7.0f,0.0f });
    t.SetTransformFunction([](Vector3& v) {
        float t = GetTime();
        v.x = sin(t) * 3.0f;
        v.y = sin(t * 3.0f) + 7.0f;
        v.z = cos(t) * 3.0f;
        });


    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Keyboard input handling
        if (IsKeyPressed(KEY_R)) {
            ResetPlayer(&player);
            ResetCamera(&freecam);
            memset(&balls, 0, sizeof(balls));
            ballcount = 0;
        }
        if (IsKeyPressed(KEY_F3)) {
            toggle(debug);
        }
        if (IsKeyPressed(KEY_Z)) {
            balls[ballcount] = { 0 };
            ballcount --;
            if (ballcount < 0) ballcount = 0;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            balls[ballcount].active = true;
            balls[ballcount].position = player.headPos();
            balls[ballcount].color = RandomColor();
            printC(balls[ballcount].color);
            balls[ballcount].velocity = Vector3Scale(player.getForward(),RandomFloat(0.2f,0.4f));
            balls[ballcount].radius = RandomFloat(0.2f,1.0f);
            ballcount = (ballcount + 1) % 100;
        }

        // Game logic
        UpdateCameraScene(&freecam,&MAP);
        player.update(&MAP);
        if (IsKeyPressed(KEY_V)) player.noClipping = !player.noClipping;
        if (!IsKeyDown(KEY_TAB)) player.attachCamera(&freecam);
        MAP.renderPortals(&freecam);
        for (int i = 0; i < ballcount; i++) {
            balls[i].tick(&MAP);
        }
        t.ApplyTransform();
        MAP.lights[0].position = t.value;
        UpdateLight(MAP.lights[0]);
        
        BeginDrawing();
            ClearBackground(BLACK); // Clear the background
            BeginMode3D(freecam);
                MAP.draw();
                MAP.draw_portals();
                DrawPlayer(&player);
                for (int i = 0; i < ballcount; i++) {
                    balls[i].draw(&freecam);
                }
                for (int i = 0; i < MAP.lights.size(); i++) {
                    DrawBillboard(freecam, icon_lightbulb, MAP.lights[i].position, 1.0f, WHITE);
                }
            EndMode3D();
            if (debug) {
                AddLine(TextFormat("Player Position: %.2f %.2f %.2f", player.position.x, player.position.y, player.position.z), true);
                AddLine(TextFormat("Player Target: %.2f %.2f %.2f", player.target.x, player.target.y, player.target.z));
                AddLine(TextFormat("Player Velocity: %.2f %.2f %.2f", player.velocity.x, player.velocity.y, player.velocity.z));
                AddLine(TextFormat("Player Height: %.2f", player.height));
                AddLine(TextFormat("Player OnGround: %i", player.onGround));
                AddLine(TextFormat("Balls: %i", ballcount));
            }
        EndDrawing();
    }
    UnloadTextures();
    UnloadShaders();
    UnloadModels();
    CloseWindow();
    return 0;
}