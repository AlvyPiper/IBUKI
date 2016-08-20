#pragma once
#include "ibuki.h"

class celist
{
public:
	inline centity *getcliententity(int i)
	{
		return getvfunc<centity *(__thiscall *)(void *, int)>(this, 3)(this, i);
	}
};
extern celist *elist;