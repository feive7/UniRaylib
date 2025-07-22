GameMap testmap;
void InitTestMap() {
	testmap.walls = {
		{{{-5.0f,16.0f},{5.0f,16.0f},{5.0f,14.0f},{-5.0f,14.0f}},0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{5.0f,-16.0f},{-5.0f,-16.0f},{-5.0f,-14.0f},{5.0f,-14.0f}},0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{16.0f,5.0f},{16.0f,-5.0f},{14.0f,-5.0f},{14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-16.0f,-5.0f},{-16.0f,5.0f},{-14.0f,5.0f},{-14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-16.0f,5.0f},{-12.0f,12.0f},{-10.0f,10.0f},{-14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-16.0f,-5.0f},{-12.0f,-12.0f},{-10.0f,-10.0f},{-14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{16.0f,-5.0f},{12.0f,-12.0f},{10.0f,-10.0f},{14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{16.0f,5.0f},{12.0f,12.0f},{10.0f,10.0f},{14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-5.0f,16.0f},{-12.0f,12.0f},{-10.0f,10.0f},{-5.0f,14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{5.0f,16.0f},{12.0f,12.0f},{10.0f,10.0f},{5.0f,14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{5.0f,-16.0f},{12.0f,-12.0f},{10.0f,-10.0f},{5.0f,-14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-5.0f,-16.0f},{-12.0f,-12.0f},{-10.0f,-10.0f},{-5.0f,-14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_test},
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{10.0f,10.0f},{14.0f,5.0f},{14.0f,-5.0f},{10.0f,-10.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{-10.0f,10.0f},{-5.0f,14.0f},{5.0f,14.0f},{10.0f,10.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{-10.0f,-10.0f},{-14.0f,-5.0f},{-14.0f,5.0f},{-10.0f,10.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{10.0f,-10.0f},{5.0f,-14.0f},{-5.0f,-14.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{10.0f,-10.0f},{5.0f,-14.0f},{-5.0f,-14.0f},{-10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{-10.0f,-10.0f},{-14.0f,-5.0f},{-14.0f,5.0f},{-10.0f,10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{-10.0f,10.0f},{-5.0f,14.0f},{5.0f,14.0f},{10.0f,10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{10.0f,10.0f},{14.0f,5.0f},{14.0f,-5.0f},{10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_test},
	};
}