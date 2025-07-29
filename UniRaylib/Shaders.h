Shader shader_test;
Shader shader_window;
Shader shader_lighting;

int current_shader = 0;
Shader* shaders[] = {&shader_lighting,&shader_test};
const int shader_count = sizeof(shaders) / sizeof(Shader*);
void InitShaders() {
	shader_test = LoadShader("assets/shaders/test.vs", "assets/shaders/test.fs");
	shader_window = LoadShader("assets/shaders/window.vs", "assets/shaders/window.fs");
	shader_lighting = LoadShader("assets/shaders/lighting.vs", "assets/shaders/lighting2.fs");
}
void UnloadShaders() {
	UnloadShader(shader_test);
	UnloadShader(shader_window);
	UnloadShader(shader_lighting);
}