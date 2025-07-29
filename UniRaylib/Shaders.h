Shader shader_test;
Shader shader_window;
Shader shader_lighting1;
Shader shader_lighting2;

int current_shader = 2;
Shader* shaders[] = {&shader_lighting1,&shader_lighting2};
const int shader_count = sizeof(shaders) / sizeof(Shader*);
void InitShaders() {
	shader_test = LoadShader("assets/shaders/test.vs", "assets/shaders/test.fs");
	shader_window = LoadShader("assets/shaders/window.vs", "assets/shaders/window.fs");
	shader_lighting1 = LoadShader("assets/shaders/lighting.vs", "assets/shaders/lighting1.fs");
	shader_lighting2 = LoadShader("assets/shaders/lighting.vs", "assets/shaders/lighting2.fs");
}
void UnloadShaders() {
	UnloadShader(shader_test);
	UnloadShader(shader_window);
	UnloadShader(shader_lighting1);
	UnloadShader(shader_lighting2);
}