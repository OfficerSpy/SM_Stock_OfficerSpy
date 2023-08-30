#include <stocklib_officerspy/shared/shareddefs>

stock void BasePlayer_SetHealth(int client, int amt)
{
	SetEntProp(client, Prop_Send, "m_iHealth", amt);
	SetEntProp(client, Prop_Data, "m_iHealth", amt); //CBaseEntity
}

stock bool BasePlayer_IsBot(int client)
{
	return (GetEntityFlags(client) & FL_FAKECLIENT) != 0;
}

//This is just how the games check for fake players
//IsFakeClient is a more reliable way of checking whether or not the player isn't real
stock bool BasePlayer_IsFakeClient(int client)
{
	return (GetEntityFlags(client) & FL_FAKECLIENT) != 0;
}

stock int CollectPlayers(ArrayList players, int team = TEAM_ANY, bool isAlive = false, bool shouldAppend = false)
{
	if (!shouldAppend)
		players.Clear();
	
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsClientInGame(i))
			continue;
		
		if (team != TEAM_ANY && GetClientTeam(i) != team)
			continue;
		
		if (isAlive && !IsPlayerAlive(i))
			continue;
		
		players.Push(i);
	}
	
	return players.Length;
}