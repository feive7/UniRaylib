GameMap testmap = {
	{
		{0.0f,1.0f,0.0f},
		{0.0f,0.0f,1.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{
		{{{-6.0f,18.0f},{6.0f,18.0f},{6.0f,8.0f},{-6.0f,8.0f}},4.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.005
		{{{6.0f,18.0f},{18.0f,18.0f},{18.0f,8.0f},{6.0f,8.0f}},8.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.014
		{{{20.0f,18.0f},{32.0f,18.0f},{32.0f,8.0f},{20.0f,8.0f}},8.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.024
		{{{9.0f,1.0f},{11.0f,1.0f},{11.0f,-1.0f},{9.0f,-1.0f}},-1.0f,2.0f,&tex_grass,WHITE,&shader_lighting}, // grass
		{{{6.0f,-6.0f},{18.0f,-6.0f},{18.0f,-8.0f},{6.0f,-8.0f}},0.0f,10.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.013
		{{{6.0f,18.0f},{-6.0f,18.0f},{-6.0f,20.0f},{6.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.001
		{{{-6.0f,-6.0f},{6.0f,-6.0f},{6.0f,-8.0f},{-6.0f,-8.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting}, // stone.002
		{{{-6.0f,6.0f},{-6.0f,-6.0f},{-8.0f,-6.0f},{-8.0f,6.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting}, // stone.003
		{{{6.0f,8.0f},{18.0f,8.0f},{18.0f,6.0f},{6.0f,6.0f}},2.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.004
		{{{18.0f,6.0f},{18.0f,18.0f},{20.0f,18.0f},{20.0f,6.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.005
		{{{20.0f,-6.0f},{32.0f,-6.0f},{32.0f,-8.0f},{20.0f,-8.0f}},0.0f,10.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall
		{{{-6.0f,18.0f},{-6.0f,6.0f},{-8.0f,6.0f},{-8.0f,18.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting}, // stone.006
		{{{18.0f,18.0f},{6.0f,18.0f},{6.0f,20.0f},{18.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.007
		{{{20.0f,8.0f},{32.0f,8.0f},{32.0f,6.0f},{20.0f,6.0f}},5.0f,5.0f,&tex_stone,WHITE,&shader_lighting}, // stone.010
		{{{32.0f,18.0f},{20.0f,18.0f},{20.0f,20.0f},{32.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.011
		{{{32.0f,6.0f},{32.0f,18.0f},{34.0f,18.0f},{34.0f,6.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting}, // stone.012
		{{{32.0f,-6.0f},{32.0f,6.0f},{34.0f,6.0f},{34.0f,-6.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting}, // stone.013
		{{{18.0f,-6.0f},{20.0f,-6.0f},{20.0f,-8.0f},{18.0f,-8.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting}, // stone.014
		{{{-6.0f,6.0f},{-4.0f,6.0f},{-4.0f,-6.0f},{-6.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor
		{{{6.0f,6.0f},{18.0f,6.0f},{18.0f,-6.0f},{6.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.001
		{{{6.0f,18.0f},{18.0f,18.0f},{18.0f,6.0f},{6.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.002
		{{{18.0f,6.0f},{20.0f,6.0f},{20.0f,-6.0f},{18.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.003
		{{{20.0f,6.0f},{32.0f,6.0f},{32.0f,-6.0f},{20.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.004
		{{{20.0f,18.0f},{32.0f,18.0f},{32.0f,6.0f},{20.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.005
		{{{-6.0f,18.0f},{6.0f,18.0f},{6.0f,6.0f},{-6.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.006
		{{{-4.0f,6.0f},{-2.0f,6.0f},{-2.0f,-6.0f},{-4.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.007
		{{{-2.0f,6.0f},{0.0f,6.0f},{0.0f,-6.0f},{-2.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.008
		{{{0.0f,6.0f},{2.0f,6.0f},{2.0f,-6.0f},{0.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.009
		{{{2.0f,6.0f},{4.0f,6.0f},{4.0f,-6.0f},{2.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.010
		{{{4.0f,6.0f},{6.0f,6.0f},{6.0f,-6.0f},{4.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting}, // woodfloor.011
	},
	{
	},
	1.0, // Ambient lighting
 	{
	},
};