GameMap testmap = {
	{
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-44.5f,-0.65f},{-43.5f,-0.65f},{-43.5f,-0.85f},{-44.5f,-0.85f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.001
		{{{-44.5f,0.85f},{-43.5f,0.85f},{-43.5f,0.65f},{-44.5f,0.65f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.002
		{{{-43.3f,-0.5f},{-43.3f,0.5f},{-43.1f,0.5f},{-43.1f,-0.5f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.003
		{{{-43.5f,-0.65f},{-43.3f,-0.5f},{-43.1f,-0.5f},{-43.5f,-0.85f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.004
		{{{-44.5f,0.65f},{-44.7f,0.5f},{-44.9f,0.5f},{-44.5f,0.85f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.005
		{{{-44.7f,0.5f},{-44.7f,-0.5f},{-44.9f,-0.5f},{-44.9f,0.5f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.006
		{{{-44.7f,-0.5f},{-44.5f,-0.65f},{-44.5f,-0.85f},{-44.9f,-0.5f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.007
		{{{-43.3f,0.5f},{-43.5f,0.65f},{-43.5f,0.85f},{-43.1f,0.5f}},6.25f,0.2f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.008
		{{{-10.0f,-44.0f},{10.0f,-44.0f},{10.0f,-46.0f},{-10.0f,-46.0f}},-1.0f,20.0f,&tex_mark,WHITE,&shader_lighting,0}, // Cube.001
		{{{-6.0f,24.0f},{7.0f,24.0f},{12.0f,12.0f},{-12.0f,12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.001
		{{{-24.0f,-6.0f},{-24.0f,7.0f},{-12.0f,12.0f},{-12.0f,-12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.002
		{{{6.0f,-24.0f},{-7.0f,-24.0f},{-12.0f,-12.0f},{12.0f,-12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.003
		{{{24.0f,6.0f},{24.0f,-7.0f},{12.0f,-12.0f},{12.0f,12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.004
		{{{7.0f,24.0f},{17.0f,17.0f},{24.0f,6.0f},{12.0f,12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.005
		{{{-24.0f,7.0f},{-17.0f,17.0f},{-6.0f,24.0f},{-12.0f,12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.006
		{{{-7.0f,-24.0f},{-17.0f,-17.0f},{-24.0f,-6.0f},{-12.0f,-12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.007
		{{{24.0f,-7.0f},{17.0f,-17.0f},{6.0f,-24.0f},{12.0f,-12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.008
		{{{-12.0f,12.0f},{12.0f,12.0f},{12.0f,-12.0f},{-12.0f,-12.0f}},-2.0f,2.0f,&tex_grass,WHITE,&shader_lighting,0}, // grass.009
		{{{-6.0f,8.0f},{-6.0f,6.0f},{-8.0f,6.0f},{-8.0f,8.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.001
		{{{8.0f,8.0f},{8.0f,6.0f},{6.0f,6.0f},{6.0f,8.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.002
		{{{6.0f,-6.0f},{8.0f,-6.0f},{8.0f,-8.0f},{6.0f,-8.0f}},0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.003
		{{{-9.0f,9.0f},{9.0f,9.0f},{9.0f,-9.0f},{-9.0f,-9.0f}},6.0f,0.5f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.004
		{{{-8.0f,-6.0f},{-6.0f,-6.0f},{-6.0f,-8.0f},{-8.0f,-8.0f}},0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.005
		{{{-7.2f,7.2f},{7.2f,7.2f},{7.2f,-7.2f},{-7.2f,-7.2f}},6.5f,0.5f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.012
		{{{-45.1f,1.5f},{-44.9f,1.5f},{-44.9f,-1.5f},{-45.1f,-1.5f}},6.0f,2.0f,&tex_scifi_floortile,WHITE,&shader_lighting,0}, // scifi_floortile.017
		{{{-50.0f,50.0f},{50.0f,50.0f},{50.0f,-50.0f},{-50.0f,-50.0f}},-3.0f,2.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.002
		{{{-45.1f,0.1f},{-44.9f,0.1f},{-44.9f,-0.1f},{-45.1f,-0.1f}},-1.0f,7.0f,&tex_wooddoor,WHITE,&shader_lighting,0}, // wooddoor
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	1.0, // Ambient lighting
	{ // Lights
	},
};