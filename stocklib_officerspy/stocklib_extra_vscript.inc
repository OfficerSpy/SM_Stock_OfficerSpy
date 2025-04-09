/* These are makeshift stocks to make use of functions exposed in VScript.
These will only work if the game in question supports VScript.
They will do nothing useful otherwise. */

#if defined _stock_officerspy_extra_vscript_included
	#endinput
#endif
#define _stock_officerspy_extra_vscript_included

#include <stocklib_officerspy/public/const>

/* Globals
Although these aren't methods of specific entity classes, you still need an entity to execute the code */

stock void VS_DispatchParticleEffect(int entity, const char[] name, float origin[3], float angles[3])
{
	OSLib_RunScriptCode(entity, _, _, "DispatchParticleEffect(%s, Vector(%f, %f, %f), Vector(%f, %f, %f))", name, origin[0], origin[1], origin[2], angles[0], angles[1], angles[2]);
}

// CLASS: CBaseEntity

stock void VS_ApplyAbsVelocityImpulse(int entity, float inVecImpulse[3])
{
	OSLib_RunScriptCode(entity, _, _, "!self.ApplyAbsVelocityImpulse(Vector(%f, %f, %f))", inVecImpulse[0], inVecImpulse[1], inVecImpulse[2]);
}

stock void VS_SetAbsAngles(int entity, float absAngles[3])
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetAbsAngles(QAngle(%f, %f, %f))", absAngles[0], absAngles[1], absAngles[2]);
}

stock void VS_SetAbsVelocity(int entity, float velocity[3])
{
	OSLib_RunScriptCode(entity, _, _, "self.SetAbsVelocity(Vector(%f, %f, %f))", velocity[0], velocity[1], velocity[2]);
}

stock void VS_SetAbsOrigin(int entity, float absOrigin[3])
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetAbsOrigin(Vector(%f, %f, %f))", absOrigin[0], absOrigin[1], absOrigin[2]);
}

stock void VS_SetHealth(int entity, int amt)
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetHealth(%d)", amt);
}

stock void VS_SetLocalAngles(int entity, float angles[3])
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetLocalAngles(QAngle(%f, %f, %f))", angles[0], angles[1], angles[2]);
}

stock void VS_SetMaxHealth(int entity, int amt)
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetMaxHealth(%d)", amt);
}

stock void VS_SetSize(int entity, const float mins[3], const float maxs[3])
{
	OSLib_RunScriptCode(entity, _, _, "self.SetSize(Vector(%f, %f, %f), Vector(%f, %f, %f))", mins[0], mins[1], mins[2], maxs[0], maxs[1], maxs[2]);
}

stock void VS_SetSolid(int entity, SolidType_t solid)
{
	OSLib_RunScriptCode(entity, _, _, "self.SetSolid(%d)", solid);
}

// CLASS: CBaseAnimating

stock void VS_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	OSLib_RunScriptCode(entity, _, _, "!self.SetModelScale(%f, %f)", scale, change_duration);
}

// CLASS: CBasePlayer

stock void VS_SnapEyeAngles(int client, float angles[3])
{
	OSLib_RunScriptCode(client, _, _, "self.SnapEyeAngles(QAngle(%f, %f, %f))", angles[0], angles[1], angles[2]);
}

stock bool OSLib_RunScriptCode(int entity, int activator = -1, int caller = -1, const char[] fmt, any ...)
{
	static char buffer[PLATFORM_MAX_PATH];
	VFormat(buffer, sizeof(buffer), fmt, 5);
	
	SetVariantString(buffer);
	
	return AcceptEntityInput(entity, "RunScriptCode", activator, caller);
}