#if defined _stock_officerspy_tf_extra_vscript_included
	#endinput
#endif
#define _stock_officerspy_tf_extra_vscript_included

#if !defined WeaponRestrictionType_ENABLED
enum WeaponRestrictionType
{
	ANY_WEAPON		= 0,
	MELEE_ONLY		= 0x0001,
	PRIMARY_ONLY	= 0x0002,
	SECONDARY_ONLY	= 0x0004
};
#define WeaponRestrictionType_ENABLED
#endif

#if !defined AttributeType_ENABLED
enum AttributeType
{
	NONE	= 0,
	REMOVE_ON_DEATH	= (1 << 0),
	AGGRESSIVE	= (1 << 1),
	IS_NPC	= (1 << 2),
	SUPPRESS_FIRE	= (1 << 3),
	DISABLE_DODGE	= (1 << 4),
	BECOME_SPECTATOR_ON_DEATH	= (1 << 5),
	QUOTA_MANANGED	= (1 << 6),
	RETAIN_BUILDINGS	= (1 << 7),
	SPAWN_WITH_FULL_CHARGE	= (1 << 8),
	ALWAYS_CRIT	= (1 << 9),
	IGNORE_ENEMIES	= (1 << 10),
	HOLD_FIRE_UNTIL_FULL_RELOAD	= (1 << 11),
	PRIORITIZE_DEFENSE	= (1 << 12),
	ALWAYS_FIRE_WEAPON	= (1 << 13),
	TELEPORT_TO_HINT	= (1 << 14),
	MINIBOSS	= (1 << 15),
	USE_BOSS_HEALTH_BAR	= (1 << 16),
	IGNORE_FLAG	= (1 << 17),
	AUTO_JUMP	= (1 << 18),
	AIR_CHARGE_ONLY	= (1 << 19),
	PREFER_VACCINATOR_BULLETS	= (1 << 20),
	PREFER_VACCINATOR_BLAST	= (1 << 21),
	PREFER_VACCINATOR_FIRE	= (1 << 22),
	BULLET_IMMUNE	= (1 << 23),
	BLAST_IMMUNE	= (1 << 24),
	FIRE_IMMUNE	= (1 << 25),
	PARACHUTE	= (1 << 26),
	PROJECTILE_SHIELD	= (1 << 27)
};
#define AttributeType_ENABLED
#endif

#if !defined DifficultyType_ENABLED
enum DifficultyType
{
	BOTSKILL_UNDEFINED = -1,
	BOTSKILL_EASY = 0,
	BOTSKILL_NORMAL = 1,
	BOTSKILL_HARD = 2,
	BOTSKILL_EXPERT = 3,
	NUM_DIFFICULTY_LEVELS
};
#define DifficultyType_ENABLED
#endif

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