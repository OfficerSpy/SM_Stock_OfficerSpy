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
	
	public int GiveAmmo(int iCount, int iAmmoIndex, bool bSuppressSound = false)
	{
		return GivePlayerAmmo(this.index, iCount, iAmmoIndex, bSuppressSound);
	}
	
	public void RemoveAmmo(int iCount, int iAmmoIndex)
	{
		BaseCombatCharacter_RemoveAmmo(this.index, iCount, iAmmoIndex);
	}
	
	public void RemoveAllAmmo()
	{
		BaseCombatCharacter_RemoveAllAmmo(this.index);
	}
	
	public int GetAmmoCount(int iAmmoIndex)
	{
		return BaseCombatCharacter_GetAmmoCount(this.index, iAmmoIndex);
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
	
	public void SetAmmoCount(int iCount, int iAmmoIndex)
	{
		BaseCombatCharacter_SetAmmoCount(this.index, iCount, iAmmoIndex);
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

stock int BaseCombatCharacter_GiveAmmo(int entity, int iCount, int iAmmoIndex, bool bSuppressSound = false)
{
	return GivePlayerAmmo(entity, iCount, iAmmoIndex, bSuppressSound);
}

stock void BaseCombatCharacter_RemoveAmmo(int entity, int iCount, int iAmmoIndex)
{
	if (iCount <= 0)
		return;
	
	//MISSING: if ( GetAmmoDef()->MaxCarry( iAmmoIndex ) == INFINITE_AMMO )
	
	SetEntProp(entity, Prop_Data, "m_iAmmo", MaxInt(GetEntProp(entity, Prop_Data, "m_iAmmo", _, iAmmoIndex) - iCount, 0), _, iAmmoIndex);
}

stock void BaseCombatCharacter_RemoveAllAmmo(int entity)
{
	for (int i = 0; i < MAX_AMMO_SLOTS; i++)
	{
		SetEntProp(entity, Prop_Data, "m_iAmmo", 0, _, i);
	}
}

stock int BaseCombatCharacter_GetAmmoCount(int entity, int iAmmoIndex)
{
	if (iAmmoIndex == -1)
		return 0;
	
	//MISSING: if ( GetAmmoDef()->MaxCarry( iAmmoIndex ) == INFINITE_AMMO )
	
	return GetEntProp(entity, Prop_Data, "m_iAmmo", _, iAmmoIndex);
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

stock void BaseCombatCharacter_SetAmmoCount(int entity, int iCount, int iAmmoIndex)
{
	SetEntProp(entity, Prop_Data, "m_iAmmo", iCount, _, iAmmoIndex);
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