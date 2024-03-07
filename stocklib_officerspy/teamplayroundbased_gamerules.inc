#if defined _stock_officerspy_teamplayroundbasedgamerules_included
	#endinput
#endif
#define _stock_officerspy_teamplayroundbasedgamerules_included

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