GameMap testmap = {
	{
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{18.0f,-6.0f},{-6.0f,-6.0f},{-6.0f,6.0f},{18.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // Cube.006
		{{{5.0f,6.0f},{7.0f,6.0f},{7.0f,-6.0f},{5.0f,-6.0f}},0.0f,6.0f,&tex_mark,WHITE,&shader_lighting,0}, // Cube.007
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
	{ // Lights
		{{0.0f,5.0f,0.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{12.0f,5.0f,0.0f}, 10.0f, {1.0f,1.0f,1.0f}},
	},
};