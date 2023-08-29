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