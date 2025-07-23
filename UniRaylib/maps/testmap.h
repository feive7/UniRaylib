GameMap testmap = {
	{
		{5.0f,0.0f,0.0f},
		{5.0f,0.0f,0.0f},
		{35.256f,34.894f,13.388f},
		{34.562f,34.175f,13.379f},
	},
	{
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_brick,WHITE,&shader_lighting}, // brick.001
		{{{-10.0f,12.0f},{10.0f,12.0f},{10.0f,10.0f},{-10.0f,10.0f}},0.0f,6.0f,&tex_brick,WHITE,&shader_lighting}, // brick.002
		{{{-12.0f,-10.0f},{-12.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting}, // brick.003
		{{{10.0f,-12.0f},{-10.0f,-12.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting}, // brick.004
		{{{12.0f,10.0f},{12.0f,-10.0f},{10.0f,-10.0f},{10.0f,10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting}, // brick.005
		{{{12.0f,34.0f},{12.0f,14.0f},{10.0f,14.0f},{10.0f,34.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.007
		{{{10.0f,12.0f},{-10.0f,12.0f},{-10.0f,14.0f},{10.0f,14.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.008
		{{{-12.0f,14.0f},{-12.0f,34.0f},{-10.0f,34.0f},{-10.0f,14.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.009
		{{{-10.0f,36.0f},{10.0f,36.0f},{10.0f,34.0f},{-10.0f,34.0f}},0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.010
		{{{-10.0f,34.0f},{10.0f,34.0f},{10.0f,14.0f},{-10.0f,14.0f}},-2.0f,2.0f,&tex_rockwall,WHITE,&shader_lighting}, // rockwall.011
	},
	{
		{{{{0.0f,-3.0f},{0.0f,3.0f},0.0f},{{-0.0f,27.0f},{0.0f,21.0f},0.0f}},6.0f},
	},
};