#if defined _stock_officerspy_entitycaptureflag_included
	#endinput
#endif
#define _stock_officerspy_entitycaptureflag_included

#include <stocklib_officerspy/shared/tf_shareddefs>

stock bool CaptureFlag_IsDisabled(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bDisabled"));
}

stock ETFFlagType CaptureFlag_GetType(int entity)
{
	return view_as<ETFFlagType>(GetEntProp(entity, Prop_Send, "m_nType"));
}

stock bool CaptureFlag_IsDropped(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_nFlagStatus") == TF_FLAGINFO_DROPPED;
}

stock bool CaptureFlag_IsHome(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_nFlagStatus") == TF_FLAGINFO_HOME;
}

stock bool CaptureFlag_IsStolen(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_nFlagStatus") == TF_FLAGINFO_STOLEN;
}