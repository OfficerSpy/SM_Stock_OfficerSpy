#if defined _stock_officerspy_entitycaptureflag_included
	#endinput
#endif
#define _stock_officerspy_entitycaptureflag_included

#include <stocklib_officerspy/shared/tf_shareddefs>

stock ETFFlagType CaptureFlag_GetType(int entity)
{
	return view_as<ETFFlagType>(GetEntProp(entity, Prop_Send, "m_nType"));
}