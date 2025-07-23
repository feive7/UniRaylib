#define MOUSE_SENSITIVITY 100
#define CAMERA_MODE_FIRST_PERSON 1
class Player {
public:
	Vector3 position;
	Vector3 target;
	float height;
	float radius;
	Camera* camera;
	Vector3 facing() {
		return Vector3Normalize(Vector3Subtract(target, position));
	}
	Vector3 headPos() {
		return Vector3Add(position, { 0.0f,height,0.0f });
	}
	void move(Vector3 movement, GameMap* scene) {
		Vector3 forward = facing(); forward.y = 0.0f; forward = Vector3Normalize(forward);
		Vector3 right = { -forward.z,0.0f,forward.x };
		Vector3 oldpos = position;
		Vector3 newpos = position + Vector3Scale(forward,movement.z) + Vector3Scale(right,movement.x);
		Vector3 collisionpos = position + Vector3Scale(Vector3Normalize(movement), radius);
		for (Wall& wall : scene->walls) {
			for (int i = 0; i < 4; i++) {
				Vector2 A = wall.points[i];
				Vector2 B = wall.points[(i+1)%4];
				Linedef line = { A,B };
				if (CheckCollisionLines(A, B, { oldpos.x,oldpos.z }, { collisionpos.x,collisionpos.z}, nullptr)) {
					newpos = oldpos;
				}
			}
		}
		for (Portal& portal : scene->portals) {
			Linedef* portal1 = &portal.sectors[0];
			Linedef* portal2 = &portal.sectors[1];
			if (CheckCollisionLines(portal1->start, portal1->end, { oldpos.x, oldpos.z }, { newpos.x, newpos.z }, nullptr) && newpos.y + height > portal1->z && newpos.y < portal1->z + portal.height) {
				//printf("Teleported to portal 2\n");
				portal.Teleport(&newpos, 2);
				break;
			}
			if (CheckCollisionLines(portal2->start, portal2->end, { oldpos.x, oldpos.z }, { newpos.x, newpos.z }, nullptr) && newpos.y + height > portal2->z && newpos.y < portal2->z + portal.height) {
				//printf("Teleported to portal 1\n");
				portal.Teleport(&newpos, 1);
				break;
			}
		}
		position = newpos;
		target = position + forward;
	}
	void attachCamera(Camera* camera, int mode = 1) {
		if (mode == CAMERA_MODE_FIRST_PERSON) {
			Vector3 camforward = GetCameraForward(camera);
			camera->position = headPos();
			camera->target = camera->position + camforward;
			target = camera->position + camforward;
		}
	}
};
void UpdateCameraScene(Camera* sceneCamera, GameMap* scene, bool move = false, bool ignore_portals = false) {
	float speed = 0.2f;
	if (IsKeyDown(KEY_LEFT_SHIFT)) speed = 0.5f;
	if (IsKeyDown(KEY_LEFT_CONTROL)) speed = 0.08f;

	Vector3 forward = GetCameraForward(sceneCamera) * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)); //forward.y = 0.0f; forward = Vector3Normalize(forward);
	Vector3 right = GetCameraRight(sceneCamera) * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)); //right.y = 0.0f; right = Vector3Normalize(right);
	Vector3 up = GetCameraUp(sceneCamera) * (IsKeyDown(KEY_SPACE));
	Vector3 movement = (forward + right + up) * speed;

	Vector3 oldpos = sceneCamera->position;
	Vector3 newpos = sceneCamera->position + movement;
	if (!ignore_portals) {
		for (Portal& portal : scene->portals) {
			Linedef* portal1 = &portal.sectors[0];
			Linedef* portal2 = &portal.sectors[1];
			if (CheckCollisionLines(portal1->start, portal1->end, { oldpos.x, oldpos.z }, { newpos.x, newpos.z }, nullptr) && newpos.y > portal1->z && newpos.y < portal1->z + portal.height) {
				//printf("Teleported to portal 2\n");
				portal.Teleport(&newpos, 2);
				break;
			}
			if (CheckCollisionLines(portal2->start, portal2->end, { oldpos.x, oldpos.z }, { newpos.x, newpos.z }, nullptr) && newpos.y > portal2->z && newpos.y < portal2->z + portal.height) {
				//printf("Teleported to portal 1\n");
				portal.Teleport(&newpos, 1);
				break;
			}
		}
	}

	Vector2 mDelta = GetMouseDelta();
	UpdateCameraPro(sceneCamera, {0.0f,0.0f,0.0f}, { MOUSE_SENSITIVITY * mDelta.x / 800.0f, MOUSE_SENSITIVITY * mDelta.y / 450.0f, 0.0f }, 0.0f);

	Vector3 camoffset = sceneCamera->target - sceneCamera->position;
	sceneCamera->position = newpos;
	sceneCamera->target = sceneCamera->position + camoffset;
}