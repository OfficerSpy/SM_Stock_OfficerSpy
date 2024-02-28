#if defined _stock_officerspy_baseentityshared_included
	#endinput
#endif
#define _stock_officerspy_baseentityshared_included

stock void BaseEntity_EyePosition(int entity, float buffer[3])
{
	float absOrigin[3]; GetEntPropVector(entity, Prop_Data, "m_vecAbsOrigin", absOrigin); //GetAbsOrigin
	float viewOffset[3]; GetEntPropVector(entity, Prop_Data, "m_vecViewOffset", viewOffset); //GetViewOffset
	
	AddVectors(absOrigin, viewOffset, buffer);
}

stock void BaseEntity_EyeAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angAbsRotation", buffer); //GetAbsAngles
}

stock void BaseEntity_LocalEyeAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angRotation", buffer); //GetLocalAngles
}

stock void BaseEntity_EarPosition(int entity, float buffer[3])
{
	BaseEntity_EyePosition(entity, buffer);
}

stock void BaseEntity_SetViewOffset(int entity, float v[3])
{
	SetEntPropVector(entity, Prop_Data, "m_vecViewOffset", v);
}

stock void BaseEntity_GetViewOffset(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecViewOffset", buffer);
}

stock void BaseEntity_ApplyAbsVelocityImpulse(int entity, const float inVecImpulse[3])
{
	if (!IsNullVector(inVecImpulse))
	{
		float vecImpulse[3]; vecImpulse = inVecImpulse;
		
		//TODO: safety checks?
		
		if (GetEntityMoveType(entity) == MOVETYPE_VPHYSICS)
		{
			//TODO: VPhysicsGetObject()->AddVelocity( &vecImpulse, NULL );
		}
		else
		{
			float vAbsVelocity[3]; GetEntPropVector(entity, Prop_Data, "m_vecAbsVelocity", vAbsVelocity); //GetAbsVelocity
			
			float vecResult[3];
			AddVectors(vAbsVelocity, vecImpulse, vecResult);
			TeleportEntity(entity, NULL_VECTOR, NULL_VECTOR, vecResult); //SetAbsVelocity
		}
	}
}