#if defined _stock_officerspy_extra_vscript_tf_included
	#endinput
#endif
#define _stock_officerspy_extra_vscript_tf_included

#include <stocklib_officerspy/shared/tf_shareddefs>
#include <stocklib_officerspy/tf/tf_bot>
#include <stocklib_officerspy/stocklib_extra_vscript>

// CEconEntity

stock void VS_AddAttribute(int entity, const char[] name, float value, float duration = -1.0)
{
	OSLib_RunScriptCode(entity, _, _, "self.AddAttribute(\"%s\", %f, %f)", name, value, duration);
}

stock void VS_RemoveAttribute(int entity, const char[] name)
{
	OSLib_RunScriptCode(entity, _, _, "self.RemoveAttribute(\"%s\")", name);
}

stock void VS_ReapplyProvision(int entity)
{
	SetVariantString("self.ReapplyProvision()");
	AcceptEntityInput(entity, "RunScriptCode");
}

//CTFPlayer

stock void VS_AddCustomAttribute(int client, char[] name, float value, float delay = -1.0)
{
	OSLib_RunScriptCode(client, _, _, "self.AddCustomAttribute(\"%s\", %f, %f)", name, value, delay);
}

stock void VS_ForceChangeTeam(int client, int team, bool fullTeamSwitch = false)
{
	OSLib_RunScriptCode(client, _, _, "self.ForceChangeTeam(%d, %s)", team, fullTeamSwitch ? "true" : "false");
}

stock void VS_GrantOrRemoveAllUpgrades(int client, bool bRemove, bool bRefund)
{
	OSLib_RunScriptCode(client, _, _, "self.GrantOrRemoveAllUpgrades(%s, %s)", bRemove ? "true" : "false", bRefund ? "true" : "false");
}

stock void VS_HandleTauntCommand(int client, int taunt_slot = 0)
{
	OSLib_RunScriptCode(client, _, _, "self.HandleTauntCommand(%d)", taunt_slot);
}

stock void VS_RemoveCondEx(int client, TFCond cond, bool ignoreDuration = false)
{
	OSLib_RunScriptCode(client, _, _, "self.RemoveCondEx(%d, %s)", cond, ignoreDuration ? "true" : "false");
}

stock void VS_Taunt(int client, int taunt_index = TAUNT_BASE_WEAPON, int taunt_concept = 0)
{
	OSLib_RunScriptCode(client, _, _, "self.Taunt(%d, %d)", taunt_index, taunt_concept);
}

//CTFBot

stock void VS_AddBotAttribute(int tfbot, AttributeType attributeFlags)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.AddBotAttribute(%d)", attributeFlags)
}

stock void VS_AddWeaponRestriction(int tfbot, WeaponRestrictionType restrictionFlags)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.AddWeaponRestriction(%d)", restrictionFlags)
}

stock void VS_ClearBotAttributes(int tfbot)
{
	SetVariantString("self.ClearAllBotAttributes()");
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_ClearWeaponRestrictions(int tfbot)
{
	SetVariantString("self.ClearAllWeaponRestrictions()");
	AcceptEntityInput(tfbot, "RunScriptCode");
}

stock void VS_DelayedThreatNotice(int tfbot, int threat, float delay)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.DelayedThreatNotice(EntIndexToHScript(%i), %f)", threat, delay);
}

stock void VS_PressAltFireButton(int bot, float duration = -1.0)
{
	OSLib_RunScriptCode(bot, _, _, "self.PressAltFireButton(%f)", duration);
}

stock void VS_PressFireButton(int bot, float duration = -1.0)
{
	OSLib_RunScriptCode(bot, _, _, "self.PressFireButton(%f)", duration);
}

stock void VS_PressSpecialFireButton(int bot, float duration = -1.0)
{
	OSLib_RunScriptCode(bot, _, _, "self.PressSpecialFireButton(%f)", duration);
}

stock void VS_SetDifficulty(int tfbot, DifficultyType difficulty)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.SetDifficulty(%d)", difficulty);
}

stock void VS_SetAutoJump(int tfbot, float flAutoJumpMin, float flAutoJumpMax)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.SetAutoJump(%f, %f)", flAutoJumpMin, flAutoJumpMax);
}

stock void VS_SetMaxVisionRangeOverride(int tfbot, float range)
{
	OSLib_RunScriptCode(tfbot, _, _, "self.SetMaxVisionRangeOverride(%f)", range);
}

stock void VS_UpdateDelayedThreatNotices(int tfbot)
{
	SetVariantString("self.UpdateDelayedThreatNotices()");
	AcceptEntityInput(tfbot, "RunScriptCode");
}