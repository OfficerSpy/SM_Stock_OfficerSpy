#if defined _stock_officerspy_teamobjectiveresource_included
	#endinput
#endif
#define _stock_officerspy_teamobjectiveresource_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/baseentity>

//#define TEAM_ARRAY( index, team )		(index + (team * MAX_CONTROL_POINTS))
#define TEAM_ARRAY(%0, %1)	(%0 + (%1 * MAX_CONTROL_POINTS))

#define CAPHUD_PARITY_BITS		6
#define CAPHUD_PARITY_MASK		((1 << CAPHUD_PARITY_BITS) - 1)

#define LAZY_UPDATE_TIME		3

methodmap OSBaseTeamObjectiveResource < OSBaseEntity
{
	public OSBaseTeamObjectiveResource(int index)
	{
		return view_as<OSBaseTeamObjectiveResource>(index);
	}
}

stock void BaseTeamObjectiveResource_ResetControlPoints(int entity)
{
	for (int i = 0; i < MAX_CONTROL_POINTS; i++)
	{
		SetEntProp(entity, Prop_Send, "m_iCappingTeam", TEAM_UNASSIGNED, _, i);
		SetEntProp(entity, Prop_Send, "m_iTeamInZone", TEAM_UNASSIGNED, _, i);
		SetEntProp(entity, Prop_Send, "m_bInMiniRound", true, _, i);
		
		for (int team = 0; team < MAX_CONTROL_POINT_TEAMS; team++)
			SetEntProp(entity, Prop_Send, "m_iNumTeamMembers", 0.0, _, TEAM_ARRAY(i, team));
	}
	
	BaseTeamObjectiveResource_UpdateCapHudElement(entity);
	SetEntProp(entity, Prop_Send, "m_bControlPointsReset", !GetEntProp(entity, Prop_Send, "m_bControlPointsReset"));
}

stock void BaseTeamObjectiveResource_SetNumControlPoints(int entity, int num)
{
	SetEntProp(entity, Prop_Send, "m_iNumControlPoints", num);
}

stock int BaseTeamObjectiveResource_GetNumControlPoints(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iNumControlPoints");
}

stock void BaseTeamObjectiveResource_SetCPIcons(int entity, int index, int iTeam, int iIcon)
{
	SetEntProp(entity, Prop_Send, "m_iTeamIcons", iIcon, _, TEAM_ARRAY(index, iTeam));
}

stock void BaseTeamObjectiveResource_SetCPOverlays(int entity, int index, int iTeam, int iIcon)
{
	SetEntProp(entity, Prop_Send, "m_iTeamOverlays", iIcon, _, TEAM_ARRAY(index, iTeam));
}

stock void BaseTeamObjectiveResource_SetTeamBaseIcons(int entity, int iTeam, int iBaseIcon)
{
	SetEntProp(entity, Prop_Send, "m_iTeamBaseIcons", iBaseIcon, _, iTeam);
}

stock void BaseTeamObjectiveResource_SetCPPosition(int entity, int index, const float vPosition[3])
{
	SetEntPropVector(entity, Prop_Send, "m_vCPPositions", vPosition, index);
}

stock void BaseTeamObjectiveResource_SetCPVisible(int entity, int index, bool bVisible)
{
	SetEntProp(entity, Prop_Send, "m_bCPIsVisible", bVisible, _, index);
}

stock void BaseTeamObjectiveResource_SetCPRequiredCappers(int entity, int index, int iTeam, int iReqPlayers)
{
	SetEntProp(entity, Prop_Send, "m_iTeamReqCappers", iReqPlayers, _, TEAM_ARRAY(index, iTeam));
}

stock void BaseTeamObjectiveResource_SetCPCapTime(int entity, int index, int iTeam, float flTime)
{
	SetEntPropFloat(entity, Prop_Send, "m_flTeamCapTime", flTime, TEAM_ARRAY(index, iTeam));
}

