#pragma deprecated Use SetEntityOwner instead
stock void BaseEntity_SetOwnerEntity(int entity, int pOwner)
{
	SetEntPropEnt(entity, Prop_Send, "m_hOwnerEntity", pOwner);
}

stock void BaseEntity_ChangeTeam(int iTeamNum)
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