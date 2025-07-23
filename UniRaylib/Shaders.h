Shader shader_test;
Shader shader_window;
Shader shader_lighting;
void InitShaders() {
	shader_test = LoadShader("assets/shaders/test.vs", "assets/shaders/test.fs");
	shader_window = LoadShader("assets/shaders/window.vs", "assets/shaders/window.fs");
	shader_lighting = LoadShader("assets/shaders/lighting.vs", "assets/shaders/lighting.fs");
}
void UnloadShaders() {
	UnloadShader(shader_test);
	UnloadShader(shader_window);
	UnloadShader(shader_lighting);
}