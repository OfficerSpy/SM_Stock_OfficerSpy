#if defined _stock_officerspy_tfobj_included
	#endinput
#endif
#define _stock_officerspy_tfobj_included

#include <tf2_stocks>
#include <sdkhooks>
#include <stocklib_officerspy/basecombatcharacter>
#include <stocklib_officerspy/other/cpp_valve>

#if !defined OBJ_MAX_UPGRADE_LEVEL
#define OBJ_MAX_UPGRADE_LEVEL	3
#endif

methodmap OSBaseObject < OSBaseCombatCharacter
{
	public OSBaseObject(int index)
	{
		return view_as<OSBaseObject>(index);
	}
	
	public bool IsBuilding()
	{
		return TF2_IsBuilding(this.index);
	}
	
	public bool IsPlacing()
	{
		return TF2_IsPlacing(this.index);
	}
	
	public bool IsCarried()
	{
		return TF2_IsCarried(this.index);
	}
	
	public bool HasSapper()
	{
		return TF2_HasSapper(this.index);
	}
	
	public bool IsPlasmaDisabled()
	{
		return TF2_IsPlasmaDisabled(this.index);
	}
	
	public int GetObjectFlags()
	{
		return TF2_GetObjectFlags(this.index);
	}
	
	public void SetObjectFlags(int flags)
	{
		TF2_SetObjectFlags(this.index, flags);
	}
	
	public bool IsDisabled()
	{
		return TF2_IsDisabled(this.index);
	}
	
	public void IncrementKills()
	{
		TF2_IncrementKills(this.index);
	}
	
	public int GetKills()
	{
		return TF2_GetKills(this.index);
	}
	
	public void IncrementAssists()
	{
		TF2_IncrementAssists(this.index);
	}
	
	public int GetAssists()
	{
		return TF2_GetAssists(this.index);
	}
	
	public int GetUpgradeLevel()
	{
		return TF2_GetUpgradeLevel(this.index);
	}
	
	public int GetUpgradeMetal()
	{
		return TF2_GetUpgradeMetal(this.index);
	}
	
	public int GetHighestUpgradeMetal()
	{
		return TF2_GetHighestUpgradeMetal(this.index);
	}
	
	public void SetHighestUpgradeLevel(int nLevel)
	{
		TF2_SetHighestUpgradeLevel(this.index, nLevel);
	}
	
	public int GetMaxUpgradeLevel()
	{
		return TF2_GetMaxUpgradeLevel();
	}
	
	/* public int GetMiniBuildingStartingHealth()
	{
		return TF2_GetMiniBuildingStartingHealth();
	} */
	
	public bool IsBuiltOnAttachment()
	{
		return TF2_IsBuiltOnAttachment(this.index);
	}
	
	public int GetBuiltOnObject()
	{
		return TF2_GetBuiltOnObject(this.index);
	}
	
	public void SetObjectMode(int iVal)
	{
		TF2_SetObjectMode(this.index, iVal)
	}
	
	public TFObjectMode GetObjectMode()
	{
		return TF2_GetObjectMode(this.index);
	}
	
	public bool IsMiniBuilding()
	{
		return TF2_IsMiniBuilding(this.index);
	}
	
	public bool IsDisposableBuilding()
	{
		return TF2_IsDisposableBuilding(this.index);
	}
	
	public bool IsMapPlaced()
	{
		return TF2_IsMapPlaced(this.index);
	}
	
	public bool CanBeRepaired()
	{
		return TF2_CanBeRepaired(this.index);
	}
	
	public bool CanBeUpgraded()
	{
		return TF2_CanBeUpgraded(this.index);
	}
	
	public int GetOwner()
	{
		return TF2_GetOwner(this.index);
	}
	
	public void SetBuilder(int pBuilder)
	{
		TF2_SetBuilder(this.index, pBuilder);
	}
	
	public TFObjectType ObjectType()
	{
		return TF2_GetObjectType(this.index);
	}
	
	public void DetonateObject()
	{
		TF2_DetonateObject(this.index);
	}
	
	public TFObjectType GetType()
	{
		return TF2_GetObjectType(this.index);
	}
	
	public int GetBuilder()
	{
		return TF2_GetBuilder(this.index);
	}
}

stock bool TF2_IsBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bBuilding"));
}

