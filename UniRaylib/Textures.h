Texture tex_scifi_floortile;
Texture tex_crate_c;
void InitTextures() {
	tex_scifi_floortile = LoadTexture("assets/textures/tex_scifi_floortile.jpg");
	tex_crate_c = LoadTexture("assets/textures/tex_crate_c.png");
}
void UnloadTextures() {
	UnloadTexture(tex_scifi_floortile);
	UnloadTexture(tex_crate_c);
}