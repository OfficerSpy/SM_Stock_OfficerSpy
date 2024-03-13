#if defined _stock_officerspy_teamplayroundbasedgamerules_included
	#endinput
#endif
#define _stock_officerspy_teamplayroundbasedgamerules_included

stock RoundState TeamplayRoundBasedRules_State_Get()
{
	// return GameRules_GetProp("m_iRoundState");
	
	return GameRules_GetRoundState();
}

stock bool TeamplayRoundBasedRules_IsInWaitingForPlayers()
{
	return view_as<bool>(GameRules_GetProp("m_bInWaitingForPlayers"));
}

stock bool TeamplayRoundBasedRules_InRoundRestart()
{
	return GameRules_GetRoundState() == RoundState_Preround;
}

stock bool TeamplayRoundBasedRules_InStalemate()
{
	return GameRules_GetRoundState() == RoundState_Stalemate;
}

stock bool TeamplayRoundBasedRules_RoundHasBeenWon()
{
	return GameRules_GetRoundState() == RoundState_TeamWin;
}

stock void TeamplayRoundBasedRules_BroadcastSound(int team, const char[] sound, int additionalSoundFlags = 0)
{
	Event hEvent = CreateEvent("teamplay_broadcast_audio");
	if (hEvent)
	{
		hEvent.SetInt("team", team);
		hEvent.SetString("sound", sound);
		hEvent.SetInt("additional_flags", additionalSoundFlags);
		hEvent.Fire();
	}
}

