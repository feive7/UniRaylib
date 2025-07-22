Shader shader_test;
Shader shader_window;
void InitShaders() {
	shader_test = LoadShader("assets/shaders/test.vs", "assets/shaders/test.fs");
	shader_window = LoadShader("assets/shaders/window.vs", "assets/shaders/window.fs");
}
void UnloadShaders() {
	UnloadShader(shader_test);
	UnloadShader(shader_window);
}