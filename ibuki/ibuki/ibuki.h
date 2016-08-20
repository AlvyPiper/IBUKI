#pragma once

/*

	Name: IBUKI
	Copyright: 2016, Alvy Piper
	Notice: This work is provided AS IS with NO WARRANTY and NO LIABILITY, any issues that are caused by my work or a derivative of my work shall NOT hold I (Alvy Piper, github.com/AlvyPiper) accountable.
	
	Feel free to redistribute, modify, and share. Please give credit where it is due, though.

*/


#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include "vmt.h"
#include "getvfunc.h"
#include "sdk.h"
#include "cheats.h"

namespace ibuki
{	
	namespace init
	{
		extern void dosigscan();
		extern void dointerface();
		extern void dohook();
		extern void finalize();
	}
	namespace hookmngr
	{
		extern bool __fastcall createmove(void*, void*, float, cusercmd*);
		extern void __fastcall painttraverse(void*, void*, unsigned int, bool, bool);
		extern void(__thiscall *org_painttraverse)(void*, unsigned int, bool, bool);
	}
	namespace util
	{
		extern bool datacompare(const char*, const char*);
		extern unsigned long findpattern(unsigned long, unsigned long, const char*);
	}
}