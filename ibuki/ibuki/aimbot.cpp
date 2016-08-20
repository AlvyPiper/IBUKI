#include "aimbot.h"

using namespace ibuki;

bool canaimat(centity *ent)
{
	if (ent->getplayercond())
	{
		if (ent->getplayercond() == PlayerCond_Ubercharged || ent->getplayercond() == PlayerCond_Bonked || ent->getplayercond() == PlayerCond_DeadRingered || ent->getplayercond() == PlayerCond_Cloaked)
			return false;
	}
	return true;
}

bool isvisible(centity *ent, Vector pos) {
	if (!ent || !localplayer())
		return false;

	ray_t ray;
	cgametrace tr;
	ctracefilter filt;
	filt.pSkip = localplayer();
	filt.pSkip2 = ent;

	ray.init(localplayer()->geteyepos(), pos);

	etrace->traceray(ray, filt, tr);

	if (tr.fraction == 1 || tr.ent == ent)
		return true;

	return false;
}

bool gethitboxply(centity *ent, int num, Vector &out) 
{
	matrix3x4 matrix[128];
	if (!ent->setupbones(matrix, 128, 0x100, 0))
		return false;

	studiohdr_t *stdhdr = modelinfo->getstudiomodel(ent->getmodel());
	if (!stdhdr)
		return false;

	mstudiobbox_t *hitbox = stdhdr->gethitbox(num);
	if (!hitbox)
		return false;

	Vector min, max;
	VectorTransform(hitbox->min, matrix[hitbox->bone], min);
	VectorTransform(hitbox->max, matrix[hitbox->bone], max);
	out = (min + max) * 0.5;

	if (isvisible(ent, out))
		return true;

	return false;
}

Vector ishitboxavailableforaiming(cusercmd *cmd)
{
	Vector output, hbox;
	float best = std::numeric_limits<float>::quiet_NaN();

	for (int i = 1; i <= engine->getmaxclients(); i++)
	{
		centity *ent = elist->getcliententity(i);
		if (!ent || ent == localplayer() || !localplayer())
			continue;

		if (ent->isdormant() || !ent->getmodel() || ent->getplayerlifestate() != 0 || ent->team() == localplayer()->team() || !gethitboxply(ent, 0, hbox) || !canaimat(ent))
			continue;

		output = hbox;
	}
	return output;
}

void aimbot::doaimbot(cusercmd *cmd)
{
	if (cmd->buttons &IN_ATTACK)
	{
		Vector hitbox = ishitboxavailableforaiming(cmd);

		if (hitbox == Vector(0, 0, 0))
			return;

		Vector eye;

		engine->getviewangles(eye);

		Vector aimpos = (hitbox - localplayer()->geteyepos()).Angle();

		Vector delta = (eye - aimpos).Angle();

		delta.NormalizeAngle();
		delta.ClampAngle();

		cmd->viewangles = eye - delta / 7 * (globals->frametime * 200);

		cmd->viewangles.NormalizeAngle();
		cmd->viewangles.ClampAngle();

		engine->setviewangles(cmd->viewangles);
	}
}