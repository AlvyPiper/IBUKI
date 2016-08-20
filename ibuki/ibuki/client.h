#pragma once
#include "ibuki.h"

class cclient
{
public:
	inline ClientClass *getallclasses(void)
	{
		return getvfunc<ClientClass *(__thiscall *)(void *)>(this, 8)(this);
	}
};
extern cclient *client;