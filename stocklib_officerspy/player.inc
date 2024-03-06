#if defined _stock_officerspy_player_included
	#endinput
#endif
#define _stock_officerspy_player_included

#include <stocklib_officerspy/basecombatcharacter>

#if !defined TEAM_ANY
#define TEAM_ANY	-2
#endif

#if !defined TEAM_INVALID
#define	TEAM_INVALID	-1
#endif

#if !defined TEAM_UNASSIGNED
#define TEAM_UNASSIGNED	0
#endif

#if !defined TEAM_SPECTATOR
#define TEAM_SPECTATOR	1
#endif

#if !defined LAST_SHARED_TEAM
#define LAST_SHARED_TEAM	TEAM_SPECTATOR
#endif

methodmap OSBasePlayer < OSBaseCombatCharacter
{
	public OSBasePlayer(int index)
	{
		return view_as<OSBasePlayer>(index);
	}
	
	public void SetHealth(int amt)
	{
		BasePlayer_SetHealth(this.index, amt);
	}
	
	public bool IsBot()
	{
		return BasePlayer_IsBot(this.index);
	}
	
	public bool IsFakeClient()
	{
		return BasePlayer_IsFakeClient(this.index);
	}
}

stock void BasePlayer_SetHealth(int client, int amt)
{
	SetEntProp(client, Prop_Send, "m_iHealth", amt);
	SetEntProp(client, Prop_Data, "m_iHealth", amt); //CBaseEntity
}

stock bool BasePlayer_IsBot(int client)
{
	return GetEntityFlags(client) & FL_FAKECLIENT != 0;
}

//This is just how the games check for fake players
//IsFakeClient is a more reliable way of checking whether or not the player isn't real
stock bool BasePlayer_IsFakeClient(int client)
{
	return GetEntityFlags(client) & FL_FAKECLIENT != 0;
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