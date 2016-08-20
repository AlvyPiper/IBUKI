#pragma once

#include "sdk.h"

struct ctracefilter
{
	virtual bool ShouldHitEntity(centity *ent, int)
	{
		if (ent == pSkip)
			return false;

		if (ent == pSkip2)
			return false;

		return true;
	}

	virtual int GetTraceType()
	{
		return 0;
	}

	char pad00[8];

	void *pSkip;
	void *pSkip2;
};

struct cgametrace
{
	Vector                  startpos;
	Vector                  endpos;
	Vector                  normal;
	float                   distance;
	char                    type;
	char                    signbits;
	short                   unknown;
	float                   fraction;
	int                     contents;
	unsigned short			dispflags;
	bool                    allsolid;
	bool                    startsolid;
	float                   fractionleftsolid;
	const char*             name;
	short                   surfaceprops;
	unsigned short			flags;
	int                     hitgroup;
	short                   physicsbone;
	centity*				ent;
	int                     hitbox;
};

struct ray_t
{
	void init(Vector s, Vector e)
	{
		m_Start = s;
		m_Delta = e - s;
		m_IsRay = true;
		m_IsSwept = true;
	}

	Vector m_Start; // These are vector aligned ( 16b )
	Vector m_Delta;
	Vector m_StartOffset;
	Vector m_Extents;
	const matrix3x4 *m_pWorldAxisTransform;
	bool m_IsRay;
	bool m_IsSwept;
	char pad04[4];
};

class cenginetrace
{
public:
	inline void traceray(ray_t &ray, ctracefilter &filt, cgametrace &trace)
	{
		return getvfunc<void(__thiscall *)(void *, ray_t&, unsigned int, ctracefilter&, cgametrace&)>(this, -1)(this, ray, 0x4600400B, filt, trace); //find it
	}
}; extern cenginetrace *etrace;