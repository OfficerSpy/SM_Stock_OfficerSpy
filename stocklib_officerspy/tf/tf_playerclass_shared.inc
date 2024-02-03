#if defined _stock_officerspy_tfplayerclassshared_included
	#endinput
#endif
#define _stock_officerspy_tfplayerclassshared_included

//You do not need to precache the model, as the function does it already
stock void TF2_SetCustomModel(int client, char[] pszModelName, bool isUsingClassAnimations = false)
{	
	SetVariantString(pszModelName);
	AcceptEntityInput(client, isUsingClassAnimations ? "SetCustomModelWithClassAnimations" : "SetCustomModel");
}