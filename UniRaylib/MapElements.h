#include <vector>
struct Playerstart {
	Vector3 position;
	Vector3 target;
};
class Linedef {
public:
	Vector2 start;
	Vector2 end;
	float z;
	Vector2 getMidpointXZ() {
		return Vector2Scale(start + end, 0.5f);
	}
	Vector3 getMidpoint() {
		Vector3 start3D = { start.x,z,start.y };
		Vector3 end3D = { end.x,z,end.y };
		return Vector3Scale(end3D + start3D, 0.5f);
	}
	Vector2 getDirection() {
		return Vector2Normalize({ end.x - start.x,end.y - start.y });
	}
	Vector2 getNormal() {
		Vector2 dir = getDirection();
		return { -dir.y,dir.x };
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
		for (int from = 0; from < 2; from++) {
			int to = 1 - from;

			// Get midpoints
			Vector3 fromMid = sectors[from].getMidpoint();
			Vector3 toMid = sectors[to].getMidpoint();

			// Get 2D directions
			Vector2 fromDir2D = sectors[from].getDirection();
			Vector2 toDir2D = sectors[to].getDirection();

			// Calculate angle difference
			float angleFrom = atan2f(fromDir2D.y, fromDir2D.x);
			float angleTo = atan2f(toDir2D.y, toDir2D.x);
			float deltaAngle = angleTo - angleFrom + PI; // +PI flips view for "looking through" portal

			// Relative position and direction to source portal
			Vector3 localPos = playercam->position - fromMid;
			Vector3 localTargetOffset = playercam->target - playercam->position;

			// Rotate around Y axis
			Vector3 rotatedPos = Vector3RotateByAxisAngle(localPos, { 0, 1, 0 }, deltaAngle);
			Vector3 rotatedTargetOffset = Vector3RotateByAxisAngle(localTargetOffset, { 0, 1, 0 }, deltaAngle);

			// Update camera
			RTCameras[from].position = toMid + rotatedPos;
			RTCameras[from].target = RTCameras[from].position + rotatedTargetOffset;
			RTCameras[from].up = playercam->up;
		}
	}

	void Teleport(Vector3* pos, int to) {
		if (to == 2) {
			*pos += offset();
		}
		else if (to == 1) {
			*pos -= offset();
		}
	}


	void draw(bool debug_mode = false) {
		BeginShaderMode(shader_window);
		rlBegin(RL_QUADS);
		for (int i = 0; i < 2; i++) {
			Linedef* l = &sectors[i];
			if (debug_mode) {
				if (i == 0) rlColor4ub(255, 100, 100, 255);
				else rlColor4ub(100, 100, 255, 255);
			}
			else {
				rlSetTexture(RTextures[i].texture.id);
			}
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
	Playerstart playerstart;
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