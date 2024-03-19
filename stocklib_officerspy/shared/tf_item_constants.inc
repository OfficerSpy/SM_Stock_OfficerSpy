#if defined _stock_officerspy_tfitemconstants_included
	#endinput
#endif
#define _stock_officerspy_tfitemconstants_included

enum
{
	TF_WPN_TYPE_PRIMARY = 0,
	TF_WPN_TYPE_SECONDARY,
	TF_WPN_TYPE_MELEE,
	TF_WPN_TYPE_GRENADE,
	TF_WPN_TYPE_BUILDING,
	TF_WPN_TYPE_PDA,
	TF_WPN_TYPE_ITEM1,
	TF_WPN_TYPE_ITEM2,
	TF_WPN_TYPE_HEAD,
	TF_WPN_TYPE_MISC,
	TF_WPN_TYPE_MELEE_ALLCLASS,
	TF_WPN_TYPE_SECONDARY2,
	TF_WPN_TYPE_PRIMARY2,
	TF_WPN_TYPE_COUNT
};

enum //loadout_positions_t
{
	LOADOUT_POSITION_INVALID = -1,
	LOADOUT_POSITION_PRIMARY = 0,
	LOADOUT_POSITION_SECONDARY,
	LOADOUT_POSITION_MELEE,
	LOADOUT_POSITION_UTILITY,
	LOADOUT_POSITION_BUILDING,
	LOADOUT_POSITION_PDA,
	LOADOUT_POSITION_PDA2,
	LOADOUT_POSITION_HEAD,
	LOADOUT_POSITION_MISC,
	LOADOUT_POSITION_ACTION,
	LOADOUT_POSITION_MISC2,
	LOADOUT_POSITION_TAUNT,
	LOADOUT_POSITION_TAUNT2,
	LOADOUT_POSITION_TAUNT3,
	LOADOUT_POSITION_TAUNT4,
	LOADOUT_POSITION_TAUNT5,
	LOADOUT_POSITION_TAUNT6,
	LOADOUT_POSITION_TAUNT7,
	LOADOUT_POSITION_TAUNT8,
	CLASS_LOADOUT_POSITION_COUNT
};

enum //account_loadout_positions_t
{
	ACCOUNT_LOADOUT_POSITION_ACCOUNT1,
	ACCOUNT_LOADOUT_POSITION_ACCOUNT2,
	ACCOUNT_LOADOUT_POSITION_ACCOUNT3,
	ACCOUNT_LOADOUT_POSITION_COUNT
};

#define	LOADOUT_MAX_WEARABLES_COUNT (8)

stock bool IsMiscSlot(int iSlot)
{
	return iSlot == LOADOUT_POSITION_MISC
		|| iSlot == LOADOUT_POSITION_MISC2
		|| iSlot == LOADOUT_POSITION_HEAD;
}

stock bool IsBuildingSlot(int iSlot)
{
	return iSlot == LOADOUT_POSITION_BUILDING
}

stock bool IsTauntSlot(int iSlot)
{
	return iSlot == LOADOUT_POSITION_TAUNT
		|| iSlot == LOADOUT_POSITION_TAUNT2
		|| iSlot == LOADOUT_POSITION_TAUNT3
		|| iSlot == LOADOUT_POSITION_TAUNT4
		|| iSlot == LOADOUT_POSITION_TAUNT5
		|| iSlot == LOADOUT_POSITION_TAUNT6
		|| iSlot == LOADOUT_POSITION_TAUNT7
		|| iSlot == LOADOUT_POSITION_TAUNT8;
}

stock bool IsWearableSlot(int iSlot)
{
	return iSlot == LOADOUT_POSITION_HEAD
		|| iSlot == LOADOUT_POSITION_MISC
		|| iSlot == LOADOUT_POSITION_ACTION
		|| IsMiscSlot(iSlot)
		|| IsTauntSlot(iSlot);
}

stock bool IsQuestSlot(int iSlot)
{
	return iSlot == ACCOUNT_LOADOUT_POSITION_ACCOUNT1
		|| iSlot == ACCOUNT_LOADOUT_POSITION_ACCOUNT2
		|| iSlot == ACCOUNT_LOADOUT_POSITION_ACCOUNT3;
}

stock bool IsValidItemSlot(int iSlot)
{
	return iSlot > LOADOUT_POSITION_INVALID && iSlot < CLASS_LOADOUT_POSITION_COUNT;
}

stock bool IsValidPickupWeaponSlot(int iSlot)
{
	return iSlot == LOADOUT_POSITION_PRIMARY
		|| iSlot == LOADOUT_POSITION_SECONDARY
		|| iSlot == LOADOUT_POSITION_MELEE;
}

#define LOADOUT_COUNT	10 + 1

enum EHalloweenMap
{
	kHalloweenMap_MannManor,
	kHalloweenMap_Viaduct,
	kHalloweenMap_Lakeside,
	kHalloweenMap_Hightower,
	kHalloweenMapCount
};

enum EHalloweenGiftSpawnMetaInfo
{
	kHalloweenGiftMeta_IsUnderworldOnViaduct_DEPRECATED = 0x01,
};