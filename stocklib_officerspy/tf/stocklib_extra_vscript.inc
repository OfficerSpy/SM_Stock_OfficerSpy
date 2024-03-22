#if defined _stock_officerspy_extra_vscript_tf_included
	#endinput
#endif
#define _stock_officerspy_extra_vscript_tf_included

#include <stocklib_officerspy/shared/tf_shareddefs>
#include <stocklib_officerspy/tf/tf_bot>

//CTFPlayer

stock void VS_AddCustomAttribute(int client, char[] name, float value, float delay = -1.0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.AddCustomAttribute(\"%s\", %f, %f)", name, value, delay);
	
	SetVariantString(buffer);
	AcceptEntityInput(client, "RunScriptCode");
}

stock void VS_ForceChangeTeam(int client, int team, bool fullTeamSwitch = false)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.ForceChangeTeam(%d, %s)", team, fullTeamSwitch ? "true" : "false");
	
	SetVariantString(buffer);
	AcceptEntityInput(client, "RunScriptCode");
}

stock void VS_RemoveCondEx(int client, TFCond cond, bool ignoreDuration = false)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.RemoveCondEx(%d, %s)", cond, ignoreDuration ? "true" : "false");
	
	SetVariantString(buffer);
	AcceptEntityInput(client, "RunScriptCode");
}

stock void VS_Taunt(int client, int taunt_index = TAUNT_BASE_WEAPON, int taunt_concept = 0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.Taunt(%d, %d)", taunt_index, taunt_concept);
	
	SetVariantString(buffer);
	AcceptEntityInput(client, "RunScriptCode");
}

//CTFBot

stock void VS_AddBotAttribute(int tfbot, AttributeType attributeFlags)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.AddBotAttribute(%d)", attributeFlags)
	
	SetVariantString(buffer);
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_AddWeaponRestriction(int tfbot, WeaponRestrictionType restrictionFlags)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.AddWeaponRestriction(%d)", restrictionFlags)
	
	SetVariantString(buffer);
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_ClearBotAttributes(int tfbot)
{
	SetVariantString("!self.ClearAllBotAttributes()");
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_ClearWeaponRestrictions(int tfbot)
{
	SetVariantString("!self.ClearAllWeaponRestrictions()");
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_SetDifficulty(int tfbot, DifficultyType difficulty)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.SetDifficulty(%d)", difficulty);
	
	SetVariantString(buffer);
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_SetAutoJump(int tfbot, float flAutoJumpMin, float flAutoJumpMax)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.SetAutoJump(%f, %f)", flAutoJumpMin, flAutoJumpMax);
	
	SetVariantString(buffer);
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_SetMaxVisionRangeOverride(int tfbot, float range)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "!self.SetMaxVisionRangeOverride(%f)", range);

	SetVariantString(buffer);
	AcceptEntityInput(tfbot, "RunScriptCode");
}