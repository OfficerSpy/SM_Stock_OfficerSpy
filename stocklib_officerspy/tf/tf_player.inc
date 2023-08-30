stock bool IsMiniBoss(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bIsMiniBoss"));
}

stock void SetIsMiniBoss(int client, bool isMiniBoss)
{
	SetEntProp(client, Prop_Send, "m_bIsMiniBoss", isMiniBoss);
}