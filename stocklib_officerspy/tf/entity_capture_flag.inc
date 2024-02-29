#if defined _stock_officerspy_entitycaptureflag_included
	#endinput
#endif
#define _stock_officerspy_entitycaptureflag_included

#if !defined ETFFlagType_ENABLED
enum ETFFlagType
{
	TF_FLAGTYPE_CTF = 0,
	TF_FLAGTYPE_ATTACK_DEFEND,
	TF_FLAGTYPE_TERRITORY_CONTROL,
	TF_FLAGTYPE_INVADE,
	TF_FLAGTYPE_RESOURCE_CONTROL,
	TF_FLAGTYPE_ROBOT_DESTRUCTION,
	TF_FLAGTYPE_PLAYER_DESTRUCTION
};
#define ETFFlagType_ENABLED
#endif

stock ETFFlagType CaptureFlag_GetType(int entity)
{
	return view_as<ETFFlagType>(GetEntProp(entity, Prop_Send, "m_nType"));
}