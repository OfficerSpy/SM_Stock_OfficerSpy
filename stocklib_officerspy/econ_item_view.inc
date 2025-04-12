#if defined _stock_officerspy_econitemview_included
	#endinput
#endif
#define _stock_officerspy_econitemview_included

static int m_iOffsetItemID = -1;

stock int EconItemView_GetID(int entity)
{
	return EconItemView_GetItemID(entity);
}

stock bool EconItemView_IsValid(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bInitialized"));
}

stock void EconItemView_Invalidate(int entity)
{
	GetClassPropertyOffsets();
	
	SetEntProp(entity, Prop_Send, "m_bInitialized", false);
	SetEntProp(entity, Prop_Send, "m_iItemDefinitionIndex", -1);
	
	SetEntData(entity, m_iOffsetItemID, -1);
}

stock void EconItemView_SetInitialized(int entity, bool bInit)
{
	SetEntProp(entity, Prop_Send, "m_bInitialized", bInit);
}

stock void EconItemView_SetItemDefIndex(int entity, int iIndex)
{
	SetEntProp(entity, Prop_Send, "m_iItemDefinitionIndex", iIndex);
	//MISSING: MarkDescriptionDirty()
}

stock int EconItemView_GetItemDefIndex(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iItemDefinitionIndex");
}

stock void EconItemView_SetItemQuality(int entity, int iQuality)
{
	// SetEntProp(entity, Prop_Send, "m_iEntityQuality", iQuality);
	
	//NOTE: for reasons unexplained, this property cannot be properly set with SetEntProp
	char serverClassname[64]; GetEntityNetClass(entity, serverClassname, sizeof(serverClassname));
	SetEntData(entity, FindSendPropInfo(serverClassname, "m_iEntityQuality"), iQuality);
	
	//MISSING: MarkDescriptionDirty()
}

stock int EconItemView_GetItemQuality(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iEntityQuality");
}

stock void EconItemView_SetItemLevel(int entity, int unLevel)
{
	// SetEntProp(entity, Prop_Send, "m_iEntityLevel", unLevel);
	
	//NOTE: for reasons unexplained, this property cannot be properly set with SetEntProp
	char serverClassname[64]; GetEntityNetClass(entity, serverClassname, sizeof(serverClassname));
	SetEntData(entity, FindSendPropInfo(serverClassname, "m_iEntityLevel"), unLevel);
	
	//MISSING: MarkDescriptionDirty()
}

stock int EconItemView_GetItemLevel(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iEntityLevel");
}

stock void EconItemView_SetItemID(int entity, int iIdx)
{
	GetClassPropertyOffsets();
	
	SetEntData(entity, m_iOffsetItemID, iIdx);
	
	//At this point, m_iItemID should be equal to our given parameter
	//So use it for the rest here instead of retrieving the data we just set ourselves
	SetEntProp(entity, Prop_Send, "m_iItemIDHigh", iIdx >> 32);
	SetEntProp(entity, Prop_Send, "m_iItemIDLow", iIdx & 0xFFFFFFFF);
}

stock int EconItemView_GetItemID(int entity)
{
	GetClassPropertyOffsets();
	
	return GetEntData(entity, m_iOffsetItemID);
}

stock int EconItemView_GetAccountID(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iAccountID");
}

stock void EconItemView_SetOverrideAccountID(int entity, int nAccountID)
{
	SetEntProp(entity, Prop_Send, "m_iAccountID", nAccountID);
}

static stock void GetClassPropertyOffsets()
{
	//m_iItemID
	if (m_iOffsetItemID < 0)
		m_iOffsetItemID = FindSendPropInfo("CEconItemView", "m_iItemIDHigh") - 4;
}