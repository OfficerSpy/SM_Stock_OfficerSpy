#if defined _stock_officerspy_tfplayerclassshared_included
	#endinput
#endif
#define _stock_officerspy_tfplayerclassshared_included

stock bool TF2_IsClass(int client, TFClassType iClass)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iClass")) == iClass;
}

#pragma deprecated Use TF2_GetPlayerClass instead
stock TFClassType TF2_GetClassIndex(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iClass"));
}

stock void TF2_GetClassIconName(int client, char[] buffer, int maxlen)
{
	GetEntPropString(client, Prop_Send, "m_iszClassIcon", buffer, maxlen);
}

stock void TF2_SetClassIconName(int client, char[] iszClassIcon)
{
	//NOTE: Setting netprop m_iszClassIcon without it first being initialized will crash the game
	//It's only initialized in CTFPlayerClassShared::Init, which happens in CTFPlayer::ForceRespawn
	//So we will only set it after it has been assigned a string value
	
	char currentIcon[PLATFORM_MAX_PATH]; GetEntPropString(client, Prop_Send, "m_iszClassIcon", currentIcon, sizeof(currentIcon));
	
	if (strlen(currentIcon) < 1)
		ThrowError("Property \"m_iszClassIcon\" has not yet been initialized!");
	
	SetEntPropString(client, Prop_Send, "m_iszClassIcon", iszClassIcon);
}

stock bool TF2_HasCustomModel(int client)
{
	char model[PLATFORM_MAX_PATH]; GetEntPropString(client, Prop_Send, "m_iszCustomModel", model, sizeof(model));
	
	return !StrEqual(model, NULL_STRING);
}
stock void TF2_SetCustomModel(int client, char[] pszModelName, bool isUsingClassAnimations = false)
{	
	//The function is in this input already precaches the model
	SetVariantString(pszModelName);
	AcceptEntityInput(client, isUsingClassAnimations ? "SetCustomModelWithClassAnimations" : "SetCustomModel");
}

stock void TF2_SetCustomModelOffset(int client, float vecOffset[3])
{
	// SetEntPropVector(client, Prop_Send, "m_vecCustomModelOffset", vecOffset);
	
	//New method
	SetVariantVector3D(vecOffset);
	AcceptEntityInput(client, "SetCustomModelOffset");
}

stock void TF2_SetCustomModelRotates(int client, bool bRotates)
{
	// SetEntProp(client, Prop_Send, "m_bCustomModelRotates", bRotates);
	
	//New method
	SetVariantBool(bRotates);
	AcceptEntityInput(client, "SetCustomModelRotates");
}

stock void TF2_SetCustomModelRotation(int client, float vecOffset[3])
{
	// SetEntPropVector(client, Prop_Send, "m_angCustomModelRotation", vecOffset);
	// SetEntProp(client, Prop_Send, "m_bCustomModelRotationSet", true);
	
	//New method
	SetVariantVector3D(vecOffset);
	AcceptEntityInput(client, "SetCustomModelRotation");
}

stock void TF2_ClearCustomModelRotation(int client)
{
	// SetEntProp(client, Prop_Send, "m_bCustomModelRotationSet", false);
	
	//New method
	AcceptEntityInput(client, "ClearCustomModelRotation");
}

stock void TF2_SetCustomModelVisibleToSelf(int client, bool bVisible)
{
	// SetEntProp(client, Prop_Send, "m_bCustomModelVisibleToSelf", bVisible);
	
	//New method
	SetVariantBool(bVisible);
	AcceptEntityInput(client, "SetCustomModelVisibleToSelf");
}