#if defined _stock_officerspy_const_included
	#endinput
#endif
#define _stock_officerspy_const_included

#define MAX_PLAYER_NAME_LENGTH		MAX_NAME_LENGTH //SourceMod handles it

#define MAX_PLAYERS_PER_CLIENT		1

#define MAX_MAP_NAME				96

#define MAX_MAP_NAME_SAVE			32

#define MAX_DISPLAY_MAP_NAME		32

#define	MAX_NETWORKID_LENGTH		64

#define SP_MODEL_INDEX_BITS			13

#define	MAX_EDICT_BITS				11

#define	MAX_EDICTS					(1 << MAX_EDICT_BITS)

#define MAX_SERVER_CLASS_BITS		9

#define MAX_SERVER_CLASSES			(1 << MAX_SERVER_CLASS_BITS)

#define SIGNED_GUID_LEN 32

#define NUM_ENT_ENTRY_BITS		(MAX_EDICT_BITS + 1)
#define NUM_ENT_ENTRIES			(1 << NUM_ENT_ENTRY_BITS)
#define ENT_ENTRY_MASK			(NUM_ENT_ENTRIES - 1)
#define INVALID_EHANDLE_INDEX	0xFFFFFFFF

#define NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS	10
#define NUM_NETWORKED_EHANDLE_BITS					MAX_EDICT_BITS + NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS
#define INVALID_NETWORKED_EHANDLE_VALUE				(1 << NUM_NETWORKED_EHANDLE_BITS) - 1

#define MAX_PACKEDENTITY_DATA	16384

#define MAX_PACKEDENTITY_PROPS	4096

#define MAX_CUSTOM_FILES		4
#define MAX_CUSTOM_FILE_SIZE	524288

//Defined in entity_prop_stocks.inc
// #define	FL_ONGROUND				(1 << 0)
// #define FL_DUCKING				(1 << 1)
// #define	FL_WATERJUMP			(1 << 2)
// #define FL_ONTRAIN				(1 << 3)
// #define FL_INRAIN				(1 << 4)
// #define FL_FROZEN				(1 << 5)
// #define FL_ATCONTROLS			(1 << 6)
// #define	FL_CLIENT				(1 << 7)
// #define FL_FAKECLIENT			(1 << 8)
// #define	FL_INWATER				(1 << 9)

// #define PLAYER_FLAG_BITS          10

// #define FL_FLY                   (1 << 10)
// #define FL_SWIM                  (1 << 11)
// #define FL_CONVEYOR              (1 << 12)
// #define FL_NPC                   (1 << 13)
// #define FL_GODMODE               (1 << 14)
// #define FL_NOTARGET              (1 << 15)
// #define FL_AIMTARGET             (1 << 16)
// #define FL_PARTIALGROUND         (1 << 17)
// #define FL_STATICPROP            (1 << 18)
// #define FL_GRAPHED               (1 << 19)
// #define FL_GRENADE               (1 << 20)
// #define FL_STEPMOVEMENT          (1 << 21)
// #define FL_DONTTOUCH             (1 << 22)
// #define FL_BASEVELOCITY          (1 << 23)
// #define FL_WORLDBRUSH            (1 << 24)
// #define FL_OBJECT                (1 << 25)
// #define FL_KILLME                (1 << 26)
// #define FL_ONFIRE                (1 << 27)
// #define FL_DISSOLVING            (1 << 28)
// #define FL_TRANSRAGDOLL          (1 << 29)
// #define FL_UNBLOCKABLE_BY_PLAYER (1 << 30)

