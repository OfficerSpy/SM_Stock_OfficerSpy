#if defined _stock_officerspy_tfobj_included
	#endinput
#endif
#define _stock_officerspy_tfobj_included

#include <stocklib_officerspy/other/cpp_valve>

#if !defined OBJ_MAX_UPGRADE_LEVEL
#define OBJ_MAX_UPGRADE_LEVEL	3
#endif

stock bool BaseObject_IsBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bBuilding"));
}

stock bool BaseObject_IsPlacing(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bPlacing"));
}

stock bool BaseObject_IsCarried(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bCarried"));
}

stock bool BaseObject_GetObjectFlags(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_fObjectFlags"));
}

stock void BaseObject_SetObjectFlags(int entity, int flags)
{
	SetEntProp(entity, Prop_Send, "m_fObjectFlags", flags);
}

stock bool BaseObject_IsDisabled(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bDisabled") || GetEntProp(entity, Prop_Send, "m_bCarried"));
}

stock void BaseObject_IncrementKills(int entity)
{
	SetEntProp(entity, Prop_Send, "m_iKills", GetEntProp(entity, Prop_Send, "m_iKills") + 1);
}

stock int BaseObject_GetKills(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iKills");
}

stock void BaseObject_IncrementAssists(int entity)
{
	SetEntProp(entity, Prop_Send, "m_iAssists", GetEntProp(entity, Prop_Send, "m_iAssists") + 1);
}

stock int BaseObject_GetAssists(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iAssists");
}

stock int BaseObject_GetUpgradeLevel(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iUpgradeLevel");
}

stock int BaseObject_GetUpgradeMetal(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iUpgradeMetal");
}

stock int BaseObject_GetHighestUpgradeMetal(int entity)
{
	return MinInt(GetEntProp(entity, Prop_Send, "m_iHighestUpgradeLevel"), BaseObject_GetMaxUpgradeLevel());
}

stock void BaseObject_SetHighestUpgradeLevel(int entity, int nLevel)
{
	SetEntProp(entity, Prop_Send, "m_iHighestUpgradeLevel", MinInt(nLevel, BaseObject_GetMaxUpgradeLevel()));
}

stock int BaseObject_GetMaxUpgradeLevel()
{
	return OBJ_MAX_UPGRADE_LEVEL;
}

stock int BaseObject_GetMiniBuildingStartingHealth()
{
	return 100;
}

stock bool BaseObject_IsBuiltOnAttachment(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuiltOnEntity") != -1;
}

stock int BaseObject_GetBuiltOnObject(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hBuiltOnEntity");
}

stock void BaseObject_SetObjectMode(int entity, int iVal)
{
	SetEntProp(entity, Prop_Send, "m_iObjectMode", iVal);
}

stock int BaseObject_GetObjectMode(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iObjectMode");
}

stock bool BaseObject_IsMiniBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bMiniBuilding"));
}

stock bool BaseObject_IsDisposableBuilding(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bDisposableBuilding"));
}

stock bool BaseObject_IsMapPlaced(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bWasMapPlaced"));
}

stock bool BaseObject_CanBeRepaired(int entity)
{
	return !BaseObject_IsDisposableBuilding(entity);
}

stock bool BaseObject_CanBeUpgraded(int entity)
{
	return !(BaseObject_IsDisposableBuilding(entity) || BaseObject_IsMiniBuilding(entity));
}