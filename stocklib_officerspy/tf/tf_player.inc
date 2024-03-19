#if defined _stock_officerspy_tfplayer_included
	#endinput
#endif
#define _stock_officerspy_tfplayer_included

#include <stocklib_officerspy/basemultiplayerplayer>
#include <stocklib_officerspy/tf/tf_playerclass_shared>
#include <stocklib_officerspy/tf/tf_player_shared>
#include <stocklib_officerspy/tf/tf_item>
#include <stocklib_officerspy/other/cpp>
#include <stocklib_officerspy/other/cpp_valve>

methodmap OSTFPlayer < OSBaseMultiplayerPlayer
{
	public OSTFPlayer(int index)
	{
		return view_as<OSTFPlayer>(index);
	}
	
	public TFClassType GetDesiredPlayerClassIndex()
	{
		return TF2_GetDesiredPlayerClassIndex(this.index);
	}
	
	public void SetDesiredPlayerClassIndex(TFClassType iClass)
	{
		TF2_SetDesiredPlayerClassIndex(this.index, iClass);
	}
	
	public void SetIsMiniBoss(bool isMiniBoss)
	{
		TF2_SetIsMiniBoss(this.index, isMiniBoss);
	}
	
	public bool ModeWantsSpectatorGUI(int iMode)
	{
		return TF2_ModeWantsSpectatorGUI(iMode);
	}
	
	public float GetLastDamageReceivedTime()
	{
		return TF2_GetLastDamageReceivedTime(this.index);
	}
	
	public bool IsCoaching()
	{
		return TF2_IsCoaching(this.index);
	}
	
	public void SetCoach(int pCoach)
	{
		TF2_SetCoach(this.index, pCoach);
	}
	
	public int GetCoach()
	{
		return TF2_GetCoach(this.index);
	}
	
	public void SetStudent(int pStudent)
	{
		TF2_SetStudent(this.index, pStudent);
	}
	
	public int GetStudent()
	{
		return TF2_GetStudent(this.index);
	}
	
	public void SetUseBossHealthBar(bool bUseBossHealthBar)
	{
		TF2_SetUseBossHealthBar(this.index, bUseBossHealthBar);
	}
	
	public void SetUsingVRHeadset(bool bState)
	{
		TF2_SetUsingVRHeadset(this.index, bState);
	}
	
	public bool IsReadyToTauntWithPartner()
	{
		return TF2_IsReadyToTauntWithPartner(this.index);
	}
	
	public int GetTauntPartner()
	{
		return TF2_GetTauntPartner(this.index);
	}
	
	public float GetTauntYaw()
	{
		return TF2_GetTauntYaw(this.index);
	}
	
	public bool IsTaunting()
	{
		return TF2_IsTaunting(this.index);
	}
	
	public float GetCurrentTauntMoveSpeed()
	{
		return TF2_GetCurrentTauntMoveSpeed(this.index);
	}
	
	public void SetCurrentTauntMoveSpeed(float flSpeed)
	{
		TF2_SetCurrentTauntMoveSpeed(this.index, flSpeed);
	}
	
	public float GetVehicleReverseTime()
	{
		return TF2_GetVehicleReverseTime(this.index);
	}
	
	public void SetVehicleReverseTime(float flTime)
	{
		TF2_SetVehicleReverseTime(this.index, flTime);
	}
	
	public bool IsArenaSpectator()
	{
		return TF2_IsArenaSpectator(this.index);
	}
	
	public int GetCurrency()
	{
		return TF2_GetCurrency(this.index);
	}
	
	public void SetCurrency(int nAmount)
	{
		TF2_SetCurrency(this.index, nAmount);
	}
	
	public void SetCustomCurrencyWorth(int nAmount)
	{
		TF2_SetCustomCurrencyWorth(this.index, nAmount);
	}
	
	public int GetExperienceLevel()
	{
		return TF2_GetExperienceLevel(this.index);
	}
	
	public void SetExperienceLevel(int nValue)
	{
		TF2_SetExperienceLevel(this.index, nValue);
	}
	
	public void SetMatchSafeToLeave(bool bMatchSafeToLeave)
	{
		TF2_SetMatchSafeToLeave(this.index, bMatchSafeToLeave);
	}
	
	public float GetKartHealth()
	{
		return TF2_GetKartHealth(this.index);
	}
	
	public void AddKartDamage(int iDamage)
	{
		TF2_AddKartDamage(this.index, iDamage);
	}
	
	public int GetGrapplingHookTarget()
	{
		return TF2_GetGrapplingHookTarget(this.index);
	}
	
	public bool IsUsingActionSlot()
	{
		return TF2_IsUsingActionSlot(this.index);
	}
	
	public void SetSecondaryLastWeapon(int pSecondaryLastWeapon)
	{
		TF2_SetSecondaryLastWeapon(this.index, pSecondaryLastWeapon);
	}
	
	public int GetSecondaryLastWeapon()
	{
		return TF2_GetSecondaryLastWeapon(this.index);
	}
	
	public void SetCampaignMedalActive(int iMedal)
	{
		TF2_SetCampaignMedalActive(this.index, iMedal);
	}
	
	public int GetSkinOverride()
	{
		return TF2_GetSkinOverride(this.index);
	}
	
	public bool IsFireproof()
	{
		return TF2_IsFireproof(this.index);
	}
	
	public int StateGet()
	{
		return TF2_StateGet(this.index);
	}
	
	public bool IsInPurgatory()
	{
		return TF2_IsInPurgatory(this.index);
	}
	
	public bool IsMiniBoss()
	{
		return TF2_IsMiniBoss(this.index);
	}
	
	public bool HasCampaignMedal(int iMedal)
	{
		return TF2_HasCampaignMedal(this.index, iMedal);
	}
	
	public int GetActiveTFWeapon()
	{
		return TF2_GetActiveTFWeapon(this.index);
	}
	
	public int GiveAmmo(int iCount, int iAmmoIndex, bool bSuppressSound = false)
	{
		return TF2_GiveAmmo(this.index, iCount, iAmmoIndex, bSuppressSound);
	}
	
	public void SetClassMenuOpen(bool bOpen)
	{
		TF2_SetClassMenuOpen(this.index, bOpen);
	}
	
	public bool ShouldCollide(int collisionGroup, int contentsMask)
	{
		return TFPlayer_ShouldCollide(this.index, collisionGroup, contentsMask);
	}
	
	public void TeleportEffect()
	{
		TF2_TeleportEffect(this.index);
	}
	
	public void RemoveTeleportEffect()
	{
		TF2_RemoveTeleportEffect(this.index);
	}
	
	public bool HasItem()
	{
		return TF2_HasItem(this.index);
	}
	
	public void SetItem(int pItem)
	{
		TF2_SetItem(this.index, pItem);
	}
	
	public int GetItem()
	{
		return TF2_GetItem(this.index);
	}
	
	public bool HasTheFlag(ETFFlagType[] exceptionTypes = {}, int nNumExceptions = 0)
	{
		return TF2_HasTheFlag(this.index, exceptionTypes, nNumExceptions);
	}
	
	public int GetClosestCaptureZone()
	{
		return TF2_GetClosestCaptureZone(this.index);
	}
	
	//Below are CTFPlayerClassShared functions but these work on clients
	
	public bool IsClass(TFClassType iClass)
	{
		return TF2_IsClass(this.index, iClass);
	}
	
	public TFClassType GetClassIndex()
	{
		return TF2_GetPlayerClass(this.index);
	}
	
	public void GetClassIconName(char[] buffer, int maxlen)
	{
		TF2_GetClassIconName(this.index, buffer, maxlen);
	}
	
	public void SetClassIconName(char[] iszClassIcon)
	{
		TF2_SetClassIconName(this.index, iszClassIcon);
	}
	
	public bool HasCustomModel()
	{
		return TF2_HasCustomModel(this.index);
	}
	
	public void SetCustomModel(char[] pszModelName, bool isUsingClassAnimations = false)
	{
		TF2_SetCustomModel(this.index, pszModelName, isUsingClassAnimations);
	}
	
	public void SetCustomModelOffset(float vecOffset[3])
	{
		TF2_SetCustomModelOffset(this.index, vecOffset);
	}
	
	public void SetCustomModelRotates(bool bRotates)
	{
		TF2_SetCustomModelRotates(this.index, bRotates);
	}
	
	public void SetCustomModelRotation(float vecOffset[3])
	{
		TF2_SetCustomModelRotation(this.index, vecOffset);
	}
	
	public void ClearCustomModelRotation()
	{
		TF2_ClearCustomModelRotation(this.index);
	}
	
	public void SetCustomModelVisibleToSelf(bool bVisible)
	{
		TF2_SetCustomModelVisibleToSelf(this.index, bVisible);
	}
	
	//Below are CTFPlayerShared functions but these work on clients
	
	public void AddCond(TFCond eCond, float flDuration = TFCondDuration_Infinite, int pProvider = -1)
	{
		TF2_AddCondition(this.index, eCond, flDuration, pProvider);
	}
	
	public void RemoveCond(TFCond eCond, bool ignore_duration = false)
	{
		TF2_RemoveCond(this.index, eCond, ignore_duration);
	}
	
	public bool InCond(TFCond eCond)
	{
		return TF2_IsPlayerInCondition(this.index, eCond);
	}
	
	public TFClassType GetDisguiseClass()
	{
		return TF2_GetDisguiseClass(this.index);
	}
	
	public int GetDisguisedSkinOverride()
	{
		return TF2_GetDisguisedSkinOverride(this.index);
	}
	
	public TFClassType GetDisguiseMask()
	{
		return TF2_GetDisguiseMask(this.index);
	}
	
	public TFClassType GetDesiredDisguiseClass()
	{
		return TF2_GetDesiredDisguiseClass(this.index);
	}
	
	public TFTeam GetDesiredDisguiseTeam()
	{
		return TF2_GetDesiredDisguiseTeam(this.index);
	}
	
	public bool WasLastDisguiseAsOwnTeam()
	{
		return TF2_WasLastDisguiseAsOwnTeam(this.index);
	}
	
	public int GetDisguiseTargetIndex()
	{
		return TF2_GetDisguiseTargetIndex(this.index);
	}
	
	public int GetDisguiseWeapon()
	{
		return TF2_GetDisguiseWeapon(this.index);
	}
	
	public int GetDisguiseHealth()
	{
		return TF2_GetDisguiseHealth(this.index);
	}
	
	public TFTeam GetTeamTeleporterUsed()
	{
		return TF2_GetTeamTeleporterUsed(this.index);
	}
	
	public void IncrementArenaNumChanges()
	{
		TF2_IncrementArenaNumChanges(this.index);
	}
	
	public void ResetArenaNumChanges()
	{
		TF2_ResetArenaNumChanges(this.index);
	}
	
	public void SetTeamTeleporterUsed(TFTeam nTeam)
	{
		TF2_SetTeamTeleporterUsed(this.index, nTeam);
	}
	
	public int GetArenaNumChanges()
	{
		return TF2_GetArenaNumChanges(this.index);
	}
	
	public float GetRuneCharge()
	{
		return TF2_GetRuneCharge(this.index);
	}
	
	public void SetRuneCharge(float fVal)
	{
		TF2_SetRuneCharge(this.index, fVal);
	}
	
	public bool IsRuneCharged()
	{
		return TF2_IsRuneCharged(this.index);
	}
	
	public bool IsInUpgradeZone()
	{
		return TF2_IsInUpgradeZone(this.index);
	}
	
	public void SetInUpgradeZone(bool bInZone)
	{
		TF2_SetInUpgradeZone(this.index, bInZone);
	}
	
	public float GetSpyCloakMeter()
	{
		return TF2_GetSpyCloakMeter(this.index);
	}
	
	public void SetSpyCloakMeter(float val)
	{
		TF2_SetSpyCloakMeter(this.index, val);
	}
	
	public bool IsRageDraining()
	{
		return TF2_IsRageDraining(this.index);
	}
	
	public float GetRageMeter()
	{
		return TF2_GetRageMeter(this.index);
	}
	
	public void StartRageDrain()
	{
		TF2_StartRageDrain(this.index);
	}
	
	public float GetScoutEnergyDrinkMeter()
	{
		return TF2_GetScoutEnergyDrinkMeter(this.index);
	}
	
	public void SetScoutEnergyDrinkMeter(float val)
	{
		TF2_SetScoutEnergyDrinkMeter(this.index, val);
	}
	
	public float GetScoutHypeMeter()
	{
		return TF2_GetScoutHypeMeter(this.index);
	}
	
	public void StopScoutHypeDrain()
	{
		TF2_StopScoutHypeDrain(this.index);
	}
	
	public bool IsHypeBuffed()
	{
		return TF2_IsHypeBuffed(this.index);
	}
	
	public float GetDemomanChargeMeter()
	{
		return TF2_GetDemomanChargeMeter(this.index);
	}
	
	public void SetDemomanChargeMeter(float val)
	{
		TF2_SetDemomanChargeMeter(this.index, val);
	}
	
	public bool IsJumping()
	{
		return TF2_IsJumping(this.index);
	}
	
	public bool IsAirDashing()
	{
		return TF2_IsAirDashing(this.index);
	}
	
	public int GetAirDash()
	{
		return TF2_GetAirDash(this.index);
	}
	
	public void SetAirDucked(int nAirDucked)
	{
		TF2_SetAirDucked(this.index, nAirDucked);
	}
	
	public int AirDuckedCount()
	{
		return TF2_AirDuckedCount(this.index);
	}
	
	public void SetDuckTimer(float flTime)
	{
		TF2_SetDuckTimer(this.index, flTime);
	}
	
	public float GetDuckTimer()
	{
		return TF2_GetDuckTimer(this.index);
	}
	
	public float GetDisguiseCompleteTime()
	{
		return TF2_GetDisguiseCompleteTime(this.index);
	}
	
	public bool IsFirstBloodBoosted()
	{
		return TF2_IsFirstBloodBoosted(this.index);
	}
	
	public void SetFirstBloodBoosted(bool bBoost)
	{
		TF2_SetFirstBloodBoosted(this.index, bBoost);
	}
	
	public int GetWeaponKnockbackID()
	{
		return TF2_GetWeaponKnockbackID(this.index);
	}
	
	public void SetWeaponKnockbackID(int iID)
	{
		TF2_SetWeaponKnockbackID(this.index, iID);
	}
	
	public bool IsLoadoutUnavailable()
	{
		return TF2_IsLoadoutUnavailable(this.index);
	}
	
	public void SetLoadoutUnavailable(bool bUnavailable)
	{
		TF2_SetLoadoutUnavailable(this.index, bUnavailable);
	}
	
	public int GetDisguiseBody()
	{
		return TF2_GetDisguiseBody(this.index);
	}
	
	public void SetDisguiseBody(int iVal)
	{
		TF2_SetDisguiseBody(this.index, iVal);
	}
	
	public bool IsCarryingObject()
	{
		return TF2_IsCarryingObject(this.index);
	}
	
	public int GetCarriedObject()
	{
		return TF2_GetCarriedObject(this.index);
	}
	
	public void SetFeignDeathReady(bool bVal)
	{
		TF2_SetFeignDeathReady(this.index, bVal);
	}
	
	public bool IsFeignDeathReady()
	{
		return TF2_IsFeignDeathReady(this.index);
	}
	
	public void SetShieldEquipped(bool bVal)
	{
		TF2_SetShieldEquipped(this.index, bVal);
	}
	
	public bool IsShieldEquipped()
	{
		return TF2_IsShieldEquipped(this.index);
	}
	
	public void SetParachuteEquipped(bool bVal)
	{
		TF2_SetParachuteEquipped(this.index, bVal);
	}
	
	public bool IsParachuteEquipped()
	{
		return TF2_IsParachuteEquipped(this.index);
	}
	
	public void SetNextMeleeCrit(int iVal)
	{
		TF2_SetNextMeleeCrit(this.index, iVal);
	}
	
	public int GetNextMeleeCrit()
	{
		return TF2_GetNextMeleeCrit(this.index);
	}
	
	public void SetDecapitations(int iVal)
	{
		TF2_SetDecapitations(this.index, iVal);
	}
	
	public int GetDecapitations()
	{
		return TF2_GetDecapitations(this.index);
	}
	
	public void SetStreak(ETFStreak streak_type, int iVal)
	{
		TF2_SetStreak(this.index, streak_type, iVal);
	}
	
	public int GetStreak(ETFStreak streak_type)
	{
		return TF2_GetStreak(this.index, streak_type);
	}
	
	public int IncrementStreak(ETFStreak streak_type, int iVal)
	{
		return TF2_IncrementStreak(this.index, streak_type, iVal);
	}
	
	public void ResetStreaks()
	{
		TF2_ResetStreaks(this.index);
	}
	
	public int GetRevengeCrits()
	{
		return TF2_GetRevengeCrits(this.index);
	}
	
	public float GetNextNoiseMakerTime()
	{
		return TF2_GetNextNoiseMakerTime(this.index);
	}
	
	public void SetNextNoiseMakerTime(float time)
	{
		TF2_SetNextNoiseMakerTime(this.index, time);
	}
	
	public void IncrementRespawnTouchCount()
	{
		TF2_IncrementRespawnTouchCount(this.index);
	}
	
	public void DecrementRespawnTouchCount()
	{
		TF2_DecrementRespawnTouchCount(this.index);
	}
	
	public int GetRespawnTouchCount()
	{
		return TF2_GetRespawnTouchCount(this.index);
	}
	
	public float GetPercentInvisible()
	{
		return TF2_GetPercentInvisible(this.index);
	}
	
	public int GetHealerByIndex(int index)
	{
		return TF2_GetHealerByIndex(this.index, index);
	}
	
	public bool AddToSpyCloakMeter(float val)
	{
		return TF2_AddToSpyCloakMeter(this.index, val);
	}
}

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

