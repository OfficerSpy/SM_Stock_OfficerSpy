/* These are makeshift stocks to make use of functions exposed in VScript.
These will only work if the game in question supports VScript.
They will do nothing useful otherwise. */

stock void VS_ApplyAbsVelocityImpulse(int entity, float inVecImpulse[3])
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.ApplyAbsVelocityImpulse(Vector(%f, %f, %f))", inVecImpulse[0], inVecImpulse[1], inVecImpulse[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetAbsAngles(int entity, float absAngles[3])
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetAbsAngles(QAngle(%f, %f, %f))", absAngles[0], absAngles[1], absAngles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetAbsOrigin(int entity, float absOrigin[3])
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetAbsOrigin(Vector(%f, %f, %f))", absOrigin[0], absOrigin[1], absOrigin[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetHealth(int entity, int amt)
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetHealth(%d)", amt);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetLocalAngles(int entity, float angles[3])
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetLocalAngles(QAngle(%f, %f, %f))", angles[0], angles[1], angles[2]);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetMaxHealth(int entity, int amt)
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetMaxHealth(%d)", amt);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}

stock void VS_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	char buffer[256]; Format(buffer, sizeof(buffer), "!self.SetModelScale(%f, %f)", scale, change_duration);
	
	SetVariantString(buffer);
	AcceptEntityInput(entity, "RunScriptCode");
}