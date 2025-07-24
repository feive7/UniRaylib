GameMap testmap = {
	{
		{3.0f,0.0f,3.0f},
		{3.0f,0.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{
		{{{0.0f,10.0f},{10.0f,10.0f},{10.0f,0.0f},{0.0f,0.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.009
		{{{10.0f,10.0f},{14.0f,5.0f},{14.0f,-5.0f},{10.0f,-10.0f}},-1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.010
		{{{-10.0f,10.0f},{-5.0f,14.0f},{5.0f,14.0f},{10.0f,10.0f}},-1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.011
		{{{-10.0f,-10.0f},{-14.0f,-5.0f},{-14.0f,5.0f},{-10.0f,10.0f}},-1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.012
		{{{10.0f,-10.0f},{5.0f,-14.0f},{-5.0f,-14.0f},{-10.0f,-10.0f}},-1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.013
		{{{10.0f,-10.0f},{5.0f,-14.0f},{-5.0f,-14.0f},{-10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.014
		{{{-10.0f,-10.0f},{-14.0f,-5.0f},{-14.0f,5.0f},{-10.0f,10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.015
		{{{-10.0f,10.0f},{-5.0f,14.0f},{5.0f,14.0f},{10.0f,10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.016
		{{{10.0f,10.0f},{14.0f,5.0f},{14.0f,-5.0f},{10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.017
		{{{-10.0f,-0.0f},{-10.0f,10.0f},{-0.0f,10.0f},{0.0f,0.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.018
		{{{0.0f,-10.0f},{-10.0f,-10.0f},{-10.0f,-0.0f},{-0.0f,0.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.019
		{{{10.0f,0.0f},{10.0f,-10.0f},{0.0f,-10.0f},{-0.0f,-0.0f}},-2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.020
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c.022
		{{{-5.0f,16.0f},{5.0f,16.0f},{5.0f,14.0f},{-5.0f,14.0f}},0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.001
		{{{5.0f,-16.0f},{-5.0f,-16.0f},{-5.0f,-14.0f},{5.0f,-14.0f}},0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.002
		{{{16.0f,5.0f},{16.0f,-5.0f},{14.0f,-5.0f},{14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.003
		{{{-16.0f,-5.0f},{-16.0f,5.0f},{-14.0f,5.0f},{-14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.004
		{{{-16.0f,5.0f},{-12.0f,12.0f},{-10.0f,10.0f},{-14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.005
		{{{-16.0f,-5.0f},{-12.0f,-12.0f},{-10.0f,-10.0f},{-14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.006
		{{{16.0f,-5.0f},{12.0f,-12.0f},{10.0f,-10.0f},{14.0f,-5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.007
		{{{16.0f,5.0f},{12.0f,12.0f},{10.0f,10.0f},{14.0f,5.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.008
		{{{-5.0f,16.0f},{-12.0f,12.0f},{-10.0f,10.0f},{-5.0f,14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.009
		{{{5.0f,16.0f},{12.0f,12.0f},{10.0f,10.0f},{5.0f,14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.010
		{{{5.0f,-16.0f},{12.0f,-12.0f},{10.0f,-10.0f},{5.0f,-14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.011
		{{{-5.0f,-16.0f},{-12.0f,-12.0f},{-10.0f,-10.0f},{-5.0f,-14.0f}},-0.0f,6.0f,&tex_scifi_floortile,WHITE,&shader_lighting}, // scifi_floortile.012
	},
	{
	},
	1.0, // Ambient lighting
 	{
	},
};