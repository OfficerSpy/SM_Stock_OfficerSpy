#if defined _stock_officerspy_tfplayer_included
	#endinput
#endif
#define _stock_officerspy_tfplayer_included

enum
{
	TFPLAYER_OBS_MODE_NONE = 0,
	TFPLAYER_OBS_MODE_DEATHCAM,
	TFPLAYER_OBS_MODE_FREEZECAM,
	TFPLAYER_OBS_MODE_FIXED,
	TFPLAYER_OBS_MODE_IN_EYE,
	TFPLAYER_OBS_MODE_CHASE,
	TFPLAYER_OBS_MODE_POI,
	TFPLAYER_OBS_MODE_ROAMING,
	TFPLAYER_NUM_OBSERVER_MODES,
};

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
	return iMode != TFPLAYER_OBS_MODE_FREEZECAM && iMode != TFPLAYER_OBS_MODE_DEATHCAM;
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
	//TODO: this is limited by a MAX value
	SetEntProp(client, Prop_Send, "m_nExperienceLevel", nValue);
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
	//TODO: this is limited by a MAX value
	SetEntProp(client, Prop_Send, "m_iKartHealth", iDamage);
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