//Defined in entity_prop_stocks.inc
/* #if !defined MoveType_t_ENABLED
enum MoveType_t
{
	MOVETYPE_NONE		= 0,
	MOVETYPE_ISOMETRIC,
	MOVETYPE_WALK,
	MOVETYPE_STEP,
	MOVETYPE_FLY,
	MOVETYPE_FLYGRAVITY,
	MOVETYPE_VPHYSICS,
	MOVETYPE_PUSH,
	MOVETYPE_NOCLIP,
	MOVETYPE_LADDER,
	MOVETYPE_OBSERVER,
	MOVETYPE_CUSTOM,
	MOVETYPE_LAST		= MOVETYPE_CUSTOM,
	MOVETYPE_MAX_BITS	= 4
};
#define MoveType_t_ENABLED
#endif */
#define MOVETYPE_LAST	MOVETYPE_CUSTOM
#define MOVETYPE_MAX_BITS	4

#if !defined MoveCollide_t_ENABLED
enum MoveCollide_t
{
	MOVECOLLIDE_DEFAULT = 0,
	MOVECOLLIDE_FLY_BOUNCE,
	MOVECOLLIDE_FLY_CUSTOM,
	MOVECOLLIDE_FLY_SLIDE,
	MOVECOLLIDE_COUNT,
	MOVECOLLIDE_MAX_BITS = 3
};
#define MoveCollide_t_ENABLED
#endif

#if !defined SolidType_t_ENABLED
enum SolidType_t
{
	SOLID_NONE			= 0,
	SOLID_BSP			= 1,
	SOLID_BBOX			= 2,
	SOLID_OBB			= 3,
	SOLID_OBB_YAW		= 4,
	SOLID_CUSTOM		= 5,
	SOLID_VPHYSICS		= 6,
	SOLID_LAST
};
#define SolidType_t_ENABLED
#endif

#if !defined SolidFlags_t_ENABLED
enum SolidFlags_t
{
	FSOLID_CUSTOMRAYTEST		= 0x0001,
	FSOLID_CUSTOMBOXTEST		= 0x0002,
	FSOLID_NOT_SOLID			= 0x0004,
	FSOLID_TRIGGER				= 0x0008,
	FSOLID_NOT_STANDABLE		= 0x0010,
	FSOLID_VOLUME_CONTENTS		= 0x0020,
	FSOLID_FORCE_WORLD_ALIGNED	= 0x0040,
	FSOLID_USE_TRIGGER_BOUNDS	= 0x0080,
	FSOLID_ROOT_PARENT_ALIGNED	= 0x0100,
	FSOLID_TRIGGER_TOUCH_DEBRIS	= 0x0200,
	FSOLID_MAX_BITS	= 10
};
#define SolidFlags_t_ENABLED
#endif

#if !defined LIFE_ALIVE
#define LIFE_ALIVE				0
#define LIFE_DYING				1
#define LIFE_DEAD				2
#define LIFE_RESPAWNABLE		3
#define LIFE_DISCARDBODY		4
#endif

#if !defined ENUMERATION_EF && !defined EF_BONEMERGE
enum
{
	EF_BONEMERGE			= 0x001,
	EF_BRIGHTLIGHT 			= 0x002,
	EF_DIMLIGHT 			= 0x004,
	EF_NOINTERP				= 0x008,
	EF_NOSHADOW				= 0x010,
	EF_NODRAW				= 0x020,
	EF_NORECEIVESHADOW		= 0x040,
	EF_BONEMERGE_FASTCULL	= 0x080,
	EF_ITEM_BLINK			= 0x100,
	EF_PARENT_ANIMATES		= 0x200,
	EF_MAX_BITS = 10
};
#define ENUMERATION_EF
#endif

#define EF_PARITY_BITS	3
#define EF_PARITY_MASK  (1 << EF_PARITY_BITS) - 1

#define EF_MUZZLEFLASH_BITS 2

#define	PLAT_LOW_TRIGGER	1

#define	SF_TRAIN_WAIT_RETRIGGER	1
#define SF_TRAIN_PASSABLE		8

#define FIXANGLE_NONE			0
#define FIXANGLE_ABSOLUTE		1
#define FIXANGLE_RELATIVE		2

#define BREAK_GLASS		0x01
#define BREAK_METAL		0x02
#define BREAK_FLESH		0x04
#define BREAK_WOOD		0x08