stock int TF2_GiveAmmo(int client, int iCount, int iAmmoIndex, bool bSuppressSound = false)
{
	return GivePlayerAmmo(client, iCount, iAmmoIndex, bSuppressSound);
}

stock void TF2_SetClassMenuOpen(int client, bool bOpen)
{
	//TODO: set offset of m_bIsClassMenuOpen instead
	FakeClientCommand(client, bOpen ? "menuopen" : "menuclosed");
}

stock bool TFPlayer_ShouldCollide(int client, int collisionGroup, int contentsMask)
{
	if ((collisionGroup == COLLISION_GROUP_PLAYER_MOVEMENT && FindConVar("tf_avoidteammates").BoolValue) || collisionGroup == TFCOLLISION_GROUP_ROCKETS || collisionGroup == TFCOLLISION_GROUP_ROCKET_BUT_NOT_WITH_OTHER_ROCKETS)
	{
		switch(TF2_GetClientTeam(client))
		{
			case TFTeam_Red:
			{
				if (!(contentsMask & CONTENTS_REDTEAM))
					return false;
			}
			case TFTeam_Blue:
			{
				if (!(contentsMask & CONTENTS_BLUETEAM))
					return false;
			}
		}
	}
	
	return BaseEntity_ShouldCollide(client, collisionGroup, contentsMask);
}

