//This probably isn't exactly safe since it has no safety checks
//It also does nothing for MOVETYPE_VPHYSICS...
stock void BaseEntity_ApplyAbsVelocityImpulse(int entity, const float inVecImpulse[3])
{
	if (!IsNullVector(inVecImpulse))
	{
		float vecImpulse[3]; vecImpulse = inVecImpulse;
		
		float vAbsVelocity[3]; GetEntPropVector(entity, Prop_Data, "m_vecAbsVelocity", vAbsVelocity);
		
		float vecResult[3];
		AddVectors(vAbsVelocity, vecImpulse, vecResult);
		TeleportEntity(entity, NULL_VECTOR, NULL_VECTOR, vecResult); //SetAbsVelocity
	}
}