#define BREAK_SMOKE		0x10
#define BREAK_TRANS		0x20
#define BREAK_CONCRETE	0x40

#define BREAK_SLAVE		0x80

#define BOUNCE_GLASS	BREAK_GLASS
#define	BOUNCE_METAL	BREAK_METAL
#define BOUNCE_FLESH	BREAK_FLESH
#define BOUNCE_WOOD		BREAK_WOOD
#define BOUNCE_SHRAP	0x10
#define BOUNCE_SHELL	0x20
#define	BOUNCE_CONCRETE BREAK_CONCRETE
#define BOUNCE_SHOTSHELL 0x80

#define TE_BOUNCE_NULL		0
#define TE_BOUNCE_SHELL		1
#define TE_BOUNCE_SHOTSHELL	2

#if !defined RenderMode_t_ENABLED
enum RenderMode_t
{	
	kRenderNormal = 0,
	kRenderTransColor,
	kRenderTransTexture,
	kRenderGlow,
	kRenderTransAlpha,
	kRenderTransAdd,
	kRenderEnvironmental,
	kRenderTransAddFrameBlend,
	kRenderTransAlphaAdd,
	kRenderWorldGlow,
	kRenderNone,
	kRenderModeCount
};
#define RenderMode_t_ENABLED
#endif

#if !defined RenderFx_t_ENABLED
enum RenderFx_t
{	
	kRenderFxNone = 0, 
	kRenderFxPulseSlow, 
	kRenderFxPulseFast, 
	kRenderFxPulseSlowWide, 
	kRenderFxPulseFastWide, 
	kRenderFxFadeSlow, 
	kRenderFxFadeFast, 
	kRenderFxSolidSlow, 
	kRenderFxSolidFast, 	   
	kRenderFxStrobeSlow, 
	kRenderFxStrobeFast, 
	kRenderFxStrobeFaster, 
	kRenderFxFlickerSlow, 
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,
	kRenderFxHologram,
	kRenderFxExplode,
	kRenderFxGlowShell,
	kRenderFxClampMinScale,
	kRenderFxEnvRain,
	kRenderFxEnvSnow,
	kRenderFxSpotlight,
	kRenderFxRagdoll,
	kRenderFxPulseFastWider,
	kRenderFxMax
};
#define RenderFx_t_ENABLED
#endif

#if !defined Collision_Group_t_ENABLED
enum //Collision_Group_t
{
	COLLISION_GROUP_NONE  = 0,
	COLLISION_GROUP_DEBRIS,
	COLLISION_GROUP_DEBRIS_TRIGGER,
	COLLISION_GROUP_INTERACTIVE_DEBRIS,
	COLLISION_GROUP_INTERACTIVE,
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_BREAKABLE_GLASS,
	COLLISION_GROUP_VEHICLE,
	COLLISION_GROUP_PLAYER_MOVEMENT,
	COLLISION_GROUP_NPC,
	COLLISION_GROUP_IN_VEHICLE,
	COLLISION_GROUP_WEAPON,
	COLLISION_GROUP_VEHICLE_CLIP,
	COLLISION_GROUP_PROJECTILE,
	COLLISION_GROUP_DOOR_BLOCKER,
	COLLISION_GROUP_PASSABLE_DOOR,
	COLLISION_GROUP_DISSOLVING,
	COLLISION_GROUP_PUSHAWAY,
	COLLISION_GROUP_NPC_ACTOR,
	COLLISION_GROUP_NPC_SCRIPTED,
	LAST_SHARED_COLLISION_GROUP
};
#define Collision_Group_t_ENABLED
#endif

#define SOUND_NORMAL_CLIP_DIST	1000.0f

#define MAX_AREA_STATE_BYTES		32
#define MAX_AREA_PORTAL_STATE_BYTES 24

#define MAX_USER_MSG_DATA 255
#define MAX_ENTITY_MSG_DATA 255