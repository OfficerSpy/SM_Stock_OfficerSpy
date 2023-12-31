#include <tf2_stocks>

#define TF_TEAM_COUNT	view_as<int>(TFTeam_Blue) + 1

#define TF_TEAM_AUTOASSIGN	TF_TEAM_COUNT + 1

#define TF_TEAM_PVE_INVADERS_GIANTS 4

//TF damage flags
// #define DMG_USE_HITLOCATIONS					DMG_AIRBOAT
// #define DMG_HALF_FALLOFF						DMG_RADIATION
#define DMG_CRITICAL							DMG_ACID
// #define DMG_RADIUS_MAX							DMG_ENERGYBEAM
// #define DMG_IGNITE								DMG_PLASMA
// #define DMG_USEDISTANCEMOD						DMG_SLOWBURN
// #define DMG_NOCLOSEDISTANCEMOD					DMG_POISON
#define DMG_FROM_OTHER_SAPPER					DMG_IGNITE
#define DMG_MELEE								DMG_BLAST_SURFACE
#define DMG_DONT_COUNT_DAMAGE_TOWARDS_CRIT_RATE	DMG_DISSOLVE

//Stun flags
#define TF_STUN_NONE						0
#define TF_STUN_MOVEMENT					TF_STUNFLAG_SLOWDOWN
#define	TF_STUN_CONTROLS					TF_STUNFLAG_BONKSTUCK
#define TF_STUN_MOVEMENT_FORWARD_ONLY		TF_STUNFLAG_LIMITMOVEMENT
#define TF_STUN_SPECIAL_SOUND				TF_STUNFLAG_CHEERSOUND
#define TF_STUN_DODGE_COOLDOWN				(1<<4)
#define TF_STUN_NO_EFFECTS					TF_STUNFLAG_NOSOUNDOREFFECT
#define TF_STUN_LOSER_STATE					TF_STUNFLAG_THIRDPERSON
#define TF_STUN_BY_TRIGGER					TF_STUNFLAG_GHOSTEFFECT
#define TF_STUN_BOTH						TF_STUN_MOVEMENT | TF_STUN_CONTROLS

stock bool IsHeadshot(int iType)
{
	return iType == TF_CUSTOM_HEADSHOT || iType == TF_CUSTOM_HEADSHOT_DECAPITATION;
}

stock TFTeam GetEnemyTeam(TFTeam team)
{
	if (team == TFTeam_Red)
		return TFTeam_Blue;
	
	if (team == TFTeam_Blue)
		return TFTeam_Red;
	
	return team;
}