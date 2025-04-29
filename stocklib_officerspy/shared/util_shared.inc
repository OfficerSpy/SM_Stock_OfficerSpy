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

stock bool StandardFilterRules(int iEntity, int fContentsMask)
{
	/* if (!IsValidEntity(iEntity))
		return true; */
	
	SolidType_t solid = BaseEntity_GetSolid(iEntity);
	//MISSING: const model_t *pModel = pCollide->GetModel();
	
	if (solid != SOLID_BSP && solid != SOLID_VPHYSICS)
	{
		if (fContentsMask & CONTENTS_MONSTER == 0)
			return false;
	}
	
	if (!(fContentsMask & CONTENTS_WINDOW) && BaseEntity_IsTransparent(iEntity))
		return false;
	
	if (!(fContentsMask & CONTENTS_MOVEABLE) && GetEntityMoveType(iEntity) == MOVETYPE_PUSH)
		return false;
	
	return true;
}