#include <vector>
class Linedef {
public:
	Vector2 start;
	Vector2 end;
	float z;
};
class Wall {
public:
	Vector2 points[4];
	float z;
	float height;
	Texture* texture;
	Color tint;
};
class GameMap {
public:
	std::vector<Wall> walls;
	void draw() {
		for (Wall& wall : walls) {
			Vector2* points = wall.points;

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
		}
	}
};