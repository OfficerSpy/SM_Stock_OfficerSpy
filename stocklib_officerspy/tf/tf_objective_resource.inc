/* Allows for manipulation of the wavebar.
You must pass in the entity index of the tf_objective_resource entity as a parameter (iResource) in order for this to work.
For best accuracy, these should be called once after CPopulationManager::UpdateObjectiveResource
However, seems calling increments and decrements dircetly after it causes it to stack for some reason
It's better to just set them to a constant number to enforce a consistent value instead */

#if defined _stock_officerspy_tfobjectiveresource_included
	#endinput
#endif
#define _stock_officerspy_tfobjectiveresource_included

#include <stocklib_officerspy/team_objectiveresource>
#include <stocklib_officerspy/shared/tf_shareddefs>

#if !defined TFOR_TELEPORTER_STRING
#define TFOR_TELEPORTER_STRING	"teleporter"
#endif

methodmap OSTFObjectiveResource < OSBaseTeamObjectiveResource
{
	public OSTFObjectiveResource(int index)
	{
		return view_as<OSTFObjectiveResource>(index);
	}
	
	public void SetMannVsMachineMaxWaveCount(int nCount)
	{
		TF2_SetMannVsMachineMaxWaveCount(this.index, nCount);
	}
	
	public int GetMannVsMachineMaxWaveCount()
	{
		return TF2_GetMannVsMachineMaxWaveCount(this.index);
	}
	
	public void SetMannVsMachineWaveCount(int nCount)
	{
		TF2_SetMannVsMachineWaveCount(this.index, nCount);
	}
	
	public int GetMannVsMachineWaveCount()
	{
		return TF2_GetMannVsMachineWaveCount(this.index);
	}
	
	public void SetMannVsMachineWaveEnemyCount(int nCount)
	{
		TF2_SetMannVsMachineWaveEnemyCount(this.index, nCount);
	}
	
	public int GetMannVsMachineWaveEnemyCount()
	{
		return TF2_GetMannVsMachineWaveEnemyCount(this.index);
	}
	
	public void AddMvMWorldMoney(int nCurrency)
	{
		TF2_AddMvMWorldMoney(this.index, nCurrency);
	}
	
	public void SetMannVsMachineNextWaveTime(float flTime)
	{
		TF2_SetMannVsMachineNextWaveTime(this.index, flTime);
	}
	
	public void SetMannVsMachineBetweenWaves(bool bVal)
	{
		TF2_SetMannVsMachineBetweenWaves(this.index, bVal);
	}
	
	public bool GetMannVsMachineIsBetweenWaves()
	{
		return TF2_GetMannVsMachineIsBetweenWaves(this.index);
	}
	
	public void GetMannVsMachineWaveClassName(int nIndex, char[] buffer, int maxlen)
	{
		TF2_GetMannVsMachineWaveClassName(this.index, nIndex, buffer, maxlen);
	}
	
	public int GetMannVsMachineWaveClassFlags(int nIndex)
	{
		return TF2_GetMannVsMachineWaveClassFlags(this.index, nIndex);
	}
	
	public void SetFlagCarrierUpgradeLevel(int nLevel)
	{
		TF2_SetFlagCarrierUpgradeLevel(this.index, nLevel);
	}
	
	public int GetFlagCarrierUpgradeLevel()
	{
		return TF2_GetFlagCarrierUpgradeLevel(this.index);
	}
	
	public void SetBaseMvMBombUpgradeTime(float nTime)
	{
		TF2_SetBaseMvMBombUpgradeTime(this.index, nTime);
	}
	
	public float GetBaseMvMBombUpgradeTime()
	{
		return TF2_GetBaseMvMBombUpgradeTime(this.index);
	}
	
	public void SetNextMvMBombUpgradeTime(float nTime)
	{
		TF2_SetNextMvMBombUpgradeTime(this.index, nTime);
	}
	
	public float GetNextMvMBombUpgradeTime()
	{
		return TF2_GetNextMvMBombUpgradeTime(this.index);
	}
	
	public void SetMannVsMachineChallengeIndex(int iIndex)
	{
		TF2_SetMannVsMachineChallengeIndex(this.index, iIndex);
	}
	
	public int GetMannVsMachineChallengeIndex()
	{
		return TF2_GetMannVsMachineChallengeIndex(this.index);
	}
	
	public void SetMvMPopfileName(char[] iszMvMPopfileName)
	{
		TF2_SetMvMPopfileName(this.index, iszMvMPopfileName);
	}
	
	public void GetMvMPopfileName(char[] buffer, int maxlen)
	{
		TF2_GetMvMPopfileName(this.index, buffer, maxlen);
	}
	
	public void SetMannVsMachineEventPopfileType(int nType)
	{
		TF2_SetMannVsMachineEventPopfileType(this.index, nType);
	}
	
	public void ClearMannVsMachineWaveClassFlags()
	{
		TF2_ClearMannVsMachineWaveClassFlags(this.index);
	}
	
	public void AddMannVsMachineWaveClassFlags(int index, int flags)
	{
		TF2_AddMannVsMachineWaveClassFlags(this.index, index, flags);
	}
	
	public int GetMannVsMachineWaveClassCount(int index)
	{
		return TF2_GetMannVsMachineWaveClassCount(this.index, index);
	}
	
	public void SetMannVsMachineWaveClassActive(char[] classIconName, bool active = true)
	{
		TF2_SetMannVsMachineWaveClassActive(this.index, classIconName, active);
	}
	
	public void SetMannVsMachineWaveClassCount(int index, int count)
	{
		TF2_SetMannVsMachineWaveClassCount(this.index, index, count);
	}
	
	public void SetMannVsMachineWaveClassName(int index, char[] classIconName)
	{
		TF2_SetMannVsMachineWaveClassName(this.index, index, classIconName);
	}
	
	public void IncrementMannVsMachineWaveClassCount(char[] classIconName, int flags)
	{
		TF2_IncrementMannVsMachineWaveClassCount(this.index, classIconName, flags);
	}
	
	public void DecrementMannVsMachineWaveClassCount(char[] classIconName, int flags)
	{
		TF2_DecrementMannVsMachineWaveClassCount(this.index, classIconName, flags);
	}
	
	public void IncrementTeleporterCount()
	{
		TF2_IncrementTeleporterCount(this.index);
	}
	
	public void DecrementTeleporterCount()
	{
		TF2_DecrementTeleporterCount(this.index);
	}
	
	public void GetTeleporterString(int iResource, char[] buffer, int maxlen)
	{
		TF2_GetTeleporterString(this.index, buffer, maxlen);
	}
}