stock bool TF2_IsPlacing(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bPlacing"));
}

stock bool TF2_IsCarried(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bCarried"));
}

stock bool TF2_HasSapper(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bHasSapper"));
}

stock bool TF2_IsPlasmaDisabled(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bPlasmaDisable"));
}

stock int TF2_GetObjectFlags(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_fObjectFlags");
}

stock void TF2_SetObjectFlags(int entity, int flags)
{
	SetEntProp(entity, Prop_Send, "m_fObjectFlags", flags);
}

stock bool TF2_IsDisabled(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bDisabled") || GetEntProp(entity, Prop_Send, "m_bCarried"));
}

stock void TF2_IncrementKills(int entity)
{
	SetEntProp(entity, Prop_Send, "m_iKills", GetEntProp(entity, Prop_Send, "m_iKills") + 1);
}

stock int TF2_GetKills(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iKills");
}

stock void TF2_IncrementAssists(int entity)
{
	SetEntProp(entity, Prop_Send, "m_iAssists", GetEntProp(entity, Prop_Send, "m_iAssists") + 1);
}

stock int TF2_GetAssists(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iAssists");
}

stock int TF2_GetUpgradeLevel(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iUpgradeLevel");
}

stock int TF2_GetUpgradeMetal(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iUpgradeMetal");
}

stock int TF2_GetHighestUpgradeMetal(int entity)
{
	return MinInt(GetEntProp(entity, Prop_Send, "m_iHighestUpgradeLevel"), TF2_GetMaxUpgradeLevel());
}

stock void TF2_SetHighestUpgradeLevel(int entity, int nLevel)
{
	SetEntProp(entity, Prop_Send, "m_iHighestUpgradeLevel", MinInt(nLevel, TF2_GetMaxUpgradeLevel()));
}

stock int TF2_GetMaxUpgradeLevel()
{
	return OBJ_MAX_UPGRADE_LEVEL;
}

/* stock int TF2_GetMiniBuildingStartingHealth()
{
	return 100;
} */

stock bool TF2_IsBuiltOnAttachment(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuiltOnEntity") != -1;
}

stock int TF2_GetBuiltOnObject(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuiltOnEntity");
}

stock void TF2_SetObjectMode(int entity, int iVal)
{
	SetEntProp(entity, Prop_Send, "m_iObjectMode", iVal);
}

#pragma deprecated Use TF2_GetObjectMode instead
stock TFObjectMode BaseObject_GetObjectMode(int entity)
{
	return view_as<TFObjectMode>(GetEntProp(entity, Prop_Send, "m_iObjectMode"));
}

stock bool TF2_IsMiniBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bMiniBuilding"));
}

stock bool TF2_IsDisposableBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bDisposableBuilding"));
}

stock bool TF2_IsMapPlaced(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bWasMapPlaced"));
}

stock bool TF2_CanBeRepaired(int entity)
{
	return !TF2_IsDisposableBuilding(entity);
}

stock bool TF2_CanBeUpgraded(int entity)
{
	return !(TF2_IsDisposableBuilding(entity) || TF2_IsMiniBuilding(entity));
}

stock int TF2_GetOwner(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuilder");
}

stock void TF2_SetBuilder(int entity, int pBuilder)
{
	//Firing input SetBuilder would be safer as it adds the object to the player's object array
	//But it also changes the object's team
	SetEntPropEnt(entity, Prop_Send, "m_hBuilder", pBuilder);
}

#pragma deprecated Use TF2_GetObjectType instead
stock TFObjectType TF2_ObjectType(int entity)
{
	return view_as<TFObjectType>(GetEntProp(entity, Prop_Send, "m_iObjectType"));
}

stock void TF2_DetonateObject(int entity)
{
	float absOrigin[3]; BaseEntity_GetAbsOrigin(entity, absOrigin);
	
	SDKHooks_TakeDamage(entity, entity, entity, 0.0, DMG_GENERIC, _, NULL_VECTOR, absOrigin, false);
}

#pragma deprecated Use TF2_GetObjectType instead
stock TFObjectType BaseObject_GetType(int entity)
{
	return view_as<TFObjectType>(GetEntProp(entity, Prop_Send, "m_iObjectType"));
}

stock int TF2_GetBuilder(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuilder");
}