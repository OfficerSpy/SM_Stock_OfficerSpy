#if defined _stock_officerspy_tfgamerules_included
	#endinput
#endif
#define _stock_officerspy_tfgamerules_included

#include <stocklib_officerspy/shared/tf_shareddefs>
#include <stocklib_officerspy/gamerules>
#include <stocklib_officerspy/team_objectiveresource>
#include <stocklib_officerspy/stocklib_extra_vscript>

stock int TF2_GetFarthestOwnedControlPoint(TFTeam iTeam, bool bWithSpawnpoints)
{
	int iRsrc = FindEntityByClassname(-1, "tf_objective_resource");
	
	int iOwnedEnd = BaseTeamObjectiveResource_GetBaseControlPointForTeam(iRsrc, iTeam);
	
	if (iOwnedEnd == -1)
		return -1;
	
	int iNumControlPoints = BaseTeamObjectiveResource_GetNumControlPoints(iRsrc);
	int iWalk = 1;
	int iEnemyEnd = iNumControlPoints - 1;
	
	if (iOwnedEnd != 0)
	{
		iWalk = -1;
		iEnemyEnd = 0;
	}
	
	int iFarthestPoint = iOwnedEnd;
	
	for (int iPoint = iOwnedEnd; iPoint != iEnemyEnd; iPoint += iWalk)
	{
		if (BaseTeamObjectiveResource_GetOwningTeam(iRsrc, iPoint) != view_as<int>(iTeam))
			break;
		
		//MISSING: if ( bWithSpawnpoints && !m_bControlSpawnsPerTeam[iTeam][iPoint] )
		
		iFarthestPoint = iPoint;
	}
	
	return iFarthestPoint;
}

stock bool TFGameRules_TeamMayCapturePoint(TFTeam iTeam, int iPointIndex)
{
	if (!FindConVar("tf_caplinear").BoolValue)
		return true;
	
	int iRsrc = FindEntityByClassname(-1, "tf_objective_resource");
	
	int iPointNeeded = BaseTeamObjectiveResource_GetPreviousPointForPoint(iRsrc, iPointIndex, iTeam, 0);
	
	if (iPointNeeded == iPointIndex)
		return true;
	
	if (TF2_IsInKothMode() && TeamplayRoundBasedRules_IsInWaitingForPlayers())
		return false;
	
	if (BaseTeamObjectiveResource_GetCPLocked(iRsrc, iPointIndex))
		return false;
	
	if (iPointNeeded == -1)
	{
		if (TF2_IsInArenaMode() == true)
		{
			if (GameRules_GetPropFloat("m_flCapturePointEnableTime") <= GetGameTime() && GameRules_GetRoundState() == RoundState_Stalemate)
				return true;
			
			return false;
		}
		
		if (!BaseTeamObjectiveResource_PlayingMiniRounds(iRsrc))
		{
			int iFarthestPoint = TF2_GetFarthestOwnedControlPoint(iTeam, false);
			return iFarthestPoint - iPointIndex <= 1;
		}
		else
		{
			return true;
		}
	}
	
	for (int iPrevPoint = 0; iPrevPoint < MAX_PREVIOUS_POINTS; iPrevPoint++)
	{
		iPointNeeded = BaseTeamObjectiveResource_GetPreviousPointForPoint(iRsrc, iPointIndex, iTeam, iPrevPoint);
		
		if (iPointNeeded != -1)
		{
			if (BaseTeamObjectiveResource_GetOwningTeam(iRsrc, iPointNeeded) != view_as<int>(iTeam))
				return false;
		}
	}
	
	return true;
}

