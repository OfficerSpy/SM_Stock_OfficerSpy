#if defined _stock_officerspy_utilshared_included
	#endinput
#endif
#define _stock_officerspy_utilshared_included

#include <stocklib_officerspy/baseentity>

//NOTE: not using IHandleEntity as this is meant for TraceEntityFilter callbacks
stock bool PassServerEntityFilter(int iTouch, int iPass)
{
	/* if (!IsValidEntity(iPass))
		return false; */
	
	if (iTouch == iPass)
		return false;
	
	/* if (!IsValidEntity(iTouch) || !IsValidEntity(iPass))
		return true; */
	
	if (BaseEntity_GetOwnerEntity(iTouch) == iPass)
		return false;
	
	if (BaseEntity_GetOwnerEntity(iPass) == iTouch)
		return false;
	
	return true;
}