#if defined _stock_officerspy_tfbot_included
	#endinput
#endif
#define _stock_officerspy_tfbot_included

#include <stocklib_officerspy/baseentity>
#include <stocklib_officerspy/shared/tf_shareddefs>

#if !defined WeaponRestrictionType_ENABLED
enum WeaponRestrictionType
{
	CTFBot_ANY_WEAPON		= 0,
	CTFBot_MELEE_ONLY		= 0x0001,
	CTFBot_PRIMARY_ONLY	= 0x0002,
	CTFBot_SECONDARY_ONLY	= 0x0004
};
#define WeaponRestrictionType_ENABLED
#endif

#if !defined AttributeType_ENABLED
enum AttributeType
{
	CTFBot_NONE	= 0,
	CTFBot_REMOVE_ON_DEATH	= (1 << 0),
	CTFBot_AGGRESSIVE	= (1 << 1),
	CTFBot_IS_NPC	= (1 << 2),
	CTFBot_SUPPRESS_FIRE	= (1 << 3),
	CTFBot_DISABLE_DODGE	= (1 << 4),
	CTFBot_BECOME_SPECTATOR_ON_DEATH	= (1 << 5),
	CTFBot_QUOTA_MANANGED	= (1 << 6),
	CTFBot_RETAIN_BUILDINGS	= (1 << 7),
	CTFBot_SPAWN_WITH_FULL_CHARGE	= (1 << 8),
	CTFBot_ALWAYS_CRIT	= (1 << 9),
	CTFBot_IGNORE_ENEMIES	= (1 << 10),
	CTFBot_HOLD_FIRE_UNTIL_FULL_RELOAD	= (1 << 11),
	CTFBot_PRIORITIZE_DEFENSE	= (1 << 12),
	CTFBot_ALWAYS_FIRE_WEAPON	= (1 << 13),
	CTFBot_TELEPORT_TO_HINT	= (1 << 14),
	CTFBot_MINIBOSS	= (1 << 15),
	CTFBot_USE_BOSS_HEALTH_BAR	= (1 << 16),
	CTFBot_IGNORE_FLAG	= (1 << 17),
	CTFBot_AUTO_JUMP	= (1 << 18),
	CTFBot_AIR_CHARGE_ONLY	= (1 << 19),
	CTFBot_PREFER_VACCINATOR_BULLETS	= (1 << 20),
	CTFBot_PREFER_VACCINATOR_BLAST	= (1 << 21),
	CTFBot_PREFER_VACCINATOR_FIRE	= (1 << 22),
	CTFBot_BULLET_IMMUNE	= (1 << 23),
	CTFBot_BLAST_IMMUNE	= (1 << 24),
	CTFBot_FIRE_IMMUNE	= (1 << 25),
	CTFBot_PARACHUTE	= (1 << 26),
	CTFBot_PROJECTILE_SHIELD	= (1 << 27)
};
#define AttributeType_ENABLED
#endif

#if !defined DifficultyType_ENABLED
enum DifficultyType
{
	CTFBot_UNDEFINED = -1,
	CTFBot_EASY = 0,
	CTFBot_NORMAL = 1,
	CTFBot_HARD = 2,
	CTFBot_EXPERT = 3,
	CTFBot_NUM_DIFFICULTY_LEVELS
};
#define DifficultyType_ENABLED
#endif

#if !defined MissionType_ENABLED
enum //MissionType
{
	CTFBot_NO_MISSION = 0,
	CTFBot_MISSION_SEEK_AND_DESTROY,
	CTFBot_MISSION_DESTROY_SENTRIES,
	CTFBot_MISSION_SNIPER,
	CTFBot_MISSION_SPY,
	CTFBot_MISSION_ENGINEER,
	CTFBot_MISSION_REPROGRAMMED
};
#define MissionType_ENABLED
#endif

stock bool TF2_IsLineOfFireClear(int client, const float from[3], const float to[3])
{
	Handle trace = TR_TraceRayFilterEx(from, to, MASK_SOLID_BRUSHONLY, RayType_EndPoint, OSTraceFilterTFBot, client);
	bool result = !TR_DidHit(trace);
	
	delete trace;
	
	return result;
}

stock bool TF2_IsLineOfFireClear2(int client, const float where[3])
{
	float eyePosition[3]; GetClientEyePosition(client, eyePosition);
	
	return TF2_IsLineOfFireClear(client, eyePosition, where);
}

stock bool TF2_IsLineOfFireClear3(int client, const float from[3], int who)
{
	float spaceCenter[3]; BaseEntity_WorldSpaceCenter(who, spaceCenter);
	
	Handle trace = TR_TraceRayFilterEx(from, spaceCenter, MASK_SOLID_BRUSHONLY, RayType_EndPoint, OSTraceFilterTFBot, client);
	bool result = !TR_DidHit(trace) || TR_GetEntityIndex(trace) == who;
	
	delete trace;
	
	return result;
}

stock bool TF2_IsLineOfFireClear4(int client, int who)
{
	float eyePosition[3]; GetClientEyePosition(client, eyePosition);
	
	return TF2_IsLineOfFireClear3(client, eyePosition, who);
}

stock void TF2_DisguiseAsMemberOfEnemyTeam(int client)
{
	TFTeam enemyTeam = TF2_GetEnemyTeam(TF2_GetClientTeam(client));
	
	//CollectPlayers
	int total = 0;
	int[] players = new int[MaxClients];
	for (int i = 1; i <= MaxClients; i++)
		if (IsClientInGame(i) && TF2_GetClientTeam(i) == enemyTeam)
			players[total++] = i;
	
	TFClassType disguise = view_as<TFClassType>(GetRandomInt(TF_FIRST_NORMAL_CLASS, TF_LAST_NORMAL_CLASS - 1));
	
	if (total > 0)
		disguise = TF2_GetPlayerClass(players[GetRandomInt(0, total - 1)]);
	
	TF2_DisguisePlayer(client, enemyTeam, disguise);
}

// EXTRA UTILITY FUNCTIONS

static stock bool OSTraceFilterTFBot(int entity, int contentsMask, int data)
{
	//NextBotTraceFilterIgnoreActors
	if (OSLib_IsBaseCombatCharacter(entity))
		return false;
	
	//CTraceFilterIgnoreFriendlyCombatItems
	int ignoreTeam = GetClientTeam(data);
	if (BaseEntity_IsCombatItem(entity))
	{
		if (BaseEntity_GetTeamNumber(entity) == ignoreTeam)
			return false;
		
		//m_bCallerIsProjectile but we don't care about it
	}
	
	//CTraceFilterChain just simply checks if both filters are true
	return true;
}