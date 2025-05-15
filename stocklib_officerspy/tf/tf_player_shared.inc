#if defined _stock_officerspy_tfplayershared_included
	#endinput
#endif
#define _stock_officerspy_tfplayershared_included

#include <tf2_stocks>
#include <stocklib_officerspy/mathlib/mathlib>
#include <stocklib_officerspy/tf/stocklib_extra_vscript>

#if !defined ETFStreak_ENABLED
enum ETFStreak
{
	kTFStreak_Kills	= 0,
	kTFStreak_KillsAll	= 1,
	kTFStreak_Ducks	= 2,
	kTFStreak_Duck_levelup	= 3,
	kTFStreak_COUNT	= 4
};
#define ETFStreak_ENABLED
#endif

#if !defined ENUMERATION_MELEE
enum
{
	MELEE_NOCRIT = 0,
	MELEE_MINICRIT = 1,
	MELEE_CRIT = 2,
};
#define ENUMERATION_MELEE
#endif

#pragma deprecated Use TF2_AddCondition
stock void TF2_AddCond(int client, TFCond eCond, float flDuration = TFCondDuration_Infinite, int pProvider = -1)
{
	TF2_AddCondition(client, eCond, flDuration, pProvider);
}

stock void TF2_RemoveCond(int client, TFCond eCond, bool ignore_duration = false)
{
	if (ignore_duration)
		VS_RemoveCondEx(client, eCond, ignore_duration);
	else
		TF2_RemoveCondition(client, eCond);
}

#pragma deprecated Use TF2_IsPlayerInCondition
stock bool TF2_InCond(int client, TFCond eCond)
{
	return TF2_IsPlayerInCondition(client, eCond);
}

stock TFTeam TF2_GetDisguiseTeam(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_DisguisedAsDispenser) ? (TF2_GetClientTeam(client) == TFTeam_Red ? TFTeam_Blue : TFTeam_Red) : view_as<TFTeam>(GetEntProp(client, Prop_Send, "m_nDisguiseTeam"));
}

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

stock float TF2_GetStealthNoAttackExpireTime(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flStealthNoAttackExpire");
}

#pragma deprecated Use TF2_StunPlayer instead
stock void TFPlayerShared_StunPlayer(int client, float flTime, float flReductionAmount, int iStunFlags = TF_STUN_MOVEMENT, int pAttacker = -1)
{
	TF2_StunPlayer(client, flTime, flReductionAmount, iStunFlags, pAttacker);
}

stock bool TF2_IsLoserStateStunned(int client)
{
	//MISSING: GetActiveStunInfo
	
	if (TF2_IsPlayerInCondition(client, TFCond_Dazed) && GetEntProp(client, Prop_Send, "m_iStunFlags") & TF_STUN_LOSER_STATE)
		return true;
	
	return false;
}