stock void BaseTeamObjectiveResource_SetCPCapPercentage(int entity, int index, float flTime)
{
	SetEntPropFloat(entity, Prop_Data, "m_flCapPercentages", flTime, index);
}

stock float BaseTeamObjectiveResource_GetCPCapPercentage(int entity, int index)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flCapPercentages", index);
}

stock void BaseTeamObjectiveResource_SetTeamCanCap(int entity, int index, int iTeam, bool bCanCap)
{
	SetEntProp(entity, Prop_Send, "m_bTeamCanCap", bCanCap, _, TEAM_ARRAY(index, iTeam));
	BaseTeamObjectiveResource_UpdateCapHudElement(entity);
}

stock void BaseTeamObjectiveResource_SetBaseCP(int entity, int index, int iTeam)
{
	SetEntProp(entity, Prop_Send, "m_iBaseControlPoints", index, _, iTeam);
}

stock void BaseTeamObjectiveResource_SetPreviousPoint(int entity, int index, int iTeam, int iPrevIndex, int iPrevPoint)
{
	int iIntIndex = iPrevIndex + (index * MAX_PREVIOUS_POINTS) + (iTeam * MAX_CONTROL_POINTS * MAX_PREVIOUS_POINTS);
	SetEntProp(entity, Prop_Send, "m_iPreviousPoints", iPrevPoint, _, iIntIndex);
}

stock int BaseTeamObjectiveResource_GetPreviousPointForPoint(int entity, int index, int team, int iPrevIndex)
{
	int iIntIndex = iPrevIndex + (index * MAX_PREVIOUS_POINTS) + (team * MAX_CONTROL_POINTS * MAX_PREVIOUS_POINTS);
	return GetEntProp(entity, Prop_Send, "m_iPreviousPoints", _, iIntIndex);
}

stock bool BaseTeamObjectiveResource_TeamCanCapPoint(int entity, int index, int team)
{
	return GetEntProp(entity, Prop_Send, "m_bTeamCanCap", _, TEAM_ARRAY(index, team));
}

stock void BaseTeamObjectiveResource_SetCapLayoutInHUD(int entity, const char[] pszLayout)
{
	SetEntPropString(entity, Prop_Send, "m_pszCapLayoutInHUD", pszLayout);
}

stock void BaseTeamObjectiveResource_SetCapLayoutCustomPosition(int entity, float flPositionX, float flPositionY)
{
	SetEntPropFloat(entity, Prop_Send, "m_flCustomPositionX", flPositionX);
	SetEntPropFloat(entity, Prop_Send, "m_flCustomPositionY", flPositionY);
}

stock void BaseTeamObjectiveResource_SetWarnOnCap(int entity, int index, int iWarnLevel)
{
	SetEntProp(entity, Prop_Send, "m_iWarnOnCap", iWarnLevel, _, index);
}

stock void BaseTeamObjectiveResource_SetWarnSound(int entity, int index, const char[] iszSound)
{
	SetEntPropString(entity, Prop_Send, "m_iszWarnSound", iszSound, index);
}

stock void BaseTeamObjectiveResource_SetCPGroup(int entity, int index, int iCPGroup)
{
	SetEntProp(entity, Prop_Send, "m_iCPGroup", iCPGroup, _, index);
}

stock void BaseTeamObjectiveResource_SetCPLocked(int entity, int index, bool bLocked)
{
	SetEntProp(entity, Prop_Send, "m_bCPLocked", bLocked, _, index);
}

stock void BaseTeamObjectiveResource_SetTrackAlarm(int entity, int index, bool bAlarm)
{
	SetEntProp(entity, Prop_Send, "m_bTrackAlarm", bAlarm, _, index);
}

stock void BaseTeamObjectiveResource_SetCPUnlockTime(int entity, int index, float flTime)
{
	SetEntPropFloat(entity, Prop_Send, "m_flUnlockTimes", flTime, index);
}

stock void BaseTeamObjectiveResource_SetCPTimerTime(int entity, int index, float flTime)
{
	SetEntPropFloat(entity, Prop_Send, "m_flCPTimerTimes", flTime, index);
}

