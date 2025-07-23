Texture tex_scifi_floortile;
Texture tex_crate_c;
Texture tex_grass;
Texture tex_rockwall;
Texture tex_woodfloor;
Texture tex_concretewall;
Texture tex_brick;
Texture tex_stone;
Texture tex_error;
void InitTextures() {
	tex_scifi_floortile = LoadTexture("assets/textures/tex_scifi_floortile.jpg");
	tex_crate_c = LoadTexture("assets/textures/tex_crate_c.png");
	tex_grass = LoadTexture("assets/textures/tex_grass.png");
	tex_rockwall = LoadTexture("assets/textures/tex_rockwall.png");
	tex_woodfloor = LoadTexture("assets/textures/tex_woodfloor.png");
	tex_concretewall = LoadTexture("assets/textures/tex_concretewall.jpg");
	tex_brick = LoadTexture("assets/textures/tex_brick.jpg");
	tex_stone = LoadTexture("assets/textures/tex_stone.jpg");
	tex_error = LoadTexture("assets/textures/tex_error.png");
}
void UnloadTextures() {
	UnloadTexture(tex_scifi_floortile);
	UnloadTexture(tex_crate_c);
	UnloadTexture(tex_grass);
	UnloadTexture(tex_rockwall);
	UnloadTexture(tex_woodfloor);
	UnloadTexture(tex_concretewall);
	UnloadTexture(tex_brick);
	UnloadTexture(tex_stone);
	UnloadTexture(tex_error);
}