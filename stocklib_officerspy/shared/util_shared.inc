#if defined _stock_officerspy_utilshared_included
	#endinput
#endif
#define _stock_officerspy_utilshared_included

#include <stocklib_officerspy/baseentity>
#include <stocklib_officerspy/public/model_types>

//NOTE: IHandleEntity is not used here as these are meant for TraceEntityFilter callbacks

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
	
	if ((GetModelType(iEntity) != mod_brush) || (solid != SOLID_BSP && solid != SOLID_VPHYSICS))
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

//Hack method, really should be getting it from CModelInfo but that is out of our scope here
static stock modtype_t GetModelType(int entity)
{
	char modelName[PLATFORM_MAX_PATH]; GetEntPropString(entity, Prop_Data, "m_ModelName", modelName, sizeof(modelName));
	
	if (modelName[0])
	{
		//TODO: get actual file extension, this just assumes the substring will only ever occur once in the path
		if (StrContains(modelName, ".spr", false) != -1 || StrContains(modelName, ".vmt", false) != -1)
		{
			return mod_sprite;
		}
		else if (StrContains(modelName, ".bsp", false) != -1)
		{
			return mod_brush;
		}
		else if (StrContains(modelName, ".mdl", false) != -1)
		{
			return mod_studio;
		}
	}
	
	return mod_bad;
}