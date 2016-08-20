#pragma once

#include "ibuki.h"

enum
{
	FL_ONGROUND = (1 << 0),
	FL_DUCKING = (1 << 1),
};

enum
{
	IN_ATTACK = (1 << 0),
	IN_JUMP = (1 << 1),
	IN_DUCK = (1 << 2),
	IN_FORWARD = (1 << 3),
	IN_BACK = (1 << 4),
	IN_USE = (1 << 5),
	IN_CANCEL = (1 << 6),
	IN_LEFT = (1 << 7),
	IN_RIGHT = (1 << 8),
	IN_MOVELEFT = (1 << 9),
	IN_MOVERIGHT = (1 << 10),
	IN_ATTACK2 = (1 << 11),
	IN_RUN = (1 << 12),
	IN_RELOAD = (1 << 13),
	IN_ALT1 = (1 << 14),
	IN_ALT2 = (1 << 15),
	IN_SCORE = (1 << 16),
	IN_SPEED = (1 << 17),
	IN_WALK = (1 << 18),
	IN_ZOOM = (1 << 19),
	IN_WEAPON1 = (1 << 20),
	IN_WEAPON2 = (1 << 21),
	IN_BULLRUSH = (1 << 22)
};

enum
{
	PlayerCond_None = 0,
	PlayerCond_Slowed = (1 << 0),
	PlayerCond_Zoomed = (1 << 1),
	PlayerCond_Disguising = (1 << 2),
	PlayerCond_Disguised = (1 << 3),
	PlayerCond_Cloaked = (1 << 4),
	PlayerCond_Ubercharged = (1 << 5),
	PlayerCond_TeleportGlow = (1 << 6),
	PlayerCond_Taunting = (1 << 7),
	PlayerCond_UberchargeFade = (1 << 8),
	PlayerCond_CloakFlicker = (1 << 9),
	PlayerCond_Teleporting = (1 << 10),
	PlayerCond_Kritzkreiged = (1 << 11),
	PlayerCond_DeadRingered = (1 << 13),
	PlayerCond_Bonked = (1 << 14),
	PlayerCond_Dazed = (1 << 15),
	PlayerCond_Buffed = (1 << 16),
	PlayerCond_Charging = (1 << 17),
	PlayerCond_DemoBuff = (1 << 18),
	PlayerCond_CritCola = (1 << 19),
	PlayerCond_InHealRadius = (1 << 20),
	PlayerCond_Healing = (1 << 21),
	PlayerCond_OnFire = (1 << 22),
	PlayerCond_Overhealed = (1 << 23),
	PlayerCond_Jarated = (1 << 24),
	PlayerCond_Bleeding = (1 << 25),
	PlayerCond_DefenseBuffed = (1 << 26),
	PlayerCond_Milked = (1 << 27),
	PlayerCond_MegaHeal = (1 << 28),
	PlayerCond_RegenBuffed = (1 << 29),
	PlayerCond_MarkedForDeath = (1 << 30),
};