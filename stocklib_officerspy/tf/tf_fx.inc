#include <stocklib_officerspy/gameinterface>

enum //WeaponSound_t
{
	TFWS_EMPTY,
	TFWS_SINGLE,
	TFWS_SINGLE_NPC,
	TFWS_WPN_DOUBLE,
	TFWS_DOUBLE_NPC,
	TFWS_BURST,
	TFWS_RELOAD,
	TFWS_RELOAD_NPC,
	TFWS_MELEE_MISS,
	TFWS_MELEE_HIT,
	TFWS_MELEE_HIT_WORLD,
	TFWS_SPECIAL1,
	TFWS_SPECIAL2,
	TFWS_SPECIAL3,
	TFWS_TAUNT,
	TFWS_DEPLOY,
	TFWS_NUM_SHOOT_SOUND_TYPES,
};

enum //ParticleAttachment_t
{
	TFPATTACH_ABSORIGIN = 0,
	TFPATTACH_ABSORIGIN_FOLLOW,
	TFPATTACH_CUSTOMORIGIN,
	TFPATTACH_POINT,
	TFPATTACH_POINT_FOLLOW,
	TFPATTACH_WORLDORIGIN,
	TFPATTACH_ROOTBONE_FOLLOW
};

stock void TE_FireBullets(int iPlayerIndex, const float vOrigin[3], const float vAngles[3], int iWeaponID, int iMode, int iSeed, float flSpread, bool bCritical)
{
	TE_Start("Fire Bullets");
	TE_WriteNum("m_iPlayer", iPlayerIndex);
	TE_WriteVector("m_vecOrigin", vOrigin);
	TE_WriteAngles("m_vecAngles", vAngles);
	TE_WriteNum("m_iSeed", iSeed);
	TE_WriteFloat("m_flSpread", flSpread);
	TE_WriteNum("m_iMode", iMode);
	TE_WriteNum("m_iWeaponID", iWeaponID);
	TE_WriteNum("m_bCritical", view_as<int>(bCritical));
	TE_SendToAll();
}

stock void TE_TFExplosion(float flDelay, const float vecOrigin[3], const float vecNormal[3], int iWeaponID, int nEntIndex, int nDefID = -1, int nSound = TFWS_SPECIAL1, int iCustomParticleIndex = INVALID_STRING_INDEX)
{
	TE_Start("TFExplosion");
	TE_WriteVector("m_vecOrigin", vecOrigin);
	TE_WriteVector("m_vecNormal", vecNormal);
	TE_WriteNum("m_iWeaponID", iWeaponID);
	TE_WriteNum("entindex", nEntIndex);
	TE_WriteNum("m_nDefID", nDefID);
	TE_WriteNum("m_nSound", nSound);
	TE_WriteNum("m_iCustomParticleIndex", iCustomParticleIndex);
	TE_SendToAll(flDelay);
}

stock void TE_TFParticleEffect(float flDelay, const char[] pszParticleName, int iAttachType, int pEntity = -1, int iAttachmentPoint = -1, bool bResetAllParticlesOnEntity = false)
{
	TE_Start("TFParticleEffect");
	TE_WriteNum("m_iParticleSystemIndex", GetParticleSystemIndex(pszParticleName));
	
	if (pEntity != -1)
		TE_WriteNum("entindex", pEntity);
	
	TE_WriteNum("m_iAttachType", iAttachType);
	TE_WriteNum("m_iAttachmentPointIndex", iAttachmentPoint);
	
	if (bResetAllParticlesOnEntity)
		TE_WriteNum("m_bResetParticles", 1);
	
	TE_SendToAll(flDelay);
}

stock void TE_TFParticleEffectComplex(float flDelay, const char[] pszParticleName, float vecOrigin[3], float vecAngles[3], float optionalColor1[3] = NULL_VECTOR, float optionalColor2[3] = NULL_VECTOR, int eParticleAttachment = -1, float vecOffset[3] = NULL_VECTOR, int pEntity = -1, int eAttachType = TFPATTACH_CUSTOMORIGIN, float vecStart[3] = NULL_VECTOR)
{
	TE_Start("TFParticleEffect");
	TE_WriteNum("m_iParticleSystemIndex", GetParticleSystemIndex(pszParticleName));
	
	TE_WriteVector("m_vecOrigin", vecOrigin);
	TE_WriteVector("m_vecAngles", vecAngles);
	TE_WriteVector("m_vecStart", vecStart);
	
	if (pEntity != -1)
	{
		TE_WriteNum("entindex", pEntity);
		TE_WriteNum("m_iAttachType", eAttachType);
	}
	
	if (!IsNullVector(optionalColor1))
	{
		TE_WriteNum("m_bCustomColors", 1);
		TE_WriteVector("m_CustomColors.m_vecColor1", optionalColor1);
		TE_WriteVector("m_CustomColors.m_vecColor2", optionalColor2);
	}
	
	if (eParticleAttachment > 0)
	{
		TE_WriteNum("m_bControlPoint1", 1);
		TE_WriteNum("m_ControlPoint1.m_eParticleAttachment", eParticleAttachment);
		TE_WriteVector("m_ControlPoint1.m_vecOffset", vecOffset);
	}
	
	TE_SendToAll(flDelay);
}