#if defined _stock_officerspy_tfbot_included
	#endinput
#endif
#define _stock_officerspy_tfbot_included

#include <stocklib_officerspy/baseentity>

stock bool CTFBot_IsLineOfFireClear(int client, const float from[3], const float to[3])
{
	Handle trace = TR_TraceRayFilterEx(from, to, MASK_SOLID_BRUSHONLY, RayType_EndPoint, TraceFilterTFBot, client);
	bool result = !TR_DidHit(trace);
	
	delete trace;
	
	return result;
}

stock bool CTFBot_IsLineOfFireClear2(int client, const float where[3])
{
	float eyePosition[3]; GetClientEyePosition(client, eyePosition);
	
	return CTFBot_IsLineOfFireClear(client, eyePosition, where);
}

stock bool CTFBot_IsLineOfFireClear3(int client, const float from[3], int who)
{
	float spaceCenter[3]; BaseEntity_WorldSpaceCenter(who, spaceCenter);
	
	Handle trace = TR_TraceRayFilterEx(from, spaceCenter, MASK_SOLID_BRUSHONLY, RayType_EndPoint, TraceFilterTFBot, client);
	bool result = !TR_DidHit(trace) || TR_GetEntityIndex(trace) == who;
	
	delete trace;
	
	return result;
}

stock bool CTFBot_IsLineOfFireClear4(int client, int who)
{
	float eyePosition[3]; GetClientEyePosition(client, eyePosition);
	
	return CTFBot_IsLineOfFireClear3(client, eyePosition, who);
}

// EXTRA UTILITY FUNCTIONS

public bool TraceFilterTFBot(int entity, int contentsMask, any data)
{
	//NextBotTraceFilterIgnoreActors
	if (IsBaseCombatCharacter(entity))
		return false;
	
	//CTraceFilterIgnoreFriendlyCombatItems
	int teamNum = GetClientTeam(data);
	if (BaseEntity_IsCombatItem(entity))
	{
		if (BaseEntity_GetTeamNumber(entity) == teamNum)
			return false;
		
		//m_bCallerIsProjectile but we don't care about it
	}
	
	//CTraceFilterChain just simply checks if both filters are true
	return true;
}