#define TF_HBB_TEAM_HALLOWEEN	view_as<int>(TFTeam_Blue) + 2

enum HalloweenBossType
{
	HALLOWEEN_BOSS_INVALID = 0,
	HALLOWEEN_BOSS_HHH = 1,
	HALLOWEEN_BOSS_MONOCULUS = 2,
	HALLOWEEN_BOSS_MERASMUS = 3,
};

stock int TF2_SpawnBossAtPos(HalloweenBossType bossType, const float vSpawnPos[3], int nTeam = TF_HBB_TEAM_HALLOWEEN, int owner = INVALID_ENT_REFERENCE)
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
			SetEntProp(pBoss, Prop_Send, "m_iTeamNum", nTeam); //ChangeTeam
			SetEntityOwner(pBoss, owner);
			
			DispatchSpawn(pBoss);
		}
	}
	
	return pBoss;
}