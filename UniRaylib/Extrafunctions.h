float LineDistance(Vector2 p, Vector2 start, Vector2 end) {
	Vector2 ab = Vector2Subtract(end, start);
	Vector2 ap = Vector2Subtract(p, start);
	float ab_len2 = Vector2LengthSqr(ab);

	if (ab_len2 == 0.0f) return Vector2Distance(p, start); // a == b

	float t = Vector2DotProduct(ap, ab) / ab_len2;
	t = fmaxf(0.0f, fminf(1.0f, t)); // Clamp to segment

	Vector2 projection = Vector2Add(start, Vector2Scale(ab, t));
	return Vector2Distance(p, projection);
}
bool CheckCollisionPointQuad(Vector2 p, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
	return CheckCollisionPointTriangle(p, a, b, c) || CheckCollisionPointTriangle(p, a, c, d);
}
bool CheckCollisionCircleQuad(Vector2 circleCenter, float radius, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
	// Check if circle center is inside the quad
	if (CheckCollisionPointQuad(Vector2Add(circleCenter, { 0.001f,0.001f }), a, b, c, d)) {
		return true; // Circle center is inside the quad
	}
	// Check distance from circle center to each edge of the quad
	float dist1 = LineDistance(circleCenter, a, b);
	float dist2 = LineDistance(circleCenter, b, c);
	float dist3 = LineDistance(circleCenter, c, d);
	float dist4 = LineDistance(circleCenter, d, a);
	if (dist1 < radius || dist2 < radius || dist3 < radius || dist4 < radius) {
		return true; // Circle collides with at least one edge of the quad
	}
	return false; // No collision detected
}
void E() {
	printf("Trigger\n");
}
void printV(Vector3 v) {
	printf("%f %f %f\n", v.x, v.y, v.z);
}
void toggle(bool& boolean) {
	boolean = !boolean;
}