stock void BaseTeamObjectiveResource_SetCPCapTimeScalesWithPlayers(int entity, int index, bool bScales)
{
	SetEntProp(entity, Prop_Send, "m_bCPCapRateScalesWithPlayers", bScales, _, index);
}

stock void BaseTeamObjectiveResource_SetNumPlayers(int entity, int index, int team, int iNumPlayers)
{
	SetEntProp(entity, Prop_Send, "m_iNumTeamMembers", iNumPlayers, _, TEAM_ARRAY(index, team));
	BaseTeamObjectiveResource_UpdateCapHudElement(entity);
}

stock void BaseTeamObjectiveResource_StartCap(int entity, int index, int team)
{
	if (GetEntProp(entity, Prop_Send, "m_iCappingTeam", _, index) != team)
	{
		SetEntProp(entity, Prop_Send, "m_iCappingTeam", team, _, index);
		BaseTeamObjectiveResource_UpdateCapHudElement(entity);
	}
}

stock void BaseTeamObjectiveResource_SetOwningTeam(int entity, int index, int team)
{
	SetEntProp(entity, Prop_Send, "m_iOwner", team, _, index);
	SetEntProp(entity, Prop_Send, "m_iCappingTeam", TEAM_UNASSIGNED, _, index);
	BaseTeamObjectiveResource_UpdateCapHudElement(entity);
}

stock void BaseTeamObjectiveResource_SetCappingTeam(int entity, int index, int team)
{
	if (GetEntProp(entity, Prop_Send, "m_iCappingTeam", _, index) != team)
	{
		SetEntProp(entity, Prop_Send, "m_iCappingTeam", team, _, index);
		BaseTeamObjectiveResource_UpdateCapHudElement(entity);
	}
}

stock void BaseTeamObjectiveResource_SetTeamInZone(int entity, int index, int team)
{
	if (GetEntProp(entity, Prop_Send, "m_iTeamInZone", _, index) != team)
	{
		SetEntProp(entity, Prop_Send, "m_iTeamInZone", team, _, index);
		BaseTeamObjectiveResource_UpdateCapHudElement(entity);
	}
}

stock void BaseTeamObjectiveResource_SetCapBlocked(int entity, int index, bool bBlocked)
{
	if (view_as<bool>(GetEntProp(entity, Prop_Send, "m_bBlocked", _, index)) != bBlocked)
	{
		SetEntProp(entity, Prop_Send, "m_bBlocked", bBlocked, _, index);
		BaseTeamObjectiveResource_UpdateCapHudElement(entity);
	}
}

stock int BaseTeamObjectiveResource_GetOwningTeam(int entity, int index)
{
	if (index >= GetEntProp(entity, Prop_Send, "m_iNumControlPoints"))
		return TEAM_UNASSIGNED;
	
	return GetEntProp(entity, Prop_Send, "m_iOwner", _, index);
}

stock int BaseTeamObjectiveResource_GetBaseControlPointForTeam(int entity, int iTeam)
{
	return GetEntProp(entity, Prop_Send, "m_iBaseControlPoints", _, iTeam);
}

stock int BaseTeamObjectiveResource_GetCappingTeam(int entity, int index)
{
	if (index >= GetEntProp(entity, Prop_Send, "m_iNumControlPoints"))
		return TEAM_UNASSIGNED;
	
	return GetEntProp(entity, Prop_Send, "m_iCappingTeam", _, index);
}

stock void BaseTeamObjectiveResource_SetTimerInHUD(int entity, int pTimer)
{
	SetEntProp(entity, Prop_Send, "m_iTimerToShowInHUD", IsValidEntity(pTimer) ? pTimer : 0);
}

stock void BaseTeamObjectiveResource_SetStopWatchTimer(int entity, int pTimer)
{
	SetEntProp(entity, Prop_Send, "m_iStopWatchTimer", IsValidEntity(pTimer) ? pTimer : 0);
}

stock int BaseTeamObjectiveResource_GetStopWatchTimer(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iStopWatchTimer");
}

