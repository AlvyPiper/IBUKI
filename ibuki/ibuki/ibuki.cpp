/*

	Name: IBUKI
	Copyright: 2016, Alvy Piper <alvycat@protonmail.com>
	Notice: This work is provided AS IS with NO WARRANTY and NO LIABILITY, any issues that are caused by my work or a derivative of my work shall NOT hold I (Alvy Piper, github.com/AlvyPiper) accountable.
	
	Feel free to redistribute, modify, and share. Please give credit where it is due, though.

*/

#include "ibuki.h"

using namespace ibuki;

void inject()
{
	init::finalize();
}

bool __stdcall entry(HINSTANCE inst, DWORD reason, void* reserved)
{
	if (reason == 1)
	{
		DisableThreadLibraryCalls(inst);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE) inject, 0, 0, 0);
	}
	TerminateThread(inject, 0);

	return 1;
}
