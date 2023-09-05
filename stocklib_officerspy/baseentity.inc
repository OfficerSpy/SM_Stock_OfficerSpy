enum
{
	VISION_MODE_NONE = 0,
	VISION_MODE_PYRO,
	VISION_MODE_HALLOWEEN,
	VISION_MODE_ROME,
	MAX_VISION_MODES
};

stock void BaseEntity_ClearModelIndexOverrides(int entity)
{
	for (int i = 0; i < MAX_VISION_MODES; i++)
		SetEntProp(entity, Prop_Send, "m_nModelIndexOverrides", 0, _, i);
}

stock void BaseEntity_SetModelIndexOverride(int entity, int index, int nValue)
{
	SetEntProp(entity, Prop_Send, "m_nModelIndexOverrides", nValue, _, index);
}

#pragma deprecated Use SetEntityOwner instead
stock void BaseEntity_SetOwnerEntity(int entity, int pOwner)
{
	SetEntPropEnt(entity, Prop_Send, "m_hOwnerEntity", pOwner);
}

stock int BaseEntity_GetMaxHealth(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iMaxHealth");
}

stock void BaseEntity_SetMaxHealth(int entity, int amt)
{
	SetEntProp(entity, Prop_Data, "m_iMaxHealth", amt);
}

stock int BaseEntity_GetHealth(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iHealth");
}

stock void BaseEntity_SetHealth(int entity, int amt)
{
	SetEntProp(entity, Prop_Data, "m_iHealth", amt);
}

stock void BaseEntity_ChangeTeam(int entity, int iTeamNum)
{
	SetEntProp(entity, Prop_Send, "m_iTeamNum", iTeamNum);
}

stock int BaseEntity_GetMoveParent(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMoveParent");
}

stock int BaseEntity_FirstMoveChild(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMoveChild");
}

stock int BaseEntity_NextMovePeer(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMovePeer");
}

stock int BaseEntity_GetParent(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_pParent");
}

stock int BaseEntity_GetParentAttachment(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iParentAttachment");
}

stock void BaseEntity_GetEntityName(int entity, char[] buffer, int maxlen)
{
	GetEntPropString(entity, Prop_Data, "m_iName", buffer, maxlen);
}

//Alternatively, you can set the keyvalue "targetname"
stock void BaseEntity_SetName(int entity, char[] newName)
{
	SetEntPropString(entity, Prop_Data, "m_iName", newName);
}

stock int BaseEntity_GetSpawnFlags(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_spawnflags");
}

stock void BaseEntity_AddSpawnFlags(int entity, int nFlags)
{
	int flags = GetEntProp(entity, Prop_Data, "m_spawnflags");
	flags |= nFlags;
	SetEntProp(entity, Prop_Data, "m_spawnflags", flags);
}

stock void BaseEntity_RemoveSpawnFlags(int entity, int nFlags)
{
	int flags = GetEntProp(entity, Prop_Data, "m_spawnflags");
	flags &= ~nFlags;
	SetEntProp(entity, Prop_Data, "m_spawnflags", flags);
}

stock void BaseEntity_ClearSpawnFlags(int entity)
{
	SetEntProp(entity, Prop_Data, "m_spawnflags", 0);
}

stock bool BaseEntity_HasSpawnFlags(int entity, int nFlags)
{
	return GetEntProp(entity, Prop_Data, "m_spawnflags") & nFlags != 0;
}

stock void BaseEntity_GetLocalOrigin(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecOrigin", buffer);
}

stock void BaseEntity_GetLocalAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angRotation", buffer);
}

stock void BaseEntity_GetAbsOrigin(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAbsOrigin", buffer);	
}

stock void BaseEntity_GetAbsAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angAbsRotation", buffer);
}

stock void BaseEntity_GetLocalVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecVelocity", buffer);
}

stock void BaseEntity_GetAbsVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAbsVelocity", buffer);
}

stock void BaseEntity_GetLocalAngularVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAngVelocity", buffer);
}

stock void BaseEntity_GetBaseVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecBaseVelocity", buffer);
}

stock void BaseEntity_SetBaseVelocity(int entity, float vec[3])
{
	SetEntPropVector(entity, Prop_Data, "m_vecBaseVelocity", vec);
}

#pragma deprecated Use GetEntityGravity instead
stock float BaseEntity_GetGravity(int entity)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flGravity");
}

#pragma deprecated Use SetEntityGravity instead
stock void BaseEntity_SetGravity(int entity, float gravity)
{
	SetEntPropFloat(entity, Prop_Data, "m_flGravity", gravity);
}