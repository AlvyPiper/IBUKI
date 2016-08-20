#pragma once

#include "sdk.h"


class cmodelinfo
{
public:
	inline const char *getmodelname(void *model) 
	{
		return getvfunc<const char *(__thiscall *)(void *, void*)>(this, 3)(this, model);
	}
	inline studiohdr_t *getstudiomodel(const void *model) 
	{
		return getvfunc<studiohdr_t *(__thiscall *)(void *, const void*)>(this, 31)(this, model);
	}
}; extern cmodelinfo *modelinfo;