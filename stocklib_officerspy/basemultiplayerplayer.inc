#if defined _stock_officerspy_basemultiplayerplayer_included
	#endinput
#endif
#define _stock_officerspy_basemultiplayerplayer_included

#include <stocklib_officerspy/player>
#include <stocklib_officerspy/shared/mp_shareddefs>

#if !defined COMMAND_MAX_RATE
#define COMMAND_MAX_RATE  0.3
#endif

methodmap OSBaseMultiplayerPlayer < OSBasePlayer
{
	public OSBaseMultiplayerPlayer(int index)
	{
		return view_as<OSBaseMultiplayerPlayer>(index);
	}
	
	public void AwardAchievement(int iAchievement, int iCount = 1)
	{
		BaseMultiplayerPlayer_AwardAchievement(this.index, iAchievement, iCount);
	}
	
	public bool SpeakConceptIfAllowed(int iConcept)
	{
		return BaseMultiplayerPlayer_SpeakConceptIfAllowed(this.index, iConcept);
	}
}

stock void BaseMultiplayerPlayer_AwardAchievement(int client, int iAchievement, int iCount = 1)
{
	Handle bf = StartMessageOne("AchievementEvent", client, USERMSG_RELIABLE);
	
	if (bf)
	{
		BfWriteShort(bf, iAchievement);
		BfWriteShort(bf, iCount);
		EndMessage();
	}
}

stock bool BaseMultiplayerPlayer_SpeakConceptIfAllowed(int client, int iConcept)
{
	char strConcept[PLATFORM_MAX_PATH]; OSLib_GetMPConceptStringFromIndex(iConcept, strConcept, sizeof(strConcept));
	
	SetVariantString(strConcept);
	
	return AcceptEntityInput(client, "SpeakResponseConcept");
}