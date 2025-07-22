#include <vector>
class Linedef {
public:
	Vector2 start;
	Vector2 end;
	float z;
	Vector3 getMidpoint() {
		Vector3 start3D = { start.x,z,start.y };
		Vector3 end3D = { end.x,z,end.y };
		return Vector3Scale(end3D + start3D, 0.5);
	}
};
class Wall {
public:
	Vector2 points[4];
	float z;
	float height;
	Texture* texture;
	Color tint;
	Shader* shader;
};
class Portal {
public:
	Linedef sectors[2];
	float height;

	RenderTexture RTextures[2];
	Camera RTCameras[2];

	void InitPortals() {
		RTextures[0] = LoadRenderTexture(800, 450);
		RTextures[1] = LoadRenderTexture(800, 450);

		RTCameras[0].position = { 0.0f, 2.0f, 10.0f };  // Camera position
		RTCameras[0].target = { 0.0f, 0.0f, 0.0f };     // Camera looking at point
		RTCameras[0].up = { 0.0f, 1.0f, 0.0f };         // Camera up vector (rotation towards target)
		RTCameras[0].fovy = 45.0f;                      // Camera field-of-view Y
		RTCameras[0].projection = CAMERA_PERSPECTIVE;   // Camera mode type

		RTCameras[1].position = { 0.0f, 2.0f, 10.0f };  // Camera position
		RTCameras[1].target = { 0.0f, 0.0f, 0.0f };     // Camera looking at point
		RTCameras[1].up = { 0.0f, 1.0f, 0.0f };         // Camera up vector (rotation towards target)
		RTCameras[1].fovy = 45.0f;                      // Camera field-of-view Y
		RTCameras[1].projection = CAMERA_PERSPECTIVE;   // Camera mode type
	}
	Vector3 offset() {
		return sectors[1].getMidpoint() - sectors[0].getMidpoint();
	}
	void updatePerspective(Camera* playercam) {
		RTCameras[0].position = playercam->position + offset();
		RTCameras[0].target = playercam->target + offset();

		RTCameras[1].position = playercam->position - offset();
		RTCameras[1].target = playercam->target - offset();
	}
	void draw() {
		BeginShaderMode(shader_window);
		rlBegin(RL_QUADS);
		for (int i = 0; i < 2; i++) {
			Linedef* l = &sectors[i];
			rlColor4ub(255, 255, 255, 255);
			rlSetTexture(RTextures[i].texture.id);
			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(l->start.x, l->z, l->start.y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(l->end.x, l->z, l->end.y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(l->end.x, l->z + height, l->end.y);
			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(l->start.x, l->z + height, l->start.y);

			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(l->start.x, l->z + height, l->start.y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(l->end.x, l->z + height, l->end.y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(l->end.x, l->z, l->end.y);
			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(l->start.x, l->z, l->start.y);
		}
		rlEnd();
		EndShaderMode();
	}
};
class GameMap {
public:
	std::vector<Wall> walls;
	std::vector<Portal> portals;
	void draw() {
		for (Wall& wall : walls) {
			Vector2* points = wall.points;

			BeginShaderMode(*wall.shader);
			rlBegin(RL_QUADS);
			rlColor4ub(wall.tint.r,wall.tint.g,wall.tint.b,wall.tint.a);
			rlSetTexture(wall.texture->id);

			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[0].x, wall.z, points[0].y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[1].x, wall.z, points[1].y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[2].x, wall.z, points[2].y);
			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[3].x, wall.z, points[3].y);
			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[3].x, wall.z, points[3].y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[2].x, wall.z, points[2].y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[1].x, wall.z, points[1].y);
			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[0].x, wall.z, points[0].y);

			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[0].x, wall.z + wall.height, points[0].y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[1].x, wall.z + wall.height, points[1].y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[2].x, wall.z + wall.height, points[2].y);
			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[3].x, wall.z + wall.height, points[3].y);
			rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[3].x, wall.z + wall.height, points[3].y);
			rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[2].x, wall.z + wall.height, points[2].y);
			rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[1].x, wall.z + wall.height, points[1].y);
			rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[0].x, wall.z + wall.height, points[0].y);

			for (int i = 0; i < 4; i++) {
				rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[i].x, wall.z, points[i].y);
				rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[(i+1)%4].x, wall.z, points[(i+1)%4].y);
				rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[(i+1)%4].x, wall.z + wall.height, points[(i+1)%4].y);
				rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[i].x, wall.z + wall.height, points[i].y);
				rlTexCoord2f(0.0f, 1.0f); rlVertex3f(points[i].x, wall.z + wall.height, points[i].y);
				rlTexCoord2f(1.0f, 1.0f); rlVertex3f(points[(i+1)%4].x, wall.z + wall.height, points[(i+1)%4].y);
				rlTexCoord2f(1.0f, 0.0f); rlVertex3f(points[(i+1)%4].x, wall.z, points[(i+1)%4].y);
				rlTexCoord2f(0.0f, 0.0f); rlVertex3f(points[i].x, wall.z, points[i].y);
			}

			rlEnd();
			EndShaderMode();
		}
	}
	void draw_portals() {
		for (Portal& portal : portals) {
			portal.draw();
		}
	}
	void renderPortals(Camera* playercam) {
		for (Portal& portal : portals) {
			portal.updatePerspective(playercam);
			for (int i = 0; i < 2; i++) {
				BeginTextureMode(portal.RTextures[i]);
				ClearBackground(RAYWHITE); // Clear the background
				BeginMode3D(portal.RTCameras[i]);
				draw();
				EndMode3D();
				EndTextureMode();
			}
		}
	}
};