stock bool TFGameRules_ShouldCollide(int collisionGroup0, int collisionGroup1)
{
	if (collisionGroup0 > collisionGroup1)
	{
		//Swap places
		int old = collisionGroup0;
		collisionGroup0 = collisionGroup1;
		collisionGroup1 = old;
	}
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT && collisionGroup1 == COLLISION_GROUP_WEAPON)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT && collisionGroup1 == COLLISION_GROUP_PROJECTILE)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER && (collisionGroup1 == TFCOLLISION_GROUP_ROCKETS || collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return true;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT && (collisionGroup1 == TFCOLLISION_GROUP_ROCKETS || collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_WEAPON && (collisionGroup1 == TFCOLLISION_GROUP_ROCKETS || collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == TF_COLLISIONGROUP_GRENADES && (collisionGroup1 == TFCOLLISION_GROUP_ROCKETS || collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PROJECTILE && (collisionGroup1 == TFCOLLISION_GROUP_ROCKETS || collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == TFCOLLISION_GROUP_ROCKETS && (collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS && (collisionGroup1 == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS))
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER && collisionGroup1 == TF_COLLISIONGROUP_GRENADES)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT && collisionGroup1 == TF_COLLISIONGROUP_GRENADES)
		return false;
	
	if (collisionGroup1 == TFCOLLISION_GROUP_RESPAWNROOMS)
		return collisionGroup0 == COLLISION_GROUP_PLAYER || collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT;
	
	if (collisionGroup0 == TF_COLLISIONGROUP_GRENADES && collisionGroup1 == TF_COLLISIONGROUP_GRENADES)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER_MOVEMENT && collisionGroup1 == TFCOLLISION_GROUP_COMBATOBJECT)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER && collisionGroup1 == TFCOLLISION_GROUP_COMBATOBJECT)
		return false;
	
	if ((collisionGroup0 == COLLISION_GROUP_PLAYER || collisionGroup0 ==  COLLISION_GROUP_PLAYER_MOVEMENT) && collisionGroup1 == TFCOLLISION_GROUP_TANK)
		return false;
	
	return CGameRules_ShouldCollide(collisionGroup0, collisionGroup1);
}

stock bool TF2_IsInArenaMode()
{
	return view_as<ETFGameType>(GameRules_GetProp("m_nGameType")) == TF_GAMETYPE_ARENA;
}

stock bool TF2_IsInKothMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingKoth"));
}

stock bool TF2_IsInMedievalMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingMedieval"));
}

stock bool TF2_IsHolidayMap(int nHoliday)
{
	return GameRules_GetProp("m_nMapHolidayType") == nHoliday;
}

stock bool TF2_IsMannVsMachineMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingMannVsMachine"));
}

stock void TF2_SetMannVsMachineAlarmStatus(bool bStatus)
{
	GameRules_SetProp("m_bMannVsMachineAlarmStatus", bStatus);
}

stock bool TF2_GetMannVsMachineAlarmStatus()
{
	return view_as<bool>(GameRules_GetProp("m_bMannVsMachineAlarmStatus"));
}

stock bool TF2_GameModeUsesCurrency()
{
	return TF2_IsMannVsMachineMode() || TF2_IsBountyMode();
}

stock bool TF2_GameModeUsesMiniBosses()
{
	return TF2_IsMannVsMachineMode() || TF2_IsBountyMode();
}

stock bool TF2_IsPasstimeMode()
{
	return view_as<ETFGameType>(GameRules_GetProp("m_nGameType")) == TF_GAMETYPE_PASSTIME;
}

stock bool TF2_IsMannVsMachineRespecEnabled()
{
	return TF2_IsMannVsMachineMode() && GetConVarBool(FindConVar("tf_mvm_respec_enabled"));
}

stock bool TF2_IsPowerupMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPowerupMode"));
}

stock void TF2_SetPowerupMode(bool bValue)
{
	ConVar tf_grapplinghook_enable = FindConVar("tf_grapplinghook_enable");
	ConVar tf_flag_return_time_credit_factor = FindConVar("tf_flag_return_time_credit_factor");
	
	if (bValue)
	{
		tf_grapplinghook_enable.SetInt(1);
		tf_flag_return_time_credit_factor.SetInt(0);
	}
	else
	{
		tf_grapplinghook_enable.SetInt(0);
		tf_flag_return_time_credit_factor.SetInt(1);
	}
	
	GameRules_SetProp("m_bPowerupMode", bValue);
}

