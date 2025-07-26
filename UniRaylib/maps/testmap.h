GameMap testmap = {
	{
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-3.05f,10.36f},{15.74f,3.52f},{15.05f,1.64f},{-3.74f,8.48f}},0.0f,2.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall
		{{{-15.74f,3.52f},{3.05f,10.36f},{3.74f,8.48f},{-15.05f,1.64f}},0.0f,2.0f,&tex_rockwall,WHITE,&shader_lighting,0}, // rockwall.013
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