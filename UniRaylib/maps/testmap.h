GameMap testmap = {
	{
		{0.0f,1.0f,0.0f},
		{0.0f,0.0f,1.0f},
		{0.0f,2.0f,0.0f},
		{1.0f,2.0f,0.0f},
	},
	{ // Walls
		{{{-6.0f,18.0f},{6.0f,18.0f},{6.0f,8.0f},{-6.0f,8.0f}},4.0f,6.0f,&tex_concretewall,WHITE,&shader_lighting,0}, // concretewall.005
		{{{-6.0f,-42.0f},{6.0f,-42.0f},{6.0f,-52.0f},{-6.0f,-52.0f}},-14.0f,12.0f,&tex_concretewall,WHITE,&shader_lighting,0}, // concretewall.007
		{{{-6.0f,-8.0f},{6.0f,-8.0f},{6.0f,-18.0f},{-6.0f,-18.0f}},-14.0f,12.0f,&tex_concretewall,WHITE,&shader_lighting,0}, // concretewall.008
		{{{6.0f,18.0f},{18.0f,18.0f},{18.0f,8.0f},{6.0f,8.0f}},8.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,0}, // concretewall.014
		{{{20.0f,18.0f},{32.0f,18.0f},{32.0f,8.0f},{20.0f,8.0f}},8.0f,2.0f,&tex_concretewall,WHITE,&shader_lighting,0}, // concretewall.024
		{{{19.5f,-2.0f},{20.5f,-2.0f},{20.5f,-6.0f},{19.5f,-6.0f}},-1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.023
		{{{20.5f,-2.0f},{21.5f,-2.0f},{21.5f,-6.0f},{20.5f,-6.0f}},0.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.024
		{{{21.5f,-2.0f},{22.5f,-2.0f},{22.5f,-6.0f},{21.5f,-6.0f}},1.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.025
		{{{22.5f,-2.0f},{23.5f,-2.0f},{23.5f,-6.0f},{22.5f,-6.0f}},2.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.026
		{{{23.5f,-2.0f},{24.5f,-2.0f},{24.5f,-6.0f},{23.5f,-6.0f}},3.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.027
		{{{24.5f,-2.0f},{25.5f,-2.0f},{25.5f,-6.0f},{24.5f,-6.0f}},4.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.028
		{{{25.5f,-2.0f},{26.5f,-2.0f},{26.5f,-6.0f},{25.5f,-6.0f}},5.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.029
		{{{26.5f,-2.0f},{27.5f,-2.0f},{27.5f,-6.0f},{26.5f,-6.0f}},6.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.030
		{{{27.5f,-2.0f},{28.5f,-2.0f},{28.5f,-6.0f},{27.5f,-6.0f}},7.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.031
		{{{28.5f,-2.0f},{29.5f,-2.0f},{29.5f,-6.0f},{28.5f,-6.0f}},8.0f,2.0f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c.032
		{{{6.0f,18.0f},{-6.0f,18.0f},{-6.0f,20.0f},{6.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.001
		{{{-6.0f,6.0f},{-6.0f,-6.0f},{-8.0f,-6.0f},{-8.0f,6.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.003
		{{{6.0f,8.0f},{18.0f,8.0f},{18.0f,6.0f},{6.0f,6.0f}},2.5f,7.5f,&tex_stone,WHITE,&shader_lighting,0}, // stone.004
		{{{18.0f,6.0f},{18.0f,18.0f},{20.0f,18.0f},{20.0f,6.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.005
		{{{20.0f,-6.0f},{32.0f,-6.0f},{32.0f,-8.0f},{20.0f,-8.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone
		{{{-6.0f,18.0f},{-6.0f,6.0f},{-8.0f,6.0f},{-8.0f,18.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.006
		{{{18.0f,18.0f},{6.0f,18.0f},{6.0f,20.0f},{18.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.007
		{{{6.0f,-6.0f},{18.0f,-6.0f},{18.0f,-8.0f},{6.0f,-8.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.008
		{{{-6.0f,-6.0f},{-6.0f,-18.0f},{-8.0f,-18.0f},{-8.0f,-6.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.009
		{{{20.0f,8.0f},{32.0f,8.0f},{32.0f,6.0f},{20.0f,6.0f}},5.0f,5.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.010
		{{{32.0f,18.0f},{20.0f,18.0f},{20.0f,20.0f},{32.0f,20.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.011
		{{{32.0f,6.0f},{32.0f,18.0f},{34.0f,18.0f},{34.0f,6.0f}},0.0f,8.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.012
		{{{32.0f,-6.0f},{32.0f,6.0f},{34.0f,6.0f},{34.0f,-6.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.013
		{{{18.0f,-6.0f},{20.0f,-6.0f},{20.0f,-8.0f},{18.0f,-8.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.014
		{{{8.0f,-8.0f},{8.0f,-18.0f},{6.0f,-18.0f},{6.0f,-8.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.015
		{{{-6.0f,-18.0f},{-6.0f,-42.0f},{-8.0f,-42.0f},{-8.0f,-18.0f}},-14.0f,24.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.016
		{{{8.0f,-18.0f},{8.0f,-42.0f},{6.0f,-42.0f},{6.0f,-18.0f}},-14.0f,24.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.017
		{{{-6.0f,-42.0f},{-6.0f,-54.0f},{-8.0f,-54.0f},{-8.0f,-42.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.018
		{{{18.0f,-56.0f},{6.0f,-56.0f},{6.0f,-54.0f},{18.0f,-54.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.019
		{{{6.0f,-56.0f},{-6.0f,-56.0f},{-6.0f,-54.0f},{6.0f,-54.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.020
		{{{30.0f,-56.0f},{18.0f,-56.0f},{18.0f,-54.0f},{30.0f,-54.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.021
		{{{30.0f,-42.0f},{18.0f,-42.0f},{18.0f,-40.0f},{30.0f,-40.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.022
		{{{18.0f,-42.0f},{8.0f,-42.0f},{8.0f,-40.0f},{18.0f,-40.0f}},0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.023
		{{{32.0f,-42.0f},{32.0f,-54.0f},{30.0f,-54.0f},{30.0f,-42.0f}},-0.0f,10.0f,&tex_stone,WHITE,&shader_lighting,0}, // stone.024
		{{{4.0f,-18.0f},{6.0f,-18.0f},{6.0f,-18.5f},{4.0f,-18.5f}},-12.0f,12.0f,&tex_wooddoor,WHITE,&shader_lighting,1}, // wooddoor.001
		{{{-6.0f,6.0f},{-4.0f,6.0f},{-4.0f,-6.0f},{-6.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor
		{{{6.0f,6.0f},{18.0f,6.0f},{18.0f,-6.0f},{6.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.001
		{{{6.0f,18.0f},{18.0f,18.0f},{18.0f,6.0f},{6.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.002
		{{{18.0f,6.0f},{20.0f,6.0f},{20.0f,-6.0f},{18.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.003
		{{{20.0f,6.0f},{32.0f,6.0f},{32.0f,-6.0f},{20.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.004
		{{{20.0f,18.0f},{32.0f,18.0f},{32.0f,6.0f},{20.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.005
		{{{-6.0f,18.0f},{6.0f,18.0f},{6.0f,6.0f},{-6.0f,6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.006
		{{{-4.0f,6.0f},{-2.0f,6.0f},{-2.0f,-6.0f},{-4.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.007
		{{{-2.0f,6.0f},{0.0f,6.0f},{0.0f,-6.0f},{-2.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.008
		{{{0.0f,6.0f},{2.0f,6.0f},{2.0f,-6.0f},{0.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.009
		{{{2.0f,6.0f},{4.0f,6.0f},{4.0f,-6.0f},{2.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.010
		{{{4.0f,6.0f},{6.0f,6.0f},{6.0f,-6.0f},{4.0f,-6.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.011
		{{{-6.0f,-6.0f},{6.0f,-6.0f},{6.0f,-18.0f},{-6.0f,-18.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.012
		{{{-6.0f,-18.0f},{6.0f,-18.0f},{6.0f,-30.0f},{-6.0f,-30.0f}},-14.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.013
		{{{-6.0f,-30.0f},{6.0f,-30.0f},{6.0f,-42.0f},{-6.0f,-42.0f}},-14.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.014
		{{{-6.0f,-42.0f},{6.0f,-42.0f},{6.0f,-54.0f},{-6.0f,-54.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.015
		{{{6.0f,-42.0f},{18.0f,-42.0f},{18.0f,-54.0f},{6.0f,-54.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.016
		{{{18.0f,-42.0f},{30.0f,-42.0f},{30.0f,-54.0f},{18.0f,-54.0f}},-2.0f,2.0f,&tex_woodfloor,WHITE,&shader_lighting,0}, // woodfloor.017
		{{{-0.25f,-18.0f},{0.25f,-18.0f},{0.25f,-42.0f},{-0.25f,-42.0f}},-0.5f,0.5f,&tex_crate_c,WHITE,&shader_lighting,0}, // crate_c
	},
	{ // Signs (WIP)
	},
	{ // Portals
	},
	1.0, // Ambient lighting
 	{ // Lights
	},
};