GameMap testmap = {
	{
		{0.0f,1.0f,0.0f},
		{0.0f,0.0f,1.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.025
		{{{7.04f,-9.69f},{-7.04f,-9.69f},{-5.87f,-8.08f},{5.87f,-8.08f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.026
		{{{-7.04f,-9.69f},{-11.4f,3.7f},{-9.49f,3.08f},{-5.87f,-8.08f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.027
		{{{-11.4f,3.7f},{-0.0f,12.0f},{-0.0f,10.0f},{-9.49f,3.08f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.028
		{{{-0.0f,12.0f},{11.39f,3.7f},{9.49f,3.08f},{-0.0f,10.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.029
		{{{11.39f,3.7f},{7.04f,-9.69f},{5.87f,-8.08f},{9.49f,3.08f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.030
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
 	{ // Lights
		{{0.0f,8.0f,0.0f}, 28.41f, {1.0f,1.0f,1.0f}},
	},
};