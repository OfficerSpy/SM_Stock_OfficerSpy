#if defined _stock_officerspy_tfitem_included
	#endinput
#endif
#define _stock_officerspy_tfitem_included

#include <stocklib_officerspy/shared/tf_shareddefs>

stock int TF2_GetItemID(int entity)
{
	//GetItemID is actually a virtual function, so here it's just based on entity class
	
	char classname[PLATFORM_MAX_PATH]; GetEntityClassname(entity, classname, sizeof(classname));
	
	if (StrEqual(classname, "item_teamflag"))
		return TF_ITEM_CAPTURE_FLAG;
	
	return TF_ITEM_UNDEFINED;
}