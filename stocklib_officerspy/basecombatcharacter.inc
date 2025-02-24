#if defined _stock_officerspy_basecombatcharacter_included
	#endinput
#endif
#define _stock_officerspy_basecombatcharacter_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/baseflex>

methodmap OSBaseCombatCharacter < OSBaseFlex
{
	public OSBaseCombatCharacter(int index)
	{
		return view_as<OSBaseCombatCharacter>(index);
	}
	
	public void AddGlowEffect()
	{
		BaseCombatCharacter_AddGlowEffect(this.index);
	}
	
	public void RemoveGlowEffect()
	{
		BaseCombatCharacter_RemoveGlowEffect(this.index);
	}
	
	public bool IsGlowEffectActive()
	{
		return BaseCombatCharacter_IsGlowEffectActive(this.index);
	}
	
	public int LastHitGroup()
	{
		return BaseCombatCharacter_LastHitGroup(this.index);
	}
	
	public void SetLastHitGroup(int nHitGroup)
	{
		BaseCombatCharacter_SetLastHitGroup(this.index, nHitGroup);
	}
	
	public int BloodColor()
	{
		return BaseCombatCharacter_BloodColor(this.index);
	}
	
	public void SetBloodColor(int nBloodColor)
	{
		BaseCombatCharacter_SetBloodColor(this.index, nBloodColor);
	}
	
	public int GetActiveWeapon()
	{
		return BaseCombatCharacter_GetActiveWeapon(this.index);
	}
	
	public void SetActiveWeapon(int pNewWeapon)
	{
		BaseCombatCharacter_SetActiveWeapon(this.index, pNewWeapon);
	}
	
	public void ClearActiveWeapon()
	{
		BaseCombatCharacter_ClearActiveWeapon(this.index);
	}
	
	public void RemoveAllWeapons()
	{
		BaseCombatCharacter_RemoveAllWeapons(this.index);
	}
}

stock void BaseCombatCharacter_AddGlowEffect(int entity)
{
	SetEntProp(entity, Prop_Send, "m_bGlowEnabled", true);
}

stock void BaseCombatCharacter_RemoveGlowEffect(int entity)
{
	SetEntProp(entity, Prop_Send, "m_bGlowEnabled", false);
}

stock bool BaseCombatCharacter_IsGlowEffectActive(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bGlowEnabled"));
}

stock int BaseCombatCharacter_LastHitGroup(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_LastHitGroup");
}

stock void BaseCombatCharacter_SetLastHitGroup(int entity, int nHitGroup)
{
	SetEntProp(entity, Prop_Data, "m_LastHitGroup", nHitGroup);
}

stock int BaseCombatCharacter_BloodColor(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_bloodColor");
}

stock void BaseCombatCharacter_SetBloodColor(int entity, int nBloodColor)
{
	SetEntProp(entity, Prop_Data, "m_bloodColor", nBloodColor);
}

stock int BaseCombatCharacter_GetActiveWeapon(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hActiveWeapon");
}

stock void BaseCombatCharacter_SetActiveWeapon(int entity, int pNewWeapon)
{
	int pOldWeapon = GetEntPropEnt(entity, Prop_Send, "m_hActiveWeapon");
	
	if (pNewWeapon != pOldWeapon)
	{
		SetEntPropEnt(entity, Prop_Send, "m_hActiveWeapon", pNewWeapon);
		//MISSING: OnChangeActiveWeapon
	}
}

stock void BaseCombatCharacter_ClearActiveWeapon(int entity)
{
	BaseCombatCharacter_SetActiveWeapon(entity, -1);
}

stock void BaseCombatCharacter_RemoveAllWeapons(int entity)
{
	BaseCombatCharacter_ClearActiveWeapon(entity);
	
	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		if (GetEntPropEnt(entity, Prop_Send, "m_hMyWeapons", i) != -1)
		{
			RemoveEntity(entity) //NOTE: CBaseCombatWeapon::Delete calls UTIL_Remove 0.1s later
			SetEntPropEnt(entity, Prop_Send, "m_hMyWeapons", -1, i);
		}
	}
}

// EXTRA UTILITY FUNCTIONS

stock bool OSLib_IsBaseCombatCharacter(int entity)
{
	//Rather obscure way of determing if this is CBCC
	return HasEntProp(entity, Prop_Data, "m_eHull");
}