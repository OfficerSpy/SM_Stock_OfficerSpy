stock bool TF2_IsMiniBoss(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsMiniBoss"));
}

stock void TF2_SetIsMiniBoss(int client, bool isMiniBoss)
{
	SetEntProp(client, Prop_Send, "m_bIsMiniBoss", isMiniBoss);
}