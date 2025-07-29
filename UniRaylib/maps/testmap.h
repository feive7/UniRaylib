GameMap testmap = {
	{
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-4.0f,4.0f},{4.0f,4.0f},{4.0f,-4.0f},{-4.0f,-4.0f}},-2.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,0,0,1.0f},
		{{{-4.0f,8.0f},{4.0f,8.0f},{4.0f,4.0f},{-4.0f,4.0f}},-1.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,1,0,1.0f},
		{{{-4.0f,11.0f},{4.0f,11.0f},{4.0f,10.0f},{-4.0f,10.0f}},1.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,2,0,1.0f},
		{{{-4.0f,10.0f},{4.0f,10.0f},{4.0f,8.0f},{-4.0f,8.0f}},0.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,3,0,1.0f},
		{{{-4.0f,11.88f},{4.0f,11.88f},{4.0f,11.75f},{-4.0f,11.75f}},4.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,4,0,1.0f},
		{{{-4.0f,11.94f},{4.0f,11.94f},{4.0f,11.88f},{-4.0f,11.88f}},5.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,5,0,1.0f},
		{{{-4.0f,11.75f},{4.0f,11.75f},{4.0f,11.5f},{-4.0f,11.5f}},3.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,6,0,1.0f},
		{{{-4.0f,11.5f},{4.0f,11.5f},{4.0f,11.0f},{-4.0f,11.0f}},2.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,7,0,1.0f},
		{{{-4.0f,12.17f},{4.0f,12.17f},{4.0f,12.16f},{-4.0f,12.16f}},10.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,8,0,1.0f},
		{{{-4.0f,12.17f},{4.0f,12.17f},{4.0f,12.17f},{-4.0f,12.17f}},11.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,9,0,1.0f},
		{{{-4.0f,12.17f},{4.0f,12.17f},{4.0f,12.17f},{-4.0f,12.17f}},13.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,10,0,1.0f},
		{{{-4.0f,12.17f},{4.0f,12.17f},{4.0f,12.17f},{-4.0f,12.17f}},12.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,11,0,1.0f},
		{{{-4.0f,12.14f},{4.0f,12.14f},{4.0f,12.11f},{-4.0f,12.11f}},8.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,12,0,1.0f},
		{{{-4.0f,12.16f},{4.0f,12.16f},{4.0f,12.14f},{-4.0f,12.14f}},9.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,13,0,1.0f},
		{{{-4.0f,12.11f},{4.0f,12.11f},{4.0f,12.05f},{-4.0f,12.05f}},7.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,14,0,1.0f},
		{{{-4.0f,12.05f},{4.0f,12.05f},{4.0f,11.92f},{-4.0f,11.92f}},6.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,15,0,1.0f},
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	0.0f, // Ambient lighting
	{ // Lights
		{{0.0f,8.0f,0.0f}, 100.0f, {1.0f,1.0f,1.0f}},
	},
};