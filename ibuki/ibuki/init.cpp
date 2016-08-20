/*

	Name: IBUKI
	Copyright: 2016, Alvy Piper
	Notice: This work is provided AS IS with NO WARRANTY and NO LIABILITY, any issues that are caused by my work or a derivative of my work shall NOT hold I (Alvy Piper, github.com/AlvyPiper) accountable.
	
	Feel free to redistribute, modify, and share. Please give credit where it is due, though.

*/


#include "ibuki.h"

using namespace ibuki;

cengine				*engine;
cclient				*client;
cinput				*input;
MsgFn				msg;
WarningFn			warning;
clientmodeshared	*clientmode;
cglobalvars			*globals;
cusercmd			*cmd;
centity				*entity;
celist				*elist;
cmodelinfo			*modelinfo;
cenginetrace		*etrace;

void init::dosigscan()
{
	DWORD* clienttable = (DWORD*) *(DWORD*) client;
	input = 0; //find these yourself.
	clientmode = 0;
	globals = 0;
}

void init::dointerface()
{
	client = createinterface<cclient*>("client.dll", "VClient017");
	engine = createinterface<cengine*>("engine.dll", "VEngineClient014");
	elist = createinterface<celist*>("client.dll", "VClientEntityList003");
	modelinfo = createinterface<cmodelinfo *>("engine.dll", "VModelInfoClient006");
	etrace = createinterface<cenginetrace *>("engine.dll", "EngineTraceClient003");

	init::dosigscan();
}

void init::dohook()
{
	init::dointerface();

	VMT *vmt_client = new VMT(clientmode);
	vmt_client->hook(21, hookmngr::createmove, 0);
}

void init::finalize()
{
	msg = getexport<MsgFn>("tier0.dll", "Msg");
	warning = getexport<WarningFn>("tier0.dll", "Warning");

	init::dohook();
}