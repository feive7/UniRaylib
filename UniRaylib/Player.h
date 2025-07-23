#define MOUSE_SENSITIVITY 100
void UpdateCameraScene(Camera* sceneCamera, GameMap* scene) {
	float speed = 0.2f;
	if (IsKeyDown(KEY_LEFT_SHIFT)) speed = 0.5f;
	if (IsKeyDown(KEY_LEFT_CONTROL)) speed = 0.08f;

	Vector3 forward = GetCameraForward(sceneCamera) * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)); //forward.y = 0.0f; forward = Vector3Normalize(forward);
	Vector3 right = GetCameraRight(sceneCamera) * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)); //right.y = 0.0f; right = Vector3Normalize(right);
	Vector3 up = GetCameraUp(sceneCamera) * (IsKeyDown(KEY_SPACE));
	Vector3 movement = (forward + right + up) * speed;

	Vector3 oldpos = sceneCamera->position;
	Vector3 newpos = sceneCamera->position + movement;
	for (Portal& portal : scene->portals) {
		Linedef* portal1 = &portal.sectors[0];
		Linedef* portal2 = &portal.sectors[1];
		if (CheckCollisionLines(portal1->start, portal1->end, { oldpos.x, oldpos.z}, { newpos.x, newpos.z }, nullptr) && newpos.y > portal1->z && newpos.y < portal1->z + portal.height) {
			printf("Teleported to portal 2\n");
			portal.Teleport(&newpos,2);
			break;
		}
		if (CheckCollisionLines(portal2->start, portal2->end, { oldpos.x, oldpos.z }, { newpos.x, newpos.z }, nullptr) && newpos.y > portal2->z && newpos.y < portal2->z + portal.height) {
			printf("Teleported to portal 1\n");
			portal.Teleport(&newpos, 1);
			break;
		}
	}

	Vector2 mDelta = GetMouseDelta();
	UpdateCameraPro(sceneCamera, {0.0f,0.0f,0.0f}, { MOUSE_SENSITIVITY * mDelta.x / 800.0f, MOUSE_SENSITIVITY * mDelta.y / 450.0f, 0.0f }, 0.0f);

	Vector3 camoffset = sceneCamera->target - sceneCamera->position;
	sceneCamera->position = newpos;
	sceneCamera->target = sceneCamera->position + camoffset;
}