stock int BaseTeamObjectiveResource_GetTimerToShowInHUD(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iTimerToShowInHUD");
}

stock void BaseTeamObjectiveResource_SetPlayingMiniRounds(int entity, bool bPlayingMiniRounds)
{
	SetEntProp(entity, Prop_Send, "m_bPlayingMiniRounds", bPlayingMiniRounds);
}

stock bool BaseTeamObjectiveResource_PlayingMiniRounds(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_bPlayingMiniRounds");
}

stock void BaseTeamObjectiveResource_SetInMiniRound(int entity, int index, bool bInRound)
{
	SetEntProp(entity, Prop_Send, "m_bInMiniRound", bInRound, _, index);
}

stock bool BaseTeamObjectiveResource_IsInMiniRound(int entity, int index)
{
	return GetEntProp(entity, Prop_Send, "m_bInMiniRound", _, index);
}

stock void BaseTeamObjectiveResource_UpdateCapHudElement(int entity)
{
	SetEntProp(entity, Prop_Send, "m_iUpdateCapHudParity", (GetEntProp(entity, Prop_Send, "m_iUpdateCapHudParity") + 1) & CAPHUD_PARITY_MASK);
}

stock void BaseTeamObjectiveResource_SetTrainPathDistance(int entity, int index, float flDistance)
{
	SetEntPropFloat(entity, Prop_Send, "m_flPathDistance", flDistance, index);
}

stock bool BaseTeamObjectiveResource_GetCPLocked(int entity, int index)
{
	return GetEntProp(entity, Prop_Send, "m_bCPLocked", _, index);
}

stock void BaseTeamObjectiveResource_ResetHillData(int entity, int team)
{
	if (team < TEAM_TRAIN_MAX_TEAMS)
	{
		SetEntProp(entity, Prop_Send, "m_nNumNodeHillData", 0, _, team);
		
		int nNumEntriesPerTeam = TEAM_TRAIN_MAX_HILLS * TEAM_TRAIN_FLOATS_PER_HILL;
		int iStartingIndex = team * nNumEntriesPerTeam;
		
		for (int i = 0; i < nNumEntriesPerTeam; i++)
			SetEntProp(entity, Prop_Send, "m_flNodeHillData", 0, _, iStartingIndex + i);
		
		iStartingIndex = team * TEAM_TRAIN_MAX_HILLS;
		
		for (int i = 0; i < TEAM_TRAIN_MAX_HILLS; i++)
			SetEntProp(entity, Prop_Send, "m_bHillIsDownhill", 0, _, iStartingIndex + i);
	}
}

stock void BaseTeamObjectiveResource_SetHillData(int entity, int team, float flStart, float flEnd, bool bDownhill)
{
	if (team < TEAM_TRAIN_MAX_TEAMS)
	{
		int index = (GetEntProp(entity, Prop_Send, "m_nNumNodeHillData", _, team) * TEAM_TRAIN_FLOATS_PER_HILL) + (team * TEAM_TRAIN_MAX_HILLS * TEAM_TRAIN_FLOATS_PER_HILL);
		
		if (index < TEAM_TRAIN_HILLS_ARRAY_SIZE - 1)
		{
			SetEntPropFloat(entity, Prop_Send, "m_flNodeHillData", flStart, index);
			SetEntPropFloat(entity, Prop_Send, "m_flNodeHillData", flEnd, index + 1);
			
			if (GetEntProp(entity, Prop_Send, "m_nNumNodeHillData", _, team) < TEAM_TRAIN_MAX_HILLS)
				SetEntProp(entity, Prop_Send, "m_bHillIsDownhill", bDownhill, _, GetEntProp(entity, Prop_Send, "m_nNumNodeHillData", _, team) + (team * TEAM_TRAIN_MAX_HILLS));
			
			SetEntProp(entity, Prop_Send, "m_nNumNodeHillData", GetEntProp(entity, Prop_Send, "m_nNumNodeHillData", _, team) + 1, _, team);
		}
	}
}