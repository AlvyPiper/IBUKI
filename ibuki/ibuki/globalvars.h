#pragma once
#include "ibuki.h"

struct cglobalvars
{
	float	realtime;
	int		framecount;
	float	absoluteframetime;
	float	curtime;
	float	frametime;
	int		maxClients;
	int		tickcount;
	float	interval_per_tick;
	float	interpolation_amount;
	int		simTicksThisFrame;
	int		network_protocol;
	char	pad00[14];
}; 
extern cglobalvars *globals;