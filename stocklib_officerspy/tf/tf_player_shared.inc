#include <tf2_stocks>

stock TFClassType TF2_GetDisguiseClass(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_DisguisedAsDispenser) ? TFClass_Engineer : view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_nDisguiseClass"));
}

stock int TF2_GetDisguisedSkinOverride(int client)
{
	return GetEntProp(client, Prop_Send, "m_nDisguiseSkinOverride");
}

stock TFClassType TF2_GetDisguiseMask(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_DisguisedAsDispenser) ? TFClass_Engineer : view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_nMaskClass"));
}

stock TFClassType TF2_GetDesiredDisguiseClass(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_nDesiredDisguiseClass"));
}

stock TFTeam TF2_GetDesiredDisguiseTeam(int client)
{
	return view_as<TFTeam>(GetEntProp(client, Prop_Send, "m_nDesiredDisguiseTeam"));
}

stock bool TF2_WasLastDisguiseAsOwnTeam(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bLastDisguisedAsOwnTeam"));
}

stock int TF2_GetDisguiseTargetIndex(int client)
{
	return GetEntProp(client, Prop_Send, "m_iDisguiseTargetIndex");
}

stock int TF2_GetDisguiseWeapon(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hDisguiseWeapon");
}

stock int TF2_GetDisguiseHealth(int client)
{
	return GetEntProp(client, Prop_Send, "m_iDisguiseHealth");
}

stock TFTeam TF2_GetTeamTeleporterUsed(int client)
{
	return view_as<TFTeam>(GetEntProp(client, Prop_Send, "m_nTeamTeleporterUsed"));
}

stock void TF2_IncrementArenaNumChanges(int client)
{
	SetEntProp(client, Prop_Send, "m_nArenaNumChanges", GetEntProp(client, Prop_Send, "m_nArenaNumChanges") + 1);
}

stock void TF2_ResetArenaNumChanges(int client)
{
	SetEntProp(client, Prop_Send, "m_nArenaNumChanges", 0);
}

stock void TF2_SetTeamTeleporterUsed(int client, TFTeam nTeam)
{
	SetEntProp(client, Prop_Send, "m_nTeamTeleporterUsed", nTeam);
}

stock int TF2_GetArenaNumChanges(int client)
{
	return GetEntProp(client, Prop_Send, "m_nArenaNumChanges");
}

stock float TF2_GetRuneCharge(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flRuneCharge");
}

stock void TF2_SetRuneCharge(int client, float fVal)
{
	//TODO: this value should actually be clamped
	SetEntPropFloat(client, Prop_Send, "m_flRuneCharge", fVal);
}

stock bool TF2_IsRuneCharged(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flRuneCharge") == 100.0;
}

stock bool TF2_IsInUpgradeZone(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bInUpgradeZone"));
}

stock void TF2_SetInUpgradeZone(int client, bool bInZone)
{
	SetEntProp(client, Prop_Send, "m_bInUpgradeZone", bInZone);
}

stock float TF2_GetSpyCloakMeter(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flCloakMeter");
}

stock void TF2_SetSpyCloakMeter(int client, float val)
{
	SetEntPropFloat(client, Prop_Send, "m_flCloakMeter", val);
}

stock bool TF2_IsRageDraining(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bRageDraining"));
}

stock float TF2_GetRageMeter(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flRageMeter");
}

stock void TF2_StartRageDrain(int client)
{
	SetEntProp(client, Prop_Send, "m_bRageDraining", true);
}

stock float TF2_GetScoutEnergyDrinkMeter(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flEnergyDrinkMeter");
}

stock void TF2_SetScoutEnergyDrinkMeter(int client, float val)
{
	SetEntPropFloat(client, Prop_Send, "m_flEnergyDrinkMeter", val);
}

stock float TF2_GetScoutHypeMeter(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flHypeMeter");
}

stock void TF2_StopScoutHypeDrain(int client)
{
	TF2_RemoveCondition(client, TFCond_CritHype);
}

stock bool TF2_IsHypeBuffed(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_CritHype);
}

stock float TF2_GetDemomanChargeMeter(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flChargeMeter");
}

stock void TF2_SetDemomanChargeMeter(int client, float val)
{
	//TODO: this value should be clamped
	SetEntPropFloat(client, Prop_Send, "m_flChargeMeter", val);
}

stock bool TF2_IsJumping(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bJumping"));
}

stock bool TF2_IsAirDashing(int client)
{
	return GetEntProp(client, Prop_Send, "m_iAirDash") > 0;
}

stock int TF2_GetAirDash(int client)
{
	return GetEntProp(client, Prop_Send, "m_iAirDash");
}

stock void TF2_SetAirDucked(int client, int nAirDucked)
{
	SetEntProp(client, Prop_Send, "m_nAirDucked", nAirDucked);
}

stock int TF2_AirDuckedCount(int client)
{
	return GetEntProp(client, Prop_Send, "m_nAirDucked");
}

stock void TF2_SetDuckTimer(int client, float flTime)
{
	SetEntPropFloat(client, Prop_Send, "m_flDuckTimer", flTime);
}

stock float TF2_GetDuckTimer(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flDuckTimer");
}

stock float TF2_GetDisguiseCompleteTime(int client)
{
	return GetEntPropFloat(client, Prop_Data, "m_flDisguiseCompleteTime");
}

stock bool TF2_IsFirstBloodBoosted(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bArenaFirstBloodBoost"));
}

stock void TF2_SetFirstBloodBoosted(int client, bool bBoost)
{
	SetEntProp(client, Prop_Send, "m_bArenaFirstBloodBoost", bBoost);
}

stock int TF2_GetWeaponKnockbackID(int client)
{
	return GetEntProp(client, Prop_Send, "m_iWeaponKnockbackID");
}

stock void TF2_SetWeaponKnockbackID(int client, int iID)
{
	SetEntProp(client, Prop_Send, "m_iWeaponKnockbackID", iID);
}

stock bool TF2_IsLoadoutUnavailable(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bLoadoutUnavailable"));
}

stock void TF2_SetLoadoutUnavailable(int client, bool bUnavailable)
{
	SetEntProp(client, Prop_Send, "m_bLoadoutUnavailable", bUnavailable);
}

stock int TF2_GetDisguiseBody(int client)
{
	return GetEntProp(client, Prop_Send, "m_iDisguiseBody");
}

stock void TF2_SetDisguiseBody(int client, int iVal)
{
	SetEntProp(client, Prop_Send, "m_iDisguiseBody", iVal);
}

stock bool TF2_IsCarryingObject(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bCarryingObject"));
}

stock int TF2_GetCarriedObject(int client)
{
	return GetEntPropEnt(client, Prop_Send, "m_hCarriedObject");
}

stock float TF2_GetPercentInvisible(int client)
{
	static int offset = -1;
	
	if (offset == -1)
		offset = FindSendPropInfo("CTFPlayer", "m_flInvisChangeCompleteTime") - 8; //m_flInvisibility
	
	return GetEntDataFloat(client, offset);
}

stock int TF2_GetHealerByIndex(int client, int index)
{
	static int offset = -1;
	
	if (offset == -1)
		offset = FindSendPropInfo("CTFPlayer", "m_nNumHealers") + 12; //m_aHealers
	
	Address pShared = GetEntityAddress(client) + view_as<Address>(offset); //m_Shared
	Address pHealers = view_as<Address>(LoadFromAddress(pShared, NumberType_Int32)); //m_aHealers
	
	//m_aHealers[index].pHealer
	return (LoadFromAddress(pHealers + view_as<Address>(index * 0x24), NumberType_Int32) & 0xFFF);
}