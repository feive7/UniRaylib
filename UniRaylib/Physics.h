class Physobj {
public:
	Vector3 position;
	Vector3 target;
	Vector3 velocity;
	Vector3 forward() {
		return Vector3Normalize(Vector3Subtract(target, position));
	}
	Vector3 right() {
		Vector3 f = forward();
		return {f.z,f.y,-f.x};
	}
	void move(Vector3 movement) {
		velocity = movement;
	}
	void update() {
		position += velocity;
	}
};