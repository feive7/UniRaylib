GameMap testmap = {
	{
		{5.0f,1.0f,0.0f},
		{4.0f,1.0f,0.0f},
		{5.0f,1.0f,0.0f},
		{4.0f,1.0f,0.0f},
	},
	{ // Walls
		{{{-10.0f,12.0f},{10.0f,12.0f},{10.0f,10.0f},{-10.0f,10.0f}},0.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting,0,0,1.0f},
		{{{-12.0f,-10.0f},{-12.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f}},-0.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting,1,0,1.0f},
		{{{10.0f,-12.0f},{-10.0f,-12.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},-0.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting,2,0,1.0f},
		{{{12.0f,10.0f},{12.0f,-10.0f},{10.0f,-10.0f},{10.0f,10.0f}},-0.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting,3,0,1.0f},
		{{{1.0f,30.0f},{1.0f,28.0f},{-1.0f,28.0f},{-1.0f,30.0f}},2.0f,2.0f,&tex_scifi_floortile,WHITE,&shader_lighting,4,0,1.0f},
		{{{-6.0f,1.0f},{-4.0f,1.0f},{-4.0f,-1.0f},{-6.0f,-1.0f}},2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,5,0,1.0f},
		{{{-10.0f,34.0f},{10.0f,34.0f},{10.0f,14.0f},{-10.0f,14.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,6,0,4.0f},
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_carpet,WHITE,&shader_lighting,7,0,4.0f},
		{{{12.0f,34.0f},{12.0f,14.0f},{10.0f,14.0f},{10.0f,34.0f}},-0.0f,6.0f,&tex_wooddoor,WHITE,&shader_lighting,8,0,1.0f},
		{{{10.0f,12.0f},{-10.0f,12.0f},{-10.0f,14.0f},{10.0f,14.0f}},-0.0f,6.0f,&tex_wooddoor,WHITE,&shader_lighting,9,0,1.0f},
		{{{-12.0f,14.0f},{-12.0f,34.0f},{-10.0f,34.0f},{-10.0f,14.0f}},-0.0f,6.0f,&tex_wooddoor,WHITE,&shader_lighting,10,0,1.0f},
		{{{-10.0f,36.0f},{10.0f,36.0f},{10.0f,34.0f},{-10.0f,34.0f}},0.0f,6.0f,&tex_wooddoor,WHITE,&shader_lighting,11,0,1.0f},
	},
	{ // Signs (WIP)
	},
	{ // Portals
		{{{{0.0f,-3.0f},{0.0f,3.0f},0.0f},{{-3.0f,24.0f},{3.0f,24.0f},-0.0f}},6.0f},
	},
	0.0f, // Ambient lighting
	{ // Lights
		{{-8.0f,4.0f,-8.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{8.0f,4.0f,-8.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{-8.0f,4.0f,8.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{-8.0f,4.0f,32.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{8.0f,4.0f,32.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{8.0f,4.0f,16.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{-8.0f,4.0f,16.0f}, 10.0f, {1.0f,1.0f,1.0f}},
		{{8.0f,4.0f,8.0f}, 10.0f, {1.0f,1.0f,1.0f}},
	},
};