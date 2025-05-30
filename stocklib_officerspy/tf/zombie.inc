#if defined _stock_officerspy_zombie_included
	#endinput
#endif
#define _stock_officerspy_zombie_included

enum SkeletonType_t
{
	SKELETON_NORMAL = 0,
	SKELETON_KING,
	SKELETON_MINI
};

static int s_iOffsetType = -1;

stock SkeletonType_t Zombie_GetSkeletonType(int entity)
{
	GetClassPropertyOffsets();
	return GetEntData(entity, s_iOffsetType);
}

static stock void GetClassPropertyOffsets()
{
	//m_nType
	if (s_iOffsetType < 0)
		s_iOffsetType = FindSendPropInfo("CZombie", "m_flHeadScale") - 4;
}