stock bool TFPlayer_IsMiniBoss(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsMiniBoss"));
}

stock void TFPlayer_SetIsMiniBoss(int client, bool isMiniBoss)
{
	SetEntProp(client, Prop_Send, "m_bIsMiniBoss", isMiniBoss);
}