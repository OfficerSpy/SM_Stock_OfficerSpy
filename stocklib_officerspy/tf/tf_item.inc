#if defined _stock_officerspy_tfitem_included
	#endinput
#endif
#define _stock_officerspy_tfitem_included

#if !defined ENUMERATION_TF_ITEM
enum
{
	TF_ITEM_UNDEFINED	= 0,
	TF_ITEM_CAPTURE_FLAG	= (1<<0),
	TF_ITEM_HEALTH_KIT	= (1<<1),
	TF_ITEM_ARMOR	= (1<<2),
	TF_ITEM_AMMO_PACK	= (1<<3),
	TF_ITEM_GRENADE_PACK	= (1<<4)
};
#define ENUMERATION_TF_ITEM
#endif

stock int TF2_GetItemID(int entity)
{
	//GetItemID is actually a virtual function, so here it's just based on entity class
	
	char classname[PLATFORM_MAX_PATH]; GetEntityClassname(entity, classname, sizeof(classname));
	
	if (StrEqual(classname, "item_teamflag"))
		return TF_ITEM_CAPTURE_FLAG;
	
	return TF_ITEM_UNDEFINED;
}