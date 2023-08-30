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