stock void TF2_SetMannVsMachineMaxWaveCount(int iResource, int nCount)
{
	SetEntProp(iResource, Prop_Send, "m_nMannVsMachineMaxWaveCount", nCount);
}

stock int TF2_GetMannVsMachineMaxWaveCount(int iResource)
{
	return GetEntProp(iResource, Prop_Send,	"m_nMannVsMachineMaxWaveCount");
}

stock void TF2_SetMannVsMachineWaveCount(int iResource, int nCount)
{
	SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveCount", nCount);
}

stock int TF2_GetMannVsMachineWaveCount(int iResource)
{
	return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveCount");
}

stock void TF2_SetMannVsMachineWaveEnemyCount(int iResource, int nCount)
{
	SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", nCount);
}

stock int TF2_GetMannVsMachineWaveEnemyCount(int iResource)
{
	return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount");
}

stock void TF2_AddMvMWorldMoney(int iResource, int nCurrency)
{
	SetEntProp(iResource, Prop_Send, "m_nMvMWorldMoney", GetEntProp(iResource, Prop_Send, "m_nMvMWorldMoney") + nCurrency);
}

stock void TF2_SetMannVsMachineNextWaveTime(int iResource, float flTime)
{
	SetEntPropFloat(iResource, Prop_Send, "m_flMannVsMachineNextWaveTime", flTime);
}

stock void TF2_SetMannVsMachineBetweenWaves(int iResource, bool bVal)
{
	SetEntProp(iResource, Prop_Send, "m_bMannVsMachineBetweenWaves", bVal);
}

stock bool TF2_GetMannVsMachineIsBetweenWaves(int iResource)
{
	return view_as<bool>(GetEntProp(iResource, Prop_Send, "m_bMannVsMachineBetweenWaves"));
}

stock void TF2_GetMannVsMachineWaveClassName(int iResource, int nIndex, char[] buffer, int maxlen)
{
	GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", buffer, maxlen, nIndex);
}

stock int TF2_GetMannVsMachineWaveClassFlags(int iResource, int nIndex)
{
	return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, nIndex);
}

stock void TF2_SetFlagCarrierUpgradeLevel(int iResource, int nLevel)
{
	SetEntProp(iResource, Prop_Send, "m_nFlagCarrierUpgradeLevel", nLevel);
}

stock int TF2_GetFlagCarrierUpgradeLevel(int iResource)
{
	return GetEntProp(iResource, Prop_Send, "m_nFlagCarrierUpgradeLevel");
}

stock void TF2_SetBaseMvMBombUpgradeTime(int iResource, float nTime)
{
	SetEntPropFloat(iResource, Prop_Send, "m_flMvMBaseBombUpgradeTime", nTime);
}

stock float TF2_GetBaseMvMBombUpgradeTime(int iResource)
{
	return GetEntPropFloat(iResource, Prop_Send, "m_flMvMBaseBombUpgradeTime");
}

stock void TF2_SetNextMvMBombUpgradeTime(int iResource, float nTime)
{
	SetEntPropFloat(iResource, Prop_Send, "m_flMvMNextBombUpgradeTime", nTime);
}

stock float TF2_GetNextMvMBombUpgradeTime(int iResource)
{
	return GetEntPropFloat(iResource, Prop_Send, "m_flMvMNextBombUpgradeTime");
}

stock void TF2_SetMannVsMachineChallengeIndex(int iResource, int iIndex)
{
	SetEntProp(iResource, Prop_Send, "m_iChallengeIndex", iIndex);
}

stock int TF2_GetMannVsMachineChallengeIndex(int iResource)
{
	return GetEntProp(iResource, Prop_Send, "m_iChallengeIndex");
}

stock void TF2_SetMvMPopfileName(int iResource, char[] iszMvMPopfileName)
{
	SetEntPropString(iResource, Prop_Send, "m_iszMvMPopfileName", iszMvMPopfileName);
}

stock void TF2_GetMvMPopfileName(int iResource, char[] buffer, int maxlen)
{
	GetEntPropString(iResource, Prop_Send, "m_iszMvMPopfileName", buffer, maxlen);
}

stock void TF2_SetMannVsMachineEventPopfileType(int iResource, int nType)
{
	SetEntProp(iResource, Prop_Send, "m_nMvMEventPopfileType", nType);
}

stock void TF2_ClearMannVsMachineWaveClassFlags(int iResource)
{
	int waveClassFlagsCount = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags");
	
	int i = 0;
	for (i = 0; i < waveClassFlagsCount; i++)
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", MVM_CLASS_FLAG_NONE, _, i);
	
	int waveClassFlags2Count = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2");
	
	for (i = 0; i < waveClassFlags2Count; i++)
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", MVM_CLASS_FLAG_NONE, _, i);
}

stock void TF2_AddMannVsMachineWaveClassFlags(int iResource, int index, int flags)
{
	int waveClassFlagsCount = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags");
	
	if (index < waveClassFlagsCount)
	{
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, index);
		
		waveClassFlags |= flags;
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", waveClassFlags, _, index);
		return;
	}
	index -= waveClassFlagsCount;
	
	int waveClassFlags2Count = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2");
	
	if (index < waveClassFlags2Count)
	{
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, index);
		
		waveClassFlags |= flags;
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", waveClassFlags, _, index);
		return;
	}
}

stock int TF2_GetMannVsMachineWaveClassCount(int iResource, int index)
{
	int waveClassCountsCount = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	
	if (index < waveClassCountsCount)
		return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, index);
	
	index -= waveClassCountsCount;
	
	int waveClassCounts2Count = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2");
	
	if (index < waveClassCounts2Count)
		return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, index);
	
	return 0;
}

stock void TF2_SetMannVsMachineWaveClassActive(int iResource, char[] classIconName, bool active = true)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	for (int i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
		
		if (StrEqual(waveClassNamesString, classIconName))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", active, _, i);
			return;
		}
	}
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	for (int i = 0; i < waveClassNames2Count; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
		
		if (StrEqual(waveClassNamesString, classIconName))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", active, _, i);
			return;
		}
	}
}

stock void TF2_SetMannVsMachineWaveClassCount(int iResource, int index, int count)
{
	int waveClassCountsCount = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	
	if (index < waveClassCountsCount)
	{
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", count, _, index);
		return;
	}
	index -= waveClassCountsCount;
	
	int waveClassCounts2Count = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2");
	
	if (index < waveClassCounts2Count)
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", count, _, index);
}

stock void TF2_SetMannVsMachineWaveClassName(int iResource, int index, char[] classIconName)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	if (index < waveClassNamesCount)
	{
		SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", classIconName, index);
		return;
	}
	index -= waveClassNamesCount;
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	if (index < waveClassNames2Count)
		SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", classIconName, index);
}

stock void TF2_IncrementMannVsMachineWaveClassCount(int iResource, char[] classIconName, int flags)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	int i = 0;
	for (i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", currentCount + 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", 1, _, i);
			
			return;
		}
	}
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	for (i = 0; i < waveClassNames2Count; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", currentCount + 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", 1, _, i);
			
			return;
		}
	}
}

stock void TF2_DecrementMannVsMachineWaveClassCount(int iResource, char[] classIconName, int flags)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	int i = 0;
	for (i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", currentCount - 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", 0, _, i);
			
			if (!currentCount)
				TF2_SetMannVsMachineWaveClassActive(iResource, classIconName, false);
			
			return;
		}
	}
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	for (i = 0; i < waveClassNames2Count; i++)
	{
		char waveClassNamesString[PLATFORM_MAX_PATH]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", currentCount - 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", 0, _, i);
			
			if (!currentCount)
				TF2_SetMannVsMachineWaveClassActive(iResource, classIconName, false);
			
			return;
		}
	}
}

stock void TF2_IncrementTeleporterCount(int iResource)
{
	TF2_IncrementMannVsMachineWaveClassCount(iResource, TFOR_TELEPORTER_STRING, MVM_CLASS_FLAG_MISSION);
}

stock void TF2_DecrementTeleporterCount(int iResource)
{
	TF2_DecrementMannVsMachineWaveClassCount(iResource, TFOR_TELEPORTER_STRING, MVM_CLASS_FLAG_MISSION);
}

stock void TF2_GetTeleporterString(int iResource, char[] buffer, int maxlen)
{
	strcopy(buffer, maxlen, TFOR_TELEPORTER_STRING);
}

stock int TF2_TFObjectiveResource()
{
	return FindEntityByClassname(-1, "tf_objective_resource");
}

//The functions below are extra and are not based on code from the game

//Adds a custom tank icon to the wavebar, replacing the default one
stock void TF2_AddCustomTankIcon(int iResource, char[] name, int count, bool isCrit = false, bool isBoss = true, isSupport = false, isSupportLimited = false)
{
	int flags = MVM_CLASS_FLAG_NORMAL;
	
	if (isCrit)
		flags = flags | MVM_CLASS_FLAG_ALWAYSCRIT;
	
	if (isBoss)
		flags = flags | MVM_CLASS_FLAG_MINIBOSS;
	
	if (isSupport)
		flags = flags | MVM_CLASS_FLAG_SUPPORT;
	
	if (isSupportLimited)
		flags = flags | MVM_CLASS_FLAG_SUPPORT_LIMITED;
	
	TF2_DecrementWaveIconSpawnCount(iResource, "tank", MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS | (isSupport ? MVM_CLASS_FLAG_SUPPORT : 0) | (isSupportLimited ? MVM_CLASS_FLAG_SUPPORT_LIMITED : 0), count, false);
	TF2_IncrementWaveIconSpawnCount(iResource, name, flags, count, false);
}

// Get wavebar spawn count of an icon with specified name and flags
stock int TF2_GetWaveIconSpawnCount(int iResource, char[] name, int flags)
{
	int sizeArray = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	char classNames[128];
	
	for (int i = 0; i < sizeArray /* * 2 */; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", classNames, sizeof(classNames), i);
		
		if (StrEqual(classNames, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
			return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
	}
	
	for (int i = 0; i < sizeArray /* * 2 */; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", classNames, sizeof(classNames), i);
		
		if (StrEqual(classNames, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
			return GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
	}
	
	return 0;
}

// Set wavebar spawn count of an icon with specified name and flags
// If count is set to 0, removes the icon from the wavebar
// Can be used to put custom icons on a wavebar
stock void TF2_SetWaveIconSpawnCount(int iResource, char[] name, int flags, int count, bool changeMaxEnemyCount = true)
{
	int sizeArray = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	char nameSlot[128];
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, "") && count > 0)
		{
			SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", name, i);
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", count, _, i);
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", flags, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count);
			
			return;
		}
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", count, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count - preCount);
			
			if (count <= 0)
			{
				SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", "", i);
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", 0, _, i);
				SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", false, _, i);
			}
			
			return;
		}
	}
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, "") && count > 0)
		{
			SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", name, i);
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", count, _, i);
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", flags, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count);
			
			return;
		}
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", count, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count - preCount);
			
			if (count <= 0)
			{
				SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", "", i);
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", 0, _, i);
				SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", false, _, i);
			}
			
			return;
		}
	}
}

// Increment wavebar spawn count of an icon with specified name and flags
// Can be used to put custom icons on a wavebar
stock void TF2_IncrementWaveIconSpawnCount(int iResource, char[] name, int flags, int count = 1, bool changeMaxEnemyCount = true)
{
	TF2_SetWaveIconSpawnCount(iResource, name, flags, TF2_GetWaveIconSpawnCount(iResource, name, flags) + count, changeMaxEnemyCount);
}

// Increment wavebar spawn count of an icon with specified name and flags
// Use it to decrement the spawn count when the enemy is killed. Should not be used for support type icons
stock void TF2_DecrementWaveIconSpawnCount(int iResource, char[] name, int flags, int count = 1, bool changeMaxEnemyCount = false)
{
	int sizeArray = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	char nameSlot[128];
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", preCount - count > 0 ? preCount - count : 0, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") - (count > preCount ? preCount : count));
			
			if (preCount - count <= 0)
			{
				SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", "", i);
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", 0, _, i);
				SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", false, _, i);
			}
			
			return;
		}
	}
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", preCount - count > 0 ? preCount - count : 0, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL | MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") - (count > preCount ? preCount : count));
			
			if (preCount - count <= 0)
			{
				SetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", "", i);
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", 0, _, i);
				SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", false, _, i);
			}
			
			return;
		}
	}
}

// Used for mission and support limited bots to display them on a wavebar during the wave, set by the game automatically when an enemy with this icon spawn
stock void TF2_SetWaveIconActive(int iResource, char[] name, int flags, bool active)
{
	int sizeArray = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	char nameSlot[128];
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", active, _, i);
			return;
		}
	}
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", active, _, i);
			return;
		}
	}
}

// Used for mission and support limited bots to display them on a wavebar during the wave, set by the game automatically when an enemy with this icon spawn
stock bool TF2_GetWaveIconActive(int iResource, char[] name, int flags)
{
	int sizeArray = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts");
	char nameSlot[128];
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
			return view_as<bool>(GetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", _, i));
	}
	
	for (int i = 0; i < sizeArray; i++)
	{
		GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", nameSlot, sizeof(nameSlot), i);
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
			return view_as<bool>(GetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", _, i));
	}
	
	return false;
}