#if defined _stock_officerspy_tfplayer_included
	#endinput
#endif
#define _stock_officerspy_tfplayer_included

#include <stocklib_officerspy/tf/tf_item>
#include <stocklib_officerspy/other/cpp>
#include <stocklib_officerspy/other/cpp_valve>

#if !defined ENUMERATION_OBS_MODE
enum
{
	OBS_MODE_NONE = 0,
	OBS_MODE_DEATHCAM,
	OBS_MODE_FREEZECAM,
	OBS_MODE_FIXED,
	OBS_MODE_IN_EYE,
	OBS_MODE_CHASE,
	OBS_MODE_POI,
	OBS_MODE_ROAMING,
	NUM_OBSERVER_MODES,
};
#define ENUMERATION_OBS_MODE
#endif

#if !defined ETFFlagType_ENABLED
enum ETFFlagType
{
	TF_FLAGTYPE_CTF = 0,
	TF_FLAGTYPE_ATTACK_DEFEND,
	TF_FLAGTYPE_TERRITORY_CONTROL,
	TF_FLAGTYPE_INVADE,
	TF_FLAGTYPE_RESOURCE_CONTROL,
	TF_FLAGTYPE_ROBOT_DESTRUCTION,
	TF_FLAGTYPE_PLAYER_DESTRUCTION
};
#define ETFFlagType_ENABLED
#endif

stock TFClassType TF2_GetDesiredPlayerClassIndex(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iDesiredPlayerClass"));
}

stock void TF2_SetDesiredPlayerClassIndex(int client, TFClassType iClass)
{
	SetEntProp(client, Prop_Send, "m_iDesiredPlayerClass", iClass);
}

stock void TF2_SetIsMiniBoss(int client, bool isMiniBoss)
{
	SetEntProp(client, Prop_Send, "m_bIsMiniBoss", isMiniBoss);
}

stock bool TF2_ModeWantsSpectatorGUI(int iMode)
{
	return iMode != OBS_MODE_FREEZECAM && iMode != OBS_MODE_DEATHCAM;
}

stock float TF2_GetLastDamageReceivedTime(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flLastDamageTime");
}

stock bool TF2_IsCoaching(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsCoaching"))
}

stock void TF2_SetCoach(int client, int pCoach)
{
	SetEntPropEnt(client, Prop_Send, "m_hCoach", pCoach);
}

stock int TF2_GetCoach(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hCoach");
}

stock void TF2_SetStudent(int client, int pStudent)
{
	SetEntPropEnt(client, Prop_Send, "m_hStudent", pStudent);
}

stock int TF2_GetStudent(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hStudent");
}

stock void TF2_SetUseBossHealthBar(int client, bool bUseBossHealthBar)
{
	SetEntProp(client, Prop_Send, "m_bUseBossHealthBar", bUseBossHealthBar);
}

stock void TF2_SetUsingVRHeadset(int client, bool bState)
{
	SetEntProp(client, Prop_Send, "m_bUsingVRHeadset", bState);
}

stock bool TF2_IsReadyToTauntWithPartner(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsReadyToHighFive"));
}

stock int TF2_GetTauntPartner(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hHighFivePartner");
}

stock float TF2_GetTauntYaw(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flTauntYaw");
}

stock bool TF2_IsTaunting(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_Taunting);
}

stock float TF2_GetCurrentTauntMoveSpeed(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flCurrentTauntMoveSpeed");
}

stock void TF2_SetCurrentTauntMoveSpeed(int client, float flSpeed)
{
	SetEntPropFloat(client, Prop_Send, "m_flCurrentTauntMoveSpeed", flSpeed);
}

stock float TF2_GetVehicleReverseTime(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flVehicleReverseTime");
}

stock void TF2_SetVehicleReverseTime(int client, float flTime)
{
	SetEntPropFloat(client, Prop_Send, "m_flVehicleReverseTime", flTime);
}

stock bool TF2_IsArenaSpectator(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bArenaSpectator"));
}

stock int TF2_GetCurrency(int client)
{
	return GetEntProp(client, Prop_Send, "m_nCurrency");
}

stock void TF2_SetCurrency(int client, int nAmount)
{
	SetEntProp(client, Prop_Send, "m_nCurrency", nAmount);
}

stock void TF2_SetCustomCurrencyWorth(int client, int nAmount)
{
	SetEntProp(client, Prop_Send, "m_nCurrency", nAmount);
}

stock int TF2_GetExperienceLevel(int client)
{
	return GetEntProp(client, Prop_Send, "m_nExperienceLevel");
}

stock void TF2_SetExperienceLevel(int client, int nValue)
{
	SetEntProp(client, Prop_Send, "m_nExperienceLevel", MaxInt(nValue, 1));
}

