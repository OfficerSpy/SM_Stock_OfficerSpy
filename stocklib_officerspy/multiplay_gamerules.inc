#if defined _stock_officerspy_multiplaygamerules_included
	#endinput
#endif
#define _stock_officerspy_multiplaygamerules_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/basemultiplayerplayer>

stock void MultiplayRules_HaveAllPlayersSpeakConceptIfAllowed(int iConcept, int iTeam = TEAM_UNASSIGNED)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsClientInGame(i))
			continue;
		
		if (iTeam != TEAM_UNASSIGNED)
			if (GetClientTeam(i) != iTeam)
				continue;
		
		BaseMultiplayerPlayer_SpeakConceptIfAllowed(i, iConcept);
	}
}