#if defined _stock_officerspy_tfweaponbase_included
	#endinput
#endif
#define _stock_officerspy_tfweaponbase_included

#include <tf2_stocks>

stock bool WeaponID_IsSniperRifle(int iWeaponID)
{
	if (iWeaponID == TF_WEAPON_SNIPERRIFLE || iWeaponID == TF_WEAPON_SNIPERRIFLE_DECAP || iWeaponID == TF_WEAPON_SNIPERRIFLE_CLASSIC)
		return true;
	else
		return false;
}

stock bool WeaponID_IsSniperRifleOrBow(int iWeaponID)
{
	if (iWeaponID == TF_WEAPON_COMPOUND_BOW)
		return true;
	else
		return WeaponID_IsSniperRifle(iWeaponID);
}