stock void TF2_SetMatchSafeToLeave(int client, bool bMatchSafeToLeave)
{
	SetEntProp(client, Prop_Send, "m_bMatchSafeToLeave", bMatchSafeToLeave);
}

stock float TF2_GetKartHealth(int client)
{
	return float(GetEntProp(client, Prop_Send, "m_iKartHealth"));
}

stock void TF2_AddKartDamage(int client, int iDamage)
{
	SetEntProp(client, Prop_Send, "m_iKartHealth", MaxInt(0, GetEntProp(client, Prop_Send, "m_iKartHealth") + iDamage));
}

stock int TF2_GetGrapplingHookTarget(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hGrapplingHookTarget");
}

stock bool TF2_IsUsingActionSlot(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bUsingActionSlot"));
}

stock void TF2_SetSecondaryLastWeapon(int client, int pSecondaryLastWeapon)
{
	SetEntPropEnt(client, Prop_Send, "m_hSecondaryLastWeapon", pSecondaryLastWeapon);
}

stock int TF2_GetSecondaryLastWeapon(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hSecondaryLastWeapon");
}

stock void TF2_SetCampaignMedalActive(int client, int iMedal)
{
	int tempVar = GetEntProp(client, Prop_Send, "m_iCampaignMedals");
	tempVar |= iMedal;
	SetEntProp(client, Prop_Send, "m_iCampaignMedals", tempVar);
}

stock int TF2_GetSkinOverride(int client)
{
	return GetEntProp(client, Prop_Send, "m_iPlayerSkinOverride");
}

stock bool TF2_IsFireproof(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_FireImmune);
}

stock int TF2_StateGet(int client)
{
	return GetEntProp(client, Prop_Send, "m_nPlayerState");
}

stock bool TF2_IsInPurgatory(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_EyeaductUnderworld);
}

stock bool TF2_IsMiniBoss(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsMiniBoss"));
}

stock bool TF2_HasCampaignMedal(int client, int iMedal)
{
	return GetEntProp(client, Prop_Send, "m_iCampaignMedals") & iMedal != 0;
}

//Same as BaseCombatCharacter_GetActiveWeapon
stock int TF2_GetActiveTFWeapon(int client)
{
	//The assert is not necessary as it feels like it was meant to return NULL regardless
	return GetEntPropEnt(client, Prop_Send, "m_hActiveWeapon");
}

stock bool TF2_HasItem(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hItem") != -1;
}

stock void TF2_SetItem(int client, int pItem)
{
	SetEntPropEnt(client, Prop_Send, "m_hItem", pItem);
	
	if (pItem != -1)
		SetEntProp(client, Prop_Send, "m_bGlowEnabled", true); //AddGlowEffect
	else
		SetEntProp(client, Prop_Send, "m_bGlowEnabled", false); //RemoveGlowEffect
	
	if (pItem != -1 && TF2_GetItemID(pItem) == TF_ITEM_CAPTURE_FLAG)
	{
		//MISSING: remove invisiblity
	}
}

stock int TF2_GetItem(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hItem");
}

stock bool TF2_HasTheFlag(int client, ETFFlagType[] exceptionTypes = {}, int nNumExceptions = 0)
{
	int item = GetEntPropEnt(client, Prop_Send, "m_hItem");
	
	if (item != -1 && TF2_GetItemID(item) == TF_ITEM_CAPTURE_FLAG)
	{
		for (int i = 0; i < nNumExceptions; i++)
			if (exceptionTypes[i] == view_as<ETFFlagType>(GetEntProp(item, Prop_Send, "m_nType")))
				return false
		
		return true;
	}
	
	return false;
}

stock int TF2_GetClosestCaptureZone(int client)
{
	int pCaptureZone = -1;
	float flClosestDistance = FLT_MAX;
	float origin[3]; GetClientAbsOrigin(client, origin);
	float center[3];
	
	int pTempCaptureZone = -1;
	while ((pTempCaptureZone = FindEntityByClassname(pTempCaptureZone, "func_capturezone")) != -1)
	{
		if (GetEntProp(pTempCaptureZone, Prop_Send, "m_bDisabled") == 0 && GetEntProp(pTempCaptureZone, Prop_Send, "m_iTeamNum") == GetClientTeam(client))
		{
			BaseEntity_WorldSpaceCenter(pCaptureZone, center);
			float fCurrentDistance = GetVectorDistance(origin, center);
			
			if (flClosestDistance > fCurrentDistance)
			{
				pCaptureZone = pTempCaptureZone;
				flClosestDistance = fCurrentDistance;
			}
		}
	}
	
	return pCaptureZone;
}