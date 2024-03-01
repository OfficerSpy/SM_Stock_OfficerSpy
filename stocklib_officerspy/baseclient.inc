#if defined _stock_officerspy_baseclient_included
	#endinput
#endif
#define _stock_officerspy_baseclient_included

/* This is done a bit differently than CBaseClient::GetNetworkIDString
but it should be more or less the same with the result */
stock void BaseClient_GetNetworkIDString(int client, char[] buffer, int maxlen)
{
	if (IsFakeClient(client))
	{
		strcopy(buffer, maxlen, "BOT");
		return;
	}
	
	if (IsClientSourceTV(client))
		strcopy(buffer, maxlen, "HLTV");
	else if (IsClientReplay(client))
		strcopy(buffer, maxlen, "REPLAY");
	else if (!GetClientAuthId(client, AuthId_Steam3, buffer, maxlen))
		strcopy(buffer, maxlen, "UNKNOWN");
}