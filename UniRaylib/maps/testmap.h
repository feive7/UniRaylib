GameMap testmap = {
	{
		{0.0f,2.0f,0.0f},
		{-0.0f,2.0f,1.0f},
		{0.0f,2.0f,0.0f},
		{-0.0f,2.0f,1.0f},
	},
	{ // Walls
		{{{-32.0f,32.0f},{32.0f,32.0f},{32.0f,-32.0f},{-32.0f,-32.0f}},-2.0f,2.0f,&tex_checker,WHITE,&shader_lighting,0,0},
		{{{-30.0f,21.0f},{-28.0f,21.0f},{-28.0f,19.0f},{-30.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,1,0},
		{{{32.0f,32.0f},{34.0f,32.0f},{34.0f,-32.0f},{32.0f,-32.0f}},0.0f,20.0f,&tex_error,WHITE,&shader_lighting,2,4},
		{{{-34.0f,32.0f},{-32.0f,32.0f},{-32.0f,-32.0f},{-34.0f,-32.0f}},0.0f,20.0f,&tex_error,WHITE,&shader_lighting,3,4},
		{{{-32.0f,-34.0f},{-32.0f,-32.0f},{32.0f,-32.0f},{32.0f,-34.0f}},0.0f,20.0f,&tex_error,WHITE,&shader_lighting,4,4},
		{{{-32.0f,32.0f},{-32.0f,34.0f},{32.0f,34.0f},{32.0f,32.0f}},0.0f,20.0f,&tex_error,WHITE,&shader_lighting,5,4},
		{{{-27.0f,21.0f},{-25.0f,21.0f},{-25.0f,19.0f},{-27.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,6,0},
		{{{-24.0f,21.0f},{-22.0f,21.0f},{-22.0f,19.0f},{-24.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,7,0},
		{{{-21.0f,21.0f},{-19.0f,21.0f},{-19.0f,19.0f},{-21.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,8,0},
		{{{-18.0f,21.0f},{-16.0f,21.0f},{-16.0f,19.0f},{-18.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,9,0},
		{{{-15.0f,21.0f},{-13.0f,21.0f},{-13.0f,19.0f},{-15.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,10,0},
		{{{-12.0f,21.0f},{-10.0f,21.0f},{-10.0f,19.0f},{-12.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,11,0},
		{{{-8.5f,21.0f},{-7.5f,21.0f},{-7.5f,19.0f},{-8.5f,19.0f}},0.0f,4.0f,&tex_mark,WHITE,&shader_lighting,12,0},
		{{{-6.0f,21.0f},{-4.0f,21.0f},{-4.0f,19.0f},{-6.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,13,0},
		{{{-3.0f,21.0f},{-1.0f,21.0f},{-1.0f,19.0f},{-3.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,14,0},
		{{{-0.28f,20.43f},{2.28f,20.43f},{2.28f,19.57f},{-0.28f,19.57f}},1.57f,0.85f,&tex_mark,WHITE,&shader_lighting,15,0},
		{{{3.75f,21.0f},{4.25f,21.0f},{4.25f,19.0f},{3.75f,19.0f}},1.75f,0.5f,&tex_mark,WHITE,&shader_lighting,16,0},
		{{{5.73f,20.41f},{8.27f,20.41f},{8.27f,19.59f},{5.73f,19.59f}},1.22f,1.55f,&tex_mark,WHITE,&shader_lighting,17,0},
		{{{9.0f,21.0f},{11.0f,21.0f},{11.0f,19.0f},{9.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,18,0},
		{{{12.0f,21.0f},{14.0f,21.0f},{14.0f,19.0f},{12.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,19,0},
		{{{15.0f,21.0f},{17.0f,21.0f},{17.0f,19.0f},{15.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,20,0},
		{{{18.0f,21.0f},{20.0f,21.0f},{20.0f,19.0f},{18.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,21,0},
		{{{21.0f,21.0f},{23.0f,21.0f},{23.0f,19.0f},{21.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,22,0},
		{{{24.0f,21.0f},{26.0f,21.0f},{26.0f,19.0f},{24.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,23,0},
		{{{27.0f,21.0f},{29.0f,21.0f},{29.0f,19.0f},{27.0f,19.0f}},1.0f,2.0f,&tex_mark,WHITE,&shader_lighting,24,0},
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	1.0, // Ambient lighting
	{ // Lights
	},
};