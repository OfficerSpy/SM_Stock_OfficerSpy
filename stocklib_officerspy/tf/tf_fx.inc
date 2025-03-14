#if defined _stock_officerspy_tffx_included
	#endinput
#endif
#define _stock_officerspy_tffx_included

#include <stocklib_officerspy/gameinterface>
#include <stocklib_officerspy/shared/particle_parse>

#if !defined WeaponSound_t_ENABLED
enum WeaponSound_t
{
	EMPTY,
	SINGLE,
	SINGLE_NPC,
	WPN_DOUBLE,
	DOUBLE_NPC,
	BURST,
	RELOAD,
	RELOAD_NPC,
	MELEE_MISS,
	MELEE_HIT,
	MELEE_HIT_WORLD,
	SPECIAL1,
	SPECIAL2,
	SPECIAL3,
	TAUNT,
	DEPLOY,
	NUM_SHOOT_SOUND_TYPES,
};
#define WeaponSound_t_ENABLED
#endif

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

stock void TE_TFExplosion(float flDelay, const float vecOrigin[3], const float vecNormal[3], int iWeaponID, int nEntIndex, int nDefID = -1, WeaponSound_t nSound = SPECIAL1, int iCustomParticleIndex = INVALID_STRING_INDEX)
{
	TE_Start("TFExplosion");
	TE_WriteVector("m_vecOrigin", vecOrigin);
	TE_WriteVector("m_vecNormal", vecNormal);
	TE_WriteNum("m_iWeaponID", iWeaponID);
	TE_WriteNum("entindex", nEntIndex);
	TE_WriteNum("m_nDefID", nDefID);
	TE_WriteNum("m_nSound", view_as<int>(nSound));
	TE_WriteNum("m_iCustomParticleIndex", iCustomParticleIndex);
	TE_SendToAll(flDelay);
}

stock void TE_TFParticleEffect(float flDelay, const char[] pszParticleName, ParticleAttachment_t iAttachType, int pEntity = -1, int iAttachmentPoint = -1, bool bResetAllParticlesOnEntity = false)
{
	TE_Start("TFParticleEffect");
	TE_WriteNum("m_iParticleSystemIndex", GetParticleSystemIndex(pszParticleName));
	
	if (pEntity != -1)
		TE_WriteNum("entindex", pEntity);
	
	TE_WriteNum("m_iAttachType", view_as<int>(iAttachType));
	TE_WriteNum("m_iAttachmentPointIndex", iAttachmentPoint);
	
	if (bResetAllParticlesOnEntity)
		TE_WriteNum("m_bResetParticles", 1);
	
	TE_SendToAll(flDelay);
}

stock void TE_TFParticleEffectComplex(float flDelay, const char[] pszParticleName, float vecOrigin[3], float vecAngles[3], float optionalColor1[3] = NULL_VECTOR, float optionalColor2[3] = NULL_VECTOR, int eParticleAttachment = -1, float vecOffset[3] = NULL_VECTOR, int pEntity = -1, ParticleAttachment_t eAttachType = PATTACH_CUSTOMORIGIN, float vecStart[3] = NULL_VECTOR)
{
	TE_Start("TFParticleEffect");
	TE_WriteNum("m_iParticleSystemIndex", GetParticleSystemIndex(pszParticleName));
	
	TE_WriteFloat("m_vecOrigin[0]", vecOrigin[0]);
	TE_WriteFloat("m_vecOrigin[1]", vecOrigin[1]);
	TE_WriteFloat("m_vecOrigin[2]", vecOrigin[2]);
	
	TE_WriteVector("m_vecAngles", vecAngles);
	
	TE_WriteFloat("m_vecStart[0]", vecStart[0]);
	TE_WriteFloat("m_vecStart[1]", vecStart[1]);
	TE_WriteFloat("m_vecStart[2]", vecStart[2]);
	
	if (pEntity != -1)
	{
		TE_WriteNum("entindex", pEntity);
		TE_WriteNum("m_iAttachType", view_as<int>(eAttachType));
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
		TE_WriteFloat("m_ControlPoint1.m_vecOffset[0]", vecOffset[0]);
		TE_WriteFloat("m_ControlPoint1.m_vecOffset[1]", vecOffset[1]);
		TE_WriteFloat("m_ControlPoint1.m_vecOffset[2]", vecOffset[2]);
	}
	
	TE_SendToAll(flDelay);
}