stock bool TF2_IsControlStunned(int client)
{
	//MISSING: GetActiveStunInfo
	
	if (TF2_IsPlayerInCondition(client, TFCond_Dazed) && GetEntProp(client, Prop_Send, "m_iStunFlags") & TF_STUN_CONTROLS)
		return true;
	
	return false;
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

stock void TF2_SetFeignDeathReady(int client, bool bVal)
{
	SetEntProp(client, Prop_Send, "m_bFeignDeathReady", bVal);
}

stock bool TF2_IsFeignDeathReady(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bFeignDeathReady"));
}

stock void TF2_SetShieldEquipped(int client, bool bVal)
{
	SetEntProp(client, Prop_Send, "m_bShieldEquipped", bVal);
}

stock bool TF2_IsShieldEquipped(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bShieldEquipped"));
}

stock void TF2_SetParachuteEquipped(int client, bool bVal)
{
	SetEntProp(client, Prop_Send, "m_bParachuteEquipped", bVal);
}

stock bool TF2_IsParachuteEquipped(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bParachuteEquipped"));
}

stock void TF2_SetNextMeleeCrit(int client, int iVal)
{
	SetEntProp(client, Prop_Send, "m_iNextMeleeCrit", iVal);
}

stock int TF2_GetNextMeleeCrit(int client)
{
	return GetEntProp(client, Prop_Send, "m_iNextMeleeCrit");
}

stock void TF2_SetDecapitations(int client, int iVal)
{
	SetEntProp(client, Prop_Send, "m_iDecapitations", iVal);
}

stock int TF2_GetDecapitations(int client)
{
	return GetEntProp(client, Prop_Send, "m_iDecapitations");
}

stock void TF2_SetStreak(int client, ETFStreak streak_type, int iVal)
{
	SetEntProp(client, Prop_Send, "m_nStreaks", iVal, _, view_as<int>(streak_type));
}

stock int TF2_GetStreak(int client, ETFStreak streak_type)
{
	return GetEntProp(client, Prop_Send, "m_nStreaks", _, view_as<int>(streak_type));
}

stock int TF2_IncrementStreak(int client, ETFStreak streak_type, int iVal)
{
	//TODO: duck streaks?
	
	SetEntProp(client, Prop_Send, "m_nStreaks", GetEntProp(client, Prop_Send, "m_nStreaks", _, view_as<int>(streak_type)) + iVal, _, view_as<int>(streak_type));
	
	return GetEntProp(client, Prop_Send, "m_nStreaks", _, view_as<int>(streak_type));
}

stock void TF2_ResetStreaks(int client)
{
	for (int streak_type = 0; streak_type < view_as<int>(kTFStreak_COUNT); streak_type++)
		SetEntProp(client, Prop_Send, "m_nStreaks", 0, _, streak_type);
}

stock int TF2_GetRevengeCrits(int client)
{
	return GetEntProp(client, Prop_Send, "m_iRevengeCrits");
}

stock float TF2_GetNextNoiseMakerTime(int client)
{
	return GetEntPropFloat(client, Prop_Send, "m_flNextNoiseMakerTime");
}

stock void TF2_SetNextNoiseMakerTime(int client, float time)
{
	SetEntPropFloat(client, Prop_Send, "m_flNextNoiseMakerTime", time);
}

stock void TF2_IncrementRespawnTouchCount(int client)
{
	SetEntProp(client, Prop_Send, "m_iSpawnRoomTouchCount", GetEntProp(client, Prop_Send, "m_iSpawnRoomTouchCount") + 1);
}

stock void TF2_DecrementRespawnTouchCount(int client)
{
	SetEntProp(client, Prop_Send, "m_iSpawnRoomTouchCount", MaxInt(GetEntProp(client, Prop_Send, "m_iSpawnRoomTouchCount") - 1, 0));
}

stock int TF2_GetRespawnTouchCount(int client)
{
	return GetEntProp(client, Prop_Send, "m_iSpawnRoomTouchCount");
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
	return LoadFromAddress(pHealers + view_as<Address>(index * 0x24), NumberType_Int32) & 0xFFF;
}

stock int TF2_GetNumHealers(int client)
{
	return GetEntProp(client, Prop_Send, "m_nNumHealers");
}

stock bool TF2_AddToSpyCloakMeter(int client, float val) //MISSING: bForce
{
	//MISSING: Weapon_OwnsThisID
	
	//MISSING: attribute NoCloakWhenCloaked
	
	float cloakMeter = GetEntPropFloat(client, Prop_Send, "m_flCloakMeter");
	
	bool bResult = (val > 0 && cloakMeter < 100.0);
	
	SetEntPropFloat(client, Prop_Send, "m_flCloakMeter", ClampFloat(cloakMeter + val, 0.0, 100.0));
	
	return bResult;
}

stock bool TF2_IsInvulnerable(int client)
{
	bool bInvuln = TF2_IsPlayerInCondition(client, TFCond_Ubercharged) || TF2_IsPlayerInCondition(client, TFCond_UberchargedCanteen) || TF2_IsPlayerInCondition(client, TFCond_UberchargedHidden) || TF2_IsPlayerInCondition(client, TFCond_UberchargedOnTakeDamage);
	
	return bInvuln;
}

stock bool TF2_IsCritBoosted(int client)
{
	bool bAllWeaponCritActive = (TF2_IsPlayerInCondition(client, TFCond_Kritzkrieged)
	|| TF2_IsPlayerInCondition(client, TFCond_HalloweenCritCandy)
	|| TF2_IsPlayerInCondition(client, TFCond_CritCanteen)
	|| TF2_IsPlayerInCondition(client, TFCond_CritOnFirstBlood)
	|| TF2_IsPlayerInCondition(client, TFCond_CritOnWin)
	|| TF2_IsPlayerInCondition(client, TFCond_CritOnFlagCapture)
	|| TF2_IsPlayerInCondition(client, TFCond_CritOnKill)
	|| TF2_IsPlayerInCondition(client, TFCond_CritOnDamage)
	|| TF2_IsPlayerInCondition(client, TFCond_CritRuneTemp));
	
	if (bAllWeaponCritActive)
		return true;
	
	//MISSING: pyro rage stuff
	//MISSING: attribute mult_crit_when_health_is_below_percent 
	
	return false;
}

stock bool TF2_IsStealthed(int client)
{
	return TF2_IsPlayerInCondition(client, TFCond_Cloaked) || TF2_IsPlayerInCondition(client, TFCond_Stealthed) || TF2_IsPlayerInCondition(client, TFCond_StealthedUserBuffFade);
}