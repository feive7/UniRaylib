Model mdl_ball;
void InitModels() {
	mdl_ball = LoadModelFromMesh(GenMeshSphere(1.0f, 32, 32)); mdl_ball.materials[0].shader = *shaders[current_shader];
}
void UnloadModels() {
	UnloadModel(mdl_ball);
}