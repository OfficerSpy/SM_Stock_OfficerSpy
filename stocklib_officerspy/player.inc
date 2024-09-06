#if defined _stock_officerspy_player_included
	#endinput
#endif
#define _stock_officerspy_player_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/basecombatcharacter>
#include <stocklib_officerspy/gamerules>

enum //PlayerPhysFlag_e
{
	PFLAG_DIROVERRIDE	= (1<<0),
	PFLAG_DUCKING	= (1<<1),
	PFLAG_USING	=	(1<<2),
	PFLAG_OBSERVER	= (1<<3),
	PFLAG_VPHYSICS_MOTIONCONTROLLER	= (1<<4),
	PFLAG_GAMEPHYSICS_ROTPUSH	= (1<<5)
};

methodmap OSBasePlayer < OSBaseCombatCharacter
{
	public OSBasePlayer(int index)
	{
		return view_as<OSBasePlayer>(index);
	}
	
	public int FragCount()
	{
		return BasePlayer_FragCount(this.index);
	}
	
	public int DeathCount()
	{
		return BasePlayer_DeathCount(this.index);
	}
	
	public bool IsSuitEquipped()
	{
		return BasePlayer_IsSuitEquipped(this.index);
	}
	
	public int ArmorValue()
	{
		return BasePlayer_ArmorValue(this.index);
	}
	
	public bool HUDNeedsRestart()
	{
		return BasePlayer_HUDNeedsRestart(this.index);
	}
	
	public float MaxSpeed()
	{
		return BasePlayer_MaxSpeed(this.index);
	}
	
	public bool IsPlayerLockedInPlace()
	{
		return BasePlayer_IsPlayerLockedInPlace(this.index);
	}
	
	public bool IsObserver()
	{
		return BasePlayer_IsObserver(this.index);
	}
	
	public float MuzzleFlashTime()
	{
		return BasePlayer_MuzzleFlashTime(this.index);
	}
	
	public float PlayerDrownTime()
	{
		return BasePlayer_PlayerDrownTime(this.index);
	}
	
	public int GetObserverMode()
	{
		return BasePlayer_GetObserverMode(this.index);
	}
	
	public int GetObserverTarget()
	{
		return BasePlayer_GetObserverTarget(this.index);
	}
	
	public void SetMaxSpeed(float flMaxSpeed)
	{
		BasePlayer_SetMaxSpeed(this.index, flMaxSpeed);
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

stock int BasePlayer_FragCount(int client)
{
	return GetEntProp(client, Prop_Data, "m_iFrags");
}

stock int BasePlayer_DeathCount(int client)
{
	return GetEntProp(client, Prop_Data, "m_iDeaths");
}

stock bool BasePlayer_IsSuitEquipped(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Send, "m_bWearingSuit"));
}

stock int BasePlayer_ArmorValue(int client)
{
	return GetEntProp(client, Prop_Data, "m_ArmorValue");
}

stock bool BasePlayer_HUDNeedsRestart(int client)
{
	return view_as<bool>(GetEntProp(client, Prop_Data, "m_fInitHUD"));
}

stock float BasePlayer_MaxSpeed(int client)
{
	return GetEntPropFloat(client, Prop_Data, "m_flMaxspeed");
}

stock bool BasePlayer_IsPlayerLockedInPlace(int client)
{
	return GetEntProp(client, Prop_Data, "m_iPlayerLocked") != 0;
}

stock bool BasePlayer_IsObserver(int client)
{
	return GetEntProp(client, Prop_Data, "m_afPhysicsFlags") & PFLAG_OBSERVER != 0;
}

stock float BasePlayer_MuzzleFlashTime(int client)
{
	return GetEntPropFloat(client, Prop_Data, "m_flFlashTime");
}

stock float BasePlayer_PlayerDrownTime(int client)
{
	return GetEntPropFloat(client, Prop_Data, "m_AirFinished");
}

stock int BasePlayer_GetObserverMode(int client)
{
	return GetEntProp(client, Prop_Data, "m_iObserverMode");
}

stock int BasePlayer_GetObserverTarget(int client)
{
	return GetEntPropEnt(client, Prop_Data, "m_hObserverTarget");
}

stock void BasePlayer_SetMaxSpeed(int client, float flMaxSpeed)
{
	SetEntPropFloat(client, Prop_Data, "m_flMaxspeed", flMaxSpeed);
	SetEntPropFloat(client, Prop_Send, "m_flMaxspeed", flMaxSpeed);
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