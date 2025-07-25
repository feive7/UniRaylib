#define MOUSE_SENSITIVITY 100
#define CAMERA_MODE_FIRST_PERSON 1
#define GRAVITY 2.0f
class Player {
public:
	Vector3 position;
	Vector3 target;
	Vector3 velocity;
	float height;
	float maxHeight;
	float radius;
	float speed;

	bool onGround = false;
	bool jumping = false;
	bool crouching = false;
	bool sprinting = false;
	bool noClipping = false;

	Vector3 headPos() {
		return Vector3Add(position, { 0.0f,height - 1.0f,0.0f });
	}
	Vector3 getForward() {
		return Vector3Normalize(Vector3Subtract(target, position));
	}
	Vector3 getRight() {
		Vector3 f = getForward();
		return { -f.z,0.0f,f.x };
	}
	Vector3 tryMove(Vector3& wishvel, GameMap* scene) {
		Vector3 oldpos = position;
		Vector3 newpos = position + wishvel;
		if (!noClipping) {
			bool grounded = false;
			bool touchingWall = false;
			for (Wall& wall : scene->walls) {
				for (int i = 0; i < 4; i++) {
					Vector2 A = wall.points[i];
					Vector2 B = wall.points[(i + 1) % 4];
					Linedef line = { A,B };
					float distance = line.lineDistance({ newpos.x,newpos.z });
					if (distance < radius && oldpos.y < wall.z + wall.height && oldpos.y + height > wall.z) {
						Vector2 normal = line.getNormal();
						float side = line.lineSide({ newpos.x,newpos.z });
						Vector2 pushback = Vector2Scale(normal, side * (radius - distance));

						wishvel.x -= pushback.x;
						wishvel.z -= pushback.y;

						newpos.x -= pushback.x;
						newpos.z -= pushback.y;

						touchingWall = true;
					}
				}
				Vector2* p = wall.points;
				if (CheckCollisionCircleQuad({ newpos.x,newpos.z }, radius, p[0], p[1], p[2], p[3])) {
					if (newpos.y <= wall.z + wall.height && newpos.y > wall.z + wall.height - 1.0f) {
						grounded = true;
						wishvel.y = 0.0f;
						newpos.y = wall.z + wall.height;
					}
					else if (newpos.y + height > wall.z && newpos.y + height < wall.z + 1.0f) {
						wishvel.y = 0.0f;
						newpos.y = wall.z - height;
					}
				}
			}
			onGround = grounded;
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
		return newpos;
	}
	void accelerate(Vector3 wishdir, float wishspeed, float accel) {
		float currentspeed = Vector3DotProduct(velocity, wishdir);
		float addspeed = wishspeed - currentspeed;
		if (addspeed <= 0.0f) return; // No accelerat
		float accelspeed = accel * GetFrameTime() * wishspeed;
		if (accelspeed > addspeed) accelspeed = addspeed; // Limit acceleration
		Vector3 addendum = wishdir * accelspeed;
		velocity.x += addendum.x;
		velocity.z += addendum.z;
	}
	void noclip(Vector3 localMovement) {
		Vector3 forward = getForward();
		Vector3 right = getRight();
		Vector3 movement = Vector3Scale(forward, localMovement.z) + Vector3Scale({0.0f,1.0f,0.0f}, localMovement.y) + Vector3Scale(right, localMovement.x);
		position += movement;
		target = position + forward;
	}
	void move(Vector3 localMovement, GameMap* scene) {
		Vector3 forward = getForward(); forward.y = 0.0f; forward = Vector3Normalize(forward);
		Vector3 right = getRight();
		
		Vector3 wishvel = Vector3Scale(forward, localMovement.z) + Vector3Scale(right, localMovement.x);
		/*Vector3 wishdir = Vector3Normalize(wishvel);
		float wishspeed = Vector3Length(wishvel);
		accelerate(wishdir, wishspeed, 8.0f);
		if (wishspeed == 0.0f) {
			velocity = Vector3Scale(velocity, 0.9);
		}*/
		velocity.x = wishvel.x;
		velocity.z = wishvel.z;
		if (onGround) {
			velocity.y = 0.0f;
		}
		else {
			velocity.y -= GRAVITY * GetFrameTime();
		}
		position = tryMove(velocity, scene);

		target = position + forward;
	}
	void attachCamera(Camera* camera, int mode = 1) {
		if (mode == CAMERA_MODE_FIRST_PERSON) {
			Vector3 camforward = GetCameraForward(camera);
			camera->position = headPos();
			camera->target = camera->position + camforward;
			target = position + camforward;
		}
	}
	void updateSpeed() {
		if (crouching) {
			speed = 0.08f;
		}
		else if (sprinting) {
			speed = 0.5f;
		}
		else {
			speed = 0.2f;
		}
	}
	void updateState() {
		sprinting = IsKeyDown(KEY_LEFT_SHIFT);
		crouching = IsKeyDown(KEY_LEFT_CONTROL);
		jumping = IsKeyDown(KEY_SPACE);
	}
	void updateHeight() {
		if (crouching) {
			float targetheight = maxHeight - 1.0f;
			height = (targetheight - height) * 0.5f + height;
		}
		else {
			float targetheight = maxHeight;
			height = (targetheight - height) * 0.5f + height;
		}
	}
	void update(GameMap* scene) {
		updateState();
		updateHeight();
		updateSpeed();
		Vector3 movement = { IsKeyDown(KEY_D) - IsKeyDown(KEY_A), IsKeyDown(KEY_SPACE) - IsKeyDown(KEY_LEFT_CONTROL),IsKeyDown(KEY_W) - IsKeyDown(KEY_S)};

		if (jumping && onGround) {
			velocity.y = 0.5f;
			onGround = false;
		}

		movement = Vector3Scale(movement, speed);
		if (noClipping) {
			noclip(movement);
		}
		else {
			move(movement, scene);
		}
	}
};
void UpdateCameraScene(Camera* sceneCamera, GameMap* scene, bool move = false, bool ignore_portals = false) {
	if (move) {
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

		Vector3 camoffset = sceneCamera->target - sceneCamera->position;
		sceneCamera->position = newpos;
		sceneCamera->target = sceneCamera->position + camoffset;
	}

	Vector2 mDelta = GetMouseDelta();
	UpdateCameraPro(sceneCamera, {0.0f,0.0f,0.0f}, { MOUSE_SENSITIVITY * mDelta.x / 800.0f, MOUSE_SENSITIVITY * mDelta.y / 450.0f, 0.0f }, 0.0f);
}