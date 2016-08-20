#pragma once

#include "sdk.h"

class centity
{
public:
	inline int flags()
	{
		return readptr<int>(this, tf2flags);
	}
	inline int team()
	{
		return readptr<int>(this, tf2teamnum);
	}
	inline int getshared()
	{
		return readptr<int>(this, tf2mshared);
	}
	inline int getclassnum()
	{
		return readptr<int>(this, tf2playerclass + tf2classnum); //m_PlayerClass + m_iClass
	}
	inline int getplayercond()
	{
		return readptr<int>(this, tf2mshared + tf2cond);
	}
	inline bool isdormant()
	{
		return getvfunc<bool(__thiscall *)(void *)>((this + 0x8), 9)((this + 0x8));
	}
	inline bool setupbones(matrix3x4 *matrix, int bones, int mask, float time)
	{
		return getvfunc<bool(__thiscall *)(void *, matrix3x4 *, int, int, float)>((this + 0x4), 14)((this + 0x4), matrix, bones, mask, time);
	}
	inline void *getmodel()
	{
		return getvfunc<void *(__thiscall *)(void *)>((this + 0x4), 8)((this + 0x4));
	}
	inline Vector getvecviewoffset()
	{
		return readptr<Vector>(this, tf2viewoffset);
	}
	inline unsigned char getplayerlifestate()
	{
		return readptr<unsigned char>(this, tf2lifestate);
	}
	inline Vector& getabsorigin()
	{
		return getvfunc<Vector&(__thiscall *)(void *)>(this, 10)(this);
	}
	inline Vector geteyepos()
	{
		return getabsorigin() + getvecviewoffset();
	}
}; 
extern centity *ent;