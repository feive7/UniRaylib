GameMap testmap;
void InitTestMap() {
	testmap.playerstart.position = {-5.0f,1.0f,0.0f};
	testmap.playerstart.target = {1.0f,2.0f,0.0f};
	testmap.walls = {
		{{{-10.0f,10.0f},{10.0f,10.0f},{10.0f,-10.0f},{-10.0f,-10.0f}},-2.0f,2.0f,&tex_brick,WHITE,&shader_lighting},
		{{{-10.0f,12.0f},{10.0f,12.0f},{10.0f,10.0f},{-10.0f,10.0f}},0.0f,6.0f,&tex_brick,WHITE,&shader_lighting},
		{{{-12.0f,-10.0f},{-12.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting},
		{{{10.0f,-12.0f},{-10.0f,-12.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting},
		{{{12.0f,10.0f},{12.0f,-10.0f},{10.0f,-10.0f},{10.0f,10.0f}},-0.0f,6.0f,&tex_brick,WHITE,&shader_lighting},
		{{{12.0f,34.0f},{12.0f,14.0f},{10.0f,14.0f},{10.0f,34.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting},
		{{{10.0f,12.0f},{-10.0f,12.0f},{-10.0f,14.0f},{10.0f,14.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting},
		{{{-12.0f,14.0f},{-12.0f,34.0f},{-10.0f,34.0f},{-10.0f,14.0f}},-0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting},
		{{{-10.0f,36.0f},{10.0f,36.0f},{10.0f,34.0f},{-10.0f,34.0f}},0.0f,6.0f,&tex_rockwall,WHITE,&shader_lighting},
		{{{-10.0f,34.0f},{10.0f,34.0f},{10.0f,14.0f},{-10.0f,14.0f}},-2.0f,2.0f,&tex_rockwall,WHITE,&shader_lighting},
	};
	testmap.portals = {
		{{{{0.0f,-3.0f},{0.0f,3.0f},0.0f},{{-0.0f,27.0f},{0.0f,21.0f},0.0f}},6.0f},
	};
}