stock void TF2_HandleCommand_JoinClass(int client, const char[] pClassName, bool bAllowSpawn = true)
{
	if (GameRules_GetRoundState() == RoundState_GameOver)
		return;
	
	//MISSING: if ( TFGameRules()->IsCompetitiveMode() )
	
	if (TF2_IsCoaching(client))
		return;
	
	if (GetClientTeam(client) <= LAST_SHARED_TEAM && TF2_IsInArenaMode() == false)
		return;
	
	TF2_SetClassMenuOpen(client, false);
	
	if (TeamplayRoundBasedRules_InStalemate() && TF2_IsInArenaMode() == false)
	{
		if (IsPlayerAlive(client)) //MISSING: !TFGameRules()->CanChangeClassInStalemate()
		{
			char szTime[6];
			Format(szTime, sizeof(szTime), "%d", FindConVar("tf_stalematechangeclasstime").IntValue);
			
			PrintToChat(client, "#game_stalemate_cant_change_class", szTime);
			return;
		}
	}
	
	//TODO: the rest
}

stock void TF2_TeleportEffect(int client)
{
	TF2_AddCondition(client, TFCond_TeleportedGlow);
	
	float flDuration = 12.0;
	
	if (TF2_IsMannVsMachineMode() && GetEntProp(client, Prop_Send, "m_bIsABot") == 1) //MISSING: IsBotOfType
		flDuration = 30.0;
	
	//In game code, this is a think context, but what's the point in doing that when you can set a duration?
	CreateTimer(flDuration, Timer_RemoveTeleportEffect, client, TIMER_FLAG_NO_MAPCHANGE);
}

stock void TF2_RemoveTeleportEffect(int client)
{
	TF2_RemoveCondition(client, TFCond_TeleportedGlow);
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

static Action Timer_RemoveTeleportEffect(Handle timer, any data)
{
	if (IsClientInGame(data))
		TF2_RemoveTeleportEffect(data);
	
	return Plugin_Stop;
}