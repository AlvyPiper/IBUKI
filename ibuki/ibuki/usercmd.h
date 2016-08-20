#pragma once
#include "sdk.h"

struct cusercmd
{
	char	pad00[4];
	int		command_number;
	int		tick_count;
	Vector	viewangles;
	Vector	move;
	int		buttons;
	char	impulse;
	int		weaponselect;
	int		weaponsubtype;
	int		random_seed;
	short	mousedx;
	short	mousedy;
	bool	hasbeenpredicted;
};