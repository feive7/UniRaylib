struct Light {
	Vector3 position;
	float power;

	int position_loc;
	int power_loc;
};
struct LightPortal {
	Vector3 pos1;
	Vector3 pos2;

	int pos1_loc;
	int pos2_loc;
};

static int lightsCount = 0;
static int lightPortalsCount = 0;

void UpdateLight(Light light) {
	SetShaderValue(shader_lighting, light.position_loc, &light.position, SHADER_UNIFORM_VEC3);
	SetShaderValue(shader_lighting, light.power_loc, &light.power, SHADER_UNIFORM_FLOAT);
}
void UpdateLightPortal(LightPortal lp) {
	SetShaderValue(shader_lighting, lp.pos1_loc, &lp.pos1, SHADER_UNIFORM_VEC3);
	SetShaderValue(shader_lighting, lp.pos2_loc, &lp.pos2, SHADER_UNIFORM_VEC3);
}
Light CreateLight(Vector3 position, float power) {
	Light light = { 0 };
	light.position = position;
	light.power = power;
	light.position_loc = GetShaderLocation(shader_lighting, TextFormat("lights[%i].position", lightsCount));
	light.power_loc = GetShaderLocation(shader_lighting, TextFormat("lights[%i].power", lightsCount));
	lightsCount++;
	UpdateLight(light);
	return light;
}
LightPortal CreateLightPortal(Vector3 pos1, Vector3 pos2) {
	LightPortal lp = { 0 };
	lp.pos1 = pos1;
	lp.pos2 = pos2;
	lp.pos1_loc = GetShaderLocation(shader_lighting, TextFormat("lightPortals[%i].pos1", lightPortalsCount));
	lp.pos2_loc = GetShaderLocation(shader_lighting, TextFormat("lightPortals[%i].pos2", lightPortalsCount));
	lightPortalsCount++;
	UpdateLightPortal(lp); 
	return lp;
}