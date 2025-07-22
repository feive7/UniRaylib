class Portal {
public:
	Linedef sectors[2];
	float height;
	RTCamera rtcameras[2];
	Vector3 offset() {
		return sectors[1].getMidpoint() - sectors[0].getMidpoint();
	}
	void update(Camera* playercam) {
		Vector3 camoffset = playercam->target - playercam->position;

		rtcameras[0].camera.position = playercam->position + offset();
		rtcameras[0].camera.target = rtcameras[0].camera.position + camoffset;
		rtcameras[1].camera.position = playercam->position - offset();
		rtcameras[0].camera.target = rtcameras[1].camera.position + camoffset;

	}
	void draw() {
		//rlBegin(RL_QUADS);
		for (int i = 0; i < 2; i++) {
			Line* l = &this->sectors[i].line;
			//rlSetTexture(this->rtcameras[i].RT.texture.id);
			//rlVertex3f(l->start.x, l->start.y, l->start.z);
			//rlVertex3f(l->end.x, l->end.y, l->end.z);
			//rlVertex3f(l->end.x, l->end.y + height, l->end.z);
			//rlVertex3f(l->start.x, l->start.y + height, l->start.z);
			DrawLine3D(l->start, l->end, RED);
		}
		//rlEnd();
	}
};