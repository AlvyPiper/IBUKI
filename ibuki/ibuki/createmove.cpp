#include "ibuki.h"

using namespace ibuki;

bool __fastcall hookmngr::createmove(void* thishook, void*, float frametime, cusercmd* cmd)
{
	if (cmd->command_number == 0)
		return 0;

	aimbot::doaimbot(cmd);

	return 0;
}