stock bool TF2_IsPVEModeActive()
{
	if (TF2_IsMannVsMachineMode())
		return true;
	
	return false;
}

stock bool TF2_IsPVEModeControlled(int who)
{
	//This assumes the entity is always a player and honestly
	//it should never be anything else as far as I know
	if (TF2_IsMannVsMachineMode())
		return GetClientTeam(who) == TF_TEAM_PVE_INVADERS ? true : false;
	
	if (TF2_IsPVEModeActive())
		return TF2_GetClientTeam(who) == TFTeam_Red ? true : false;
	
	return false;
}

stock void TF2_GetCustomUpgradesFile(char[] buffer, int maxlen)
{
	GameRules_GetPropString("m_pszCustomUpgradesFile", buffer, maxlen);
}

stock bool TF2_IsInTraining()
{
	return view_as<bool>(GameRules_GetProp("m_bIsInTraining"));
}

stock bool TF2_AllowTrainingAchievements()
{
	return view_as<bool>(GameRules_GetProp("m_bAllowTrainingAchievements"));
}

stock void TF2_SetAllowTrainingAchievements(bool bAllow)
{
	GameRules_SetProp("m_bAllowTrainingAchievements", bAllow);
}

stock bool TF2_IsWaitingForTrainingToContinue()
{
	return view_as<bool>(GameRules_GetProp("m_bIsWaitingForTrainingContinue"));
}

stock void TF2_SetIsWaitingForTrainingToContinue(bool bWaiting)
{
	GameRules_SetProp("m_bIsWaitingForTrainingContinue", bWaiting);
}

stock int TF2_GetHUDType()
{
	return GameRules_GetProp("m_nHudType");
}

stock bool TF2_IsInItemTestingMode()
{
	return view_as<bool>(GameRules_GetProp("m_bIsInItemTestingMode"));
}

stock void TF2_SetInItemTestingMode(bool bInTesting)
{
	GameRules_SetProp("m_bIsInItemTestingMode", bInTesting);
}

stock bool TF2_IsPlayingHybrid_CTF_CP()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingHybrid_CTF_CP"));
}

stock bool TF2_IsPlayingSpecialDeliveryMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingSpecialDeliveryMode"));
}

stock bool TF2_IsPlayingRobotDestructionMode()
{
	return view_as<bool>(GameRules_GetProp("m_bPlayingRobotDestructionMode"));
}

stock int TF2_GetBonusLogic()
{
	return GameRules_GetPropEnt("m_hBonusLogic");
}

stock int TF2_GetRedKothRoundTimer()
{
	return GameRules_GetPropEnt("m_hRedKothTimer");
}

stock int TF2_GetBlueKothRoundTimer()
{
	return GameRules_GetPropEnt("m_hBlueKothTimer");
}

stock bool TF2_IsBountyMode()
{
	//This is always false in the release build, at least for now
	return false;
}

stock void TF2_PushAllPlayersAway(const float vFromThisPoint[3], float flRange, float flForce, TFTeam nTeam)
{
	//CollectPlayers
	int iTotal = 0;
	int[] iArrPlayers = new int[MaxClients];
	for (int i = 1; i <= MaxClients; i++)
		if (IsClientInGame(i) && TF2_GetClientTeam(i) == nTeam && IsPlayerAlive(i))
			iArrPlayers[iTotal++] = i;
	
	for (int i = 0; i < iTotal; i++)
	{
		int player = iArrPlayers[i];
		
		float eyePosition[3]; GetClientEyePosition(player, eyePosition);
		
		float toPlayer[3]; SubtractVectors(eyePosition, vFromThisPoint, toPlayer);
		
		if (GetVectorLength(toPlayer, true) < flRange * flRange)
		{
			toPlayer[2] = 0.0;
			NormalizeVector(toPlayer, toPlayer);
			toPlayer[2] = 1.0;
			
			float vPush[3]; vPush = toPlayer;
			ScaleVector(vPush, flForce);
			
			VS_ApplyAbsVelocityImpulse(player, vPush);
		}
	}
}