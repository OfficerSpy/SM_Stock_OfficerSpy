#if defined _stock_officerspy_extra_vscript_tf_included
	#endinput
#endif
#define _stock_officerspy_extra_vscript_tf_included

#include <stocklib_officerspy/shared/tf_shareddefs>
#include <stocklib_officerspy/tf/tf_bot>

// CEconEntity

stock void VS_AddAttribute(int entity, const char[] name, float value, float duration = -1.0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.AddAttribute(\"%s\", %f, %f)", name, value, duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_RemoveAttribute(int entity, const char[] name)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.RemoveAttribute(\"%s\")", name);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_ReapplyProvision(int entity)
{
	SetVariantString("self.ReapplyProvision()");
	AcceptEntityInput(entity, "RunScriptCode");
}

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

stock void VS_PressAltFireButton(int bot, float duration = -1.0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.PressAltFireButton(%f)", duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(bot, "RunScriptCode");
}

stock void VS_PressFireButton(int bot, float duration = -1.0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.PressFireButton(%f)", duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(bot, "RunScriptCode");
}

stock void VS_PressSpecialFireButton(int bot, float duration = -1.0)
{
	char buffer[PLATFORM_MAX_PATH]; Format(buffer, sizeof(buffer), "self.PressSpecialFireButton(%f)", duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(bot, "RunScriptCode");
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