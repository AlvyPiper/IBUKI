#pragma once

#include "sdk.h"

struct mstudiobbox_t //more structs ripped from styles/d3x
{
	int bone;
	int group;
	Vector min;
	Vector max;
	int unused[9];
};

struct mstudiobone_t
{
	char pad00[4];
	int parent;
	char pad01[152];
	int flags;
	char pad02[52];
};

struct mstudiohitboxset_t
{
	char pad[8];
	int hitboxindex;
	inline mstudiobbox_t* gethitbox(int index) { return (mstudiobbox_t*) ((BYTE *)this + hitboxindex) + index; }
};

struct studiohdr_t {
	char pad00[156];
	int numbones;
	int boneindex;
	inline mstudiobone_t *getbone(int i) { return (mstudiobone_t *) (((BYTE *)this) + boneindex) + i; }
	char pad01[12];
	int hitboxsetindex;
	inline mstudiobbox_t* gethitbox(int index) { return ((mstudiohitboxset_t*) ((BYTE *)this + hitboxsetindex))->gethitbox(index); }
};