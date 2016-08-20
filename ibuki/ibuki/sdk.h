#pragma once

extern int tf2mshared;
extern int tf2playerclass;
extern int tf2cond;
extern int tf2classnum;
extern int tf2lifestate;
extern int tf2flags;
extern int tf2teamnum;
extern int tf2viewoffset;

#include "vector.h"
#include "color.h"
#include "ibuki.h"
#include "usercmd.h"
#include "enums.h"
#include "recvprop.h"
#include "client.h"
#include "engine.h"
#include "input.h"
#include "clientmode.h"
#include "globalvars.h"
#include "server.h"
#include "surface.h"
#include "entity.h"
#include "entlist.h"
#include "studiohdr.h"
#include "cmodelinfo.h"
#include "trace.h"

#define localplayer() (elist->getcliententity(engine->getlocalplayer()))

typedef void(__cdecl *MsgFn)(const char *, ...);
typedef void(__cdecl *WarningFn)(const char *, ...);

extern MsgFn msg;
extern WarningFn warning;