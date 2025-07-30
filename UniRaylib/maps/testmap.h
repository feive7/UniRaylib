GameMap testmap = {
	{
		{-0.0f,2.0f,0.0f},
		{-1.0f,2.0f,0.0f},
		{-0.0f,2.0f,0.0f},
		{-1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-18.0f,-6.0f},{6.0f,-6.0f},{6.0f,6.0f},{-18.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,{255,255,255,255},&shader_lighting,0,0,1.0f}, // Cube.006
		{{{-5.0f,6.0f},{-7.0f,6.0f},{-7.0f,-6.0f},{-5.0f,-6.0f}},0.0f,6.0f,&tex_mark,{255,255,255,255},&shader_lighting,1,0,1.0f}, // Cube.007
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
	{ // Lights
		{{-0.0f,5.0f,0.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{-12.0f,5.0f,0.0f}, 10.0f, {1.0f,1.0f,1.0f}},
	},
};