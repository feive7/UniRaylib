GameMap testmap = {
	{
		{0.0f,1.0f,0.0f},
		{0.0f,0.0f,1.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-0.24f,9.33f},{11.98f,4.89f},{11.3f,3.01f},{-0.92f,7.45f}},0.0f,12.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall
		{{{-11.98f,4.89f},{0.24f,9.33f},{0.92f,7.45f},{-11.3f,3.01f}},0.0f,12.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.013
		{{{-12.0f,-10.0f},{-12.0f,5.0f},{-10.0f,5.0f},{-10.0f,-10.0f}},0.0f,12.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.014
		{{{10.0f,-10.0f},{10.0f,5.0f},{12.0f,5.0f},{12.0f,-10.0f}},0.0f,12.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.015
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.031
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
 	{ // Lights
		{{0.0f,7.0f,0.0f}, 66.31f, {1.0f,1.0f,1.0f}},
	},
};