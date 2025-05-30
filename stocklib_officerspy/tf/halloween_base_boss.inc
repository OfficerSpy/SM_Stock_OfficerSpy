#if defined _stock_officerspy_halloween_base_boss_included
	#endinput
#endif
#define _stock_officerspy_halloween_base_boss_included

#include <stocklib_officerspy/shared/tf_shareddefs>
#include <stocklib_officerspy/baseentity>

stock int TF2_SpawnBossAtPos(HalloweenBossType bossType, const float vSpawnPos[3], int nTeam = TF_TEAM_HALLOWEEN, int owner = INVALID_ENT_REFERENCE)
{
	char strBossType[20];
	switch(bossType)
	{
		case HALLOWEEN_BOSS_HHH:	strBossType = "headless_hatman";
		case HALLOWEEN_BOSS_MONOCULUS:	strBossType = "eyeball_boss";
		case HALLOWEEN_BOSS_MERASMUS:	strBossType = "merasmus";
		default:	ThrowError("Invalid Halloween Boss Type");
	}
	
	int pBoss;
	if (strlen(strBossType) > 0)
	{
		pBoss = CreateEntityByName(strBossType);
		if (pBoss != -1)
		{
			float finalSpawnPos[3];	finalSpawnPos = vSpawnPos;
			finalSpawnPos[2] += 10.0;
			
			TeleportEntity(pBoss, finalSpawnPos); //SetAbsOrigin
			BaseEntity_ChangeTeam(pBoss, nTeam);
			SetEntityOwner(pBoss, owner);
			
			DispatchSpawn(pBoss);
		}
	}
	
	return pBoss;
}