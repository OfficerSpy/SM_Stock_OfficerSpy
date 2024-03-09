#if defined _stock_officerspy_entitycaptureflag_included
	#endinput
#endif
#define _stock_officerspy_entitycaptureflag_included

stock ETFFlagType CaptureFlag_GetType(int entity)
{
	return view_as<ETFFlagType>(GetEntProp(entity, Prop_Send, "m_nType"));
}