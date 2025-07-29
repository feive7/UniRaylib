#define GRAVITY 2.0f
#define BOUNCE false
class Ball {
public:
	Vector3 position;
	Vector3 velocity;
	Color color;
	bool active = false;
	float radius = 0.5f;
	void tick(GameMap* scene) {
		if (position.y < -1000) active = false;
		if (!active) return;
		Vector3 wishvel = Vector3Subtract(velocity, {0.0f,GRAVITY*GetFrameTime(),0.0f});
		Vector3 oldpos = position;
		Vector3 newpos = position + wishvel;
		for (Wall& wall : scene->walls) {
			for (int i = 0; i < 4; i++) {
				Vector2 A = wall.points[i];
				Vector2 B = wall.points[(i + 1) % 4];
				Linedef line = { A,B };
				float distance = line.lineDistance({ newpos.x,newpos.z });
				if (distance < radius && oldpos.y - radius < wall.z + wall.height && oldpos.y + radius > wall.z) {
					Vector2 normal = line.getNormal();
					float side = line.lineSide({ newpos.x,newpos.z });
					Vector2 pushback = Vector2Scale(normal, side * (radius - distance));

					newpos.x -= pushback.x;
					newpos.z -= pushback.y;

					Vector3 normal3 = { normal.x, 0.0f, normal.y };
					wishvel = wishvel - Vector3Scale(normal3, 2 * Vector3DotProduct(wishvel, normal3));
				}
			}
			Vector2* p = wall.points;
			if (CheckCollisionCircleQuad({ newpos.x,newpos.z }, radius, p[0], p[1], p[2], p[3])) {
				if (newpos.y - radius < wall.z + wall.height && newpos.y - radius > wall.z + wall.height - 1.0f) { // Hit top of wall
					if (BOUNCE) {
						float distanceIn = wall.z + wall.height - newpos.y + radius;
						newpos.y = wall.z + wall.height + radius + distanceIn; // Place ball on top of wall
						wishvel.y = -wishvel.y;
					}
					else {
						wishvel.y = 0.0f;
						newpos.y = wall.z + wall.height + radius; // Place ball on top of wall without bouncing
					}
				}
				else if (newpos.y + radius > wall.z && newpos.y + radius < wall.z + 1.0f) { // Hit underside of wall
					if (BOUNCE) {
						float distanceIn = wall.z - newpos.y + radius;
						newpos.y = wall.z - radius;
						wishvel.y = -wishvel.y;
					}
					else {
						wishvel.y = 0.0f;
						newpos.y = wall.z - radius; // Place ball under wall without bouncing
					}
				}
			}
			velocity = wishvel;
			position = newpos;
		}
	}
	void draw3D() {
		if (!active) return;
		DrawModel(mdl_ball, position, radius, color);
	}
	void drawBillboard(Camera* camera) {
		if (!active) return;
		DrawBillboard(*camera, tex_ball, position, 1.0f, WHITE);
		//Vector2 screenpos = GetWorldToScreen(position, *camera);
		//DrawTexture(tex_ball, screenpos.x, screenpos.y, WHITE);
	}
};