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
	char buffer[PLATFORM_MAX_PATH];
	FormatEx(buffer, sizeof(buffer), "DispatchParticleEffect(%s, Vector(%f, %f, %f), Vector(%f, %f, %f))", name, origin[0], origin[1], origin[2], angles[0], angles[1], angles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

// CLASS: CBaseEntity

stock void VS_ApplyAbsVelocityImpulse(int entity, float inVecImpulse[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.ApplyAbsVelocityImpulse(Vector(%f, %f, %f))", inVecImpulse[0], inVecImpulse[1], inVecImpulse[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetAbsAngles(int entity, float absAngles[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetAbsAngles(QAngle(%f, %f, %f))", absAngles[0], absAngles[1], absAngles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetAbsVelocity(int entity, float velocity[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "self.SetAbsVelocity(Vector(%f, %f, %f))", velocity[0], velocity[1], velocity[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetAbsOrigin(int entity, float absOrigin[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetAbsOrigin(Vector(%f, %f, %f))", absOrigin[0], absOrigin[1], absOrigin[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetHealth(int entity, int amt)
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetHealth(%d)", amt);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetLocalAngles(int entity, float angles[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetLocalAngles(QAngle(%f, %f, %f))", angles[0], angles[1], angles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetMaxHealth(int entity, int amt)
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetMaxHealth(%d)", amt);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetSize(int entity, const float mins[3], const float maxs[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "self.SetSize(Vector(%f, %f, %f), Vector(%f, %f, %f))", mins[0], mins[1], mins[2], maxs[0], maxs[1], maxs[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetSolid(int entity, SolidType_t solid)
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "self.SetSolid(%d)", solid);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

// CLASS: CBaseAnimating

stock void VS_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "!self.SetModelScale(%f, %f)", scale, change_duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

// CLASS: CBasePlayer

stock void VS_SnapEyeAngles(int client, float angles[3])
{
	char buffer[PLATFORM_MAX_PATH]; FormatEx(buffer, sizeof(buffer), "self.SnapEyeAngles(QAngle(%f, %f, %f))", angles[0], angles[1], angles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(client, "RunScriptCode");
}