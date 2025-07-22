GameMap testmap;
void InitTestMap() {
	testmap.walls = {
		{{{12.0f,10.0f},{12.0f,-4.0f},{10.0f,-4.0f},{10.0f,10.0f}},0.0f,6.0f,&tex_concretewall,WHITE,&shader_test},
		{{{-12.0f,-10.0f},{-12.0f,4.0f},{-10.0f,4.0f},{-10.0f,-10.0f}},0.0f,6.0f,&tex_concretewall,WHITE,&shader_test},
		{{{-10.0f,12.0f},{10.0f,12.0f},{10.0f,10.0f},{-10.0f,10.0f}},0.0f,6.0f,&tex_concretewall,WHITE,&shader_test},
		{{{-10.0f,-10.0f},{10.0f,-10.0f},{10.0f,-12.0f},{-10.0f,-12.0f}},0.0f,6.0f,&tex_concretewall,WHITE,&shader_test},
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_test},
	};
	testmap.portals = {
		{{{{10.0f,-10.0f},{10.0f,-4.0f},0.0f},{{-10.0f,4.0f},{-10.0f,10.0f},0.0f}},6.0f},
	};
}