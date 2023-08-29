/* Allows for manipulation of the wavebar.
You must pass in the entity index of the tf_objective_resource entity as a parameter (iResource) in order for this to work.
For best accuracy, these should be called once after CPopulationManager::UpdateObjectiveResource
However, seems calling increments and decrements dircetly after it causes it to stack for some reason
It's better to just set them to a constant number to enforce a consistent value instead */
#include <stocklib_officerspy/shared/tf_shareddefs>

stock void TFOR_ClearMannVsMachineWaveClassFlags(int iResource)
{
	int waveClassFlagsCount = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags");
	
	int i = 0;
	for (i = 0; i < waveClassFlagsCount; i++)
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", MVM_CLASS_FLAG_NONE, _, i);
	
	int waveClassFlags2Count = GetEntPropArraySize(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2");
	
	for (i = 0; i < waveClassFlags2Count; i++)
		SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", MVM_CLASS_FLAG_NONE, _, i);
}

stock void TFOR_AddMannVsMachineWaveClassFlags(int iResource, int index, int flags)
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

stock int TFOR_GetMannVsMachineWaveClassCount(int iResource, int index)
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

stock void TFOR_SetMannVsMachineWaveClassActive(int iResource, char[] classIconName, bool active = true)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	for (int i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
		
		if (StrEqual(waveClassNamesString, classIconName))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive", active, _, i);
			return;
		}
	}
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	for (int i = 0; i < waveClassNames2Count; i++)
	{
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
		
		if (StrEqual(waveClassNamesString, classIconName))
		{
			SetEntProp(iResource, Prop_Send, "m_bMannVsMachineWaveClassActive2", active, _, i);
			return;
		}
	}
}

stock void TFOR_SetMannVsMachineWaveClassCount(int iResource, int index, int count)
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

stock void TFOR_SetMannVsMachineWaveClassName(int iResource, int index, char[] classIconName)
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

stock void TFOR_IncrementMannVsMachineWaveClassCount(int iResource, char[] classIconName, int flags)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	int i = 0;
	for (i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
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
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
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

stock void TFOR_DecrementMannVsMachineWaveClassCount(int iResource, char[] classIconName, int flags)
{
	int waveClassNamesCount = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames");
	
	int i = 0;
	for (i = 0; i < waveClassNamesCount; i++)
	{
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", currentCount - 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", 0, _, i);
			
			if (!currentCount)
				TFOR_SetMannVsMachineWaveClassActive(iResource, classIconName, false);
			
			return;
		}
	}
	
	int waveClassNames2Count = GetEntPropArraySize(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2");
	
	for (i = 0; i < waveClassNames2Count; i++)
	{
		char waveClassNamesString[256]; GetEntPropString(iResource, Prop_Data, "m_iszMannVsMachineWaveClassNames2", waveClassNamesString, sizeof(waveClassNamesString), i);
		int waveClassFlags = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i);
		
		if (StrEqual(waveClassNamesString, classIconName) && waveClassFlags & flags)
		{
			int currentCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", currentCount - 1, _, i);
			
			if (currentCount <= 0)
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", 0, _, i);
			
			if (!currentCount)
				TFOR_SetMannVsMachineWaveClassActive(iResource, classIconName, false);
			
			return;
		}
	}
}

stock void TFOR_IncrementTeleporterCount(int iResource)
{
	TFOR_IncrementMannVsMachineWaveClassCount(iResource, "teleporter", MVM_CLASS_FLAG_MISSION);
}

stock void TFOR_DecrementTeleporterCount(int iResource)
{
	TFOR_DecrementMannVsMachineWaveClassCount(iResource, "teleporter", MVM_CLASS_FLAG_MISSION);
}

//The functions below are extra and are not based on code from the game

//Adds a custom tank icon to the wavebar, replacing the default one
stock void TFOR_AddCustomTankIcon(int iResource, char[] name, int count, bool isCrit = false, bool isBoss = true, isSupport = false, isSupportLimited = false)
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
	
	TFOR_DecrementWaveIconSpawnCount(iResource, "tank", MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS|(isSupport ? MVM_CLASS_FLAG_SUPPORT : 0)|(isSupportLimited ? MVM_CLASS_FLAG_SUPPORT_LIMITED : 0), count, false);
	TFOR_IncrementWaveIconSpawnCount(iResource, name, flags, count, false);
}

// Get wavebar spawn count of an icon with specified name and flags
stock int TFOR_GetWaveIconSpawnCount(int iResource, char[] name, int flags)
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
stock void TFOR_SetWaveIconSpawnCount(int iResource, char[] name, int flags, int count, bool changeMaxEnemyCount = true)
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
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count);
			
			return;
		}
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts", count, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
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
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
				SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount", GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveEnemyCount") + count);
			
			return;
		}
		
		if (StrEqual(nameSlot, name) && (flags == 0 || GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassFlags2", _, i) == flags))
		{
			int preCount = GetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", _, i);
			
			SetEntProp(iResource, Prop_Send, "m_nMannVsMachineWaveClassCounts2", count, _, i);
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
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
stock void TFOR_IncrementWaveIconSpawnCount(int iResource, char[] name, int flags, int count = 1, bool changeMaxEnemyCount = true)
{
	TFOR_SetWaveIconSpawnCount(iResource, name, flags, TFOR_GetWaveIconSpawnCount(iResource, name, flags) + count, changeMaxEnemyCount);
}

// Increment wavebar spawn count of an icon with specified name and flags
// Use it to decrement the spawn count when the enemy is killed. Should not be used for support type icons
stock void TFOR_DecrementWaveIconSpawnCount(int iResource, char[] name, int flags, int count = 1, bool changeMaxEnemyCount = false)
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
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
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
			
			if (changeMaxEnemyCount && (flags & (MVM_CLASS_FLAG_NORMAL|MVM_CLASS_FLAG_MINIBOSS)))
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
stock void TFOR_SetWaveIconActive(int iResource, char[] name, int flags, bool active)
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
stock bool TFOR_GetWaveIconActive(int iResource, char[] name, int flags)
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