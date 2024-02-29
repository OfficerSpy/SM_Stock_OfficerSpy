#if defined _stock_officerspy_tfgamerules_included
	#endinput
#endif
#define _stock_officerspy_tfgamerules_included

#include <stocklib_officerspy/player>
#include <stocklib_officerspy/stocklib_extra_vscript>

#if !defined TF_TEAM_PVE_INVADERS
#define TF_TEAM_PVE_INVADERS	TFTeam_Blue
#endif

#if !defined TF_TEAM_PVE_DEFENDERS
#define TF_TEAM_PVE_DEFENDERS	TFTeam_Red
#endif

#if !defined ETFGameType_ENABLED
enum ETFGameType
{
	TF_GAMETYPE_UNDEFINED = 0,
	TF_GAMETYPE_CTF,
	TF_GAMETYPE_CP,
	TF_GAMETYPE_ESCORT,
	TF_GAMETYPE_ARENA,
	TF_GAMETYPE_MVM,
	TF_GAMETYPE_RD,
	TF_GAMETYPE_PASSTIME,
	TF_GAMETYPE_PD,
	TF_GAMETYPE_COUNT
};
#define ETFGameType_ENABLED
#endif

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
	return GameRules_GetProp("m_nGameType") == TF_GAMETYPE_PASSTIME;
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
		return TF2_GetClientTeam(who) == TF_TEAM_PVE_INVADERS ? true : false;
	
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
	ArrayList adtPlayer;
	CollectPlayers(adtPlayer, view_as<int>(nTeam), true);
	
	for (int i = 0; i < adtPlayer.Length; i++)
	{
		int player = adtPlayer.Get(i);
		
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