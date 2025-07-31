GameMap testmap = {
	{
		{-0.0f,2.0f,0.0f},
		{-0.0f,2.0f,-1.0f},
		{-0.0f,2.0f,0.0f},
		{-0.0f,2.0f,-1.0f},
	},
	{ // Walls
		{{{5.0f,5.0f},{-5.0f,5.0f},{-5.0f,-5.0f},{5.0f,-5.0f}},-2.0f,2.0f,&tex_checker,{255,255,255,255},&shader_lighting,0,0,1.0f}, // Cube.134
		{{{1.0f,-5.0f},{-1.0f,-5.0f},{-1.0f,-7.0f},{1.0f,-7.0f}},-2.0f,2.0f,&tex_crate_c,{255,255,255,255},&shader_lighting,1,0,1.0f}, // Cube.135
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
	{ // Lights
		{{-0.0f,5.0f,0.0f}, 0.1f, {1.0f,1.0f,1.0f}},
	},
};