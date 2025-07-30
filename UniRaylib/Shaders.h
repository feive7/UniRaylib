Shader shader_window;

Shader shader_none;
Shader shader_darkness;
Shader shader_lighting;

int current_shader = 1;
Shader* shaders[] = {&shader_none,&shader_lighting,&shader_darkness};
std::string shader_names[] = {"None","Lighting","Test"};
const int shader_count = sizeof(shaders) / sizeof(Shader*);
void InitShaders() {
	shader_window = LoadShader("assets/shaders/window.vs", "assets/shaders/window.fs");

	shader_none = LoadShader("assets/shaders/base.vs", "assets/shaders/base.fs");
	shader_darkness = LoadShader("assets/shaders/darkness.vs", "assets/shaders/darkness.fs");
	shader_lighting = LoadShader("assets/shaders/lighting.vs", "assets/shaders/lighting1.fs");
}
void UnloadShaders() {
	UnloadShader(shader_window);

	UnloadShader(shader_none);
	UnloadShader(shader_darkness);
	UnloadShader(shader_lighting);
}