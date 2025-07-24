GameMap testmap = {
	{
		{-4.0f,0.0f,0.0f},
		{-4.0f,0.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{
		{{{12.0f,12.0f},{14.0f,12.0f},{14.0f,-12.0f},{12.0f,-12.0f}},0.0f,8.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.001
		{{{-12.0f,12.0f},{-12.0f,14.0f},{12.0f,14.0f},{12.0f,12.0f}},-0.0f,8.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.002
		{{{-12.0f,-12.0f},{-14.0f,-12.0f},{-14.0f,12.0f},{-12.0f,12.0f}},-0.0f,8.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall.003
		{{{-1.0f,1.0f},{1.0f,1.0f},{1.0f,-1.0f},{-1.0f,-1.0f}},0.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting}, // crate_c
		{{{12.0f,-12.0f},{12.0f,-14.0f},{-12.0f,-14.0f},{-12.0f,-12.0f}},-0.0f,8.0f,&tex_concretewall,WHITE,&shader_lighting}, // concretewall
		{{{-12.0f,12.0f},{12.0f,12.0f},{12.0f,-12.0f},{-12.0f,-12.0f}},-2.0f,2.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.006
	},
	{
	},
	{
		{{5.0f,6.0f,0.0f}, 10.0f, {1.0f,0.249f,0.107f}},
	},
};