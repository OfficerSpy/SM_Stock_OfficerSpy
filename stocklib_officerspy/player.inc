#if defined _stock_officerspy_player_included
	#endinput
#endif
#define _stock_officerspy_player_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/basecombatcharacter>
#include <stocklib_officerspy/gamerules>

methodmap OSBasePlayer < OSBaseCombatCharacter
{
	public OSBasePlayer(int index)
	{
		return view_as<OSBasePlayer>(index);
	}
	
	public bool IsBot()
	{
		return BasePlayer_IsBot(this.index);
	}
	
	public bool IsFakeClient()
	{
		return BasePlayer_IsFakeClient(this.index);
	}
	
	public int GetFOV()
	{
		return BasePlayer_GetFOV(this.index);
	}
	
	public void EyeVectors(float pForward[3], float pRight[3] = NULL_VECTOR, float pUp[3] = NULL_VECTOR)
	{
		BasePlayer_EyeVectors(this.index, pForward, pRight, pUp);
	}
	
	public int GetDefaultFOV()
	{
		return BasePlayer_GetDefaultFOV(this.index);
	}
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

stock int BasePlayer_GetFOV(int client)
{
	int nDefaultFOV;
	
	//MISSING: if ( GetVehicle() )
	
	nDefaultFOV = BasePlayer_GetDefaultFOV(client);
	
	int m_iFOV = GetEntProp(client, Prop_Send, "m_iFOV");
	
	int fFOV = m_iFOV == 0 ? nDefaultFOV : m_iFOV;
	
	float m_flFOVRate = GetEntPropFloat(client, Prop_Send, "m_flFOVRate");
	
	if (m_flFOVRate == 0.0)
		return fFOV;
	
	float deltaTime = (GetGameTime() - GetEntPropFloat(client, Prop_Send, "m_flFOVTime")) / m_flFOVRate;
	
	if (deltaTime >= 1.0)
	{
		SetEntProp(client, Prop_Send, "m_iFOVStart", fFOV);
		SetEntProp(client, Prop_Data, "m_iFOVStart", fFOV);
	}
	else
	{
		//MISSING: fFOV = SimpleSplineRemapValClamped( deltaTime, 0.0f, 1.0f, m_iFOVStart, fFOV );
	}
	
	return fFOV;
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

stock void BasePlayer_EyeVectors(int client, float pForward[3], float pRight[3] = NULL_VECTOR, float pUp[3] = NULL_VECTOR)
{
	//MISSING: if ( GetVehicle() != NULL )
	
	float eyeAngles[3]; GetClientEyeAngles(client, eyeAngles);
	GetAngleVectors(eyeAngles, pForward, pRight, pUp);
}

stock int BasePlayer_GetDefaultFOV(int client)
{
	int m_iDefaultFOV = GetEntProp(client, Prop_Send, "m_iDefaultFOV");
	
	int iFOV = m_iDefaultFOV == 0 ? CGameRules_DefaultFOV() : m_iDefaultFOV;
	if (iFOV > MAX_FOV)
		iFOV = MAX_FOV;
	
	return iFOV;
}