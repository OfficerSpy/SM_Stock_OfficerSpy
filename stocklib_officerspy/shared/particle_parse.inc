#if defined _stock_officerspy_particleparse_included
	#endinput
#endif
#define _stock_officerspy_particleparse_included

#include <stocklib_officerspy/gameinterface>
#include <stocklib_officerspy/baseentity>

#if !defined ParticleAttachment_t_ENABLED
enum ParticleAttachment_t
{
	PATTACH_ABSORIGIN = 0,
	PATTACH_ABSORIGIN_FOLLOW,
	PATTACH_CUSTOMORIGIN,
	PATTACH_POINT,
	PATTACH_POINT_FOLLOW,
	PATTACH_WORLDORIGIN,
	PATTACH_ROOTBONE_FOLLOW
};
#define ParticleAttachment_t_ENABLED
#endif

#define PARTICLE_DISPATCH_FROM_ENTITY		(1 << 0)
#define PARTICLE_DISPATCH_RESET_PARTICLES	(1 << 1)

enum struct te_tf_particle_effects_colors_t
{
	float m_vecColor1[3];
	float m_vecColor2[3];
}

enum struct te_tf_particle_effects_control_point_t
{
	ParticleAttachment_t m_eParticleAttachment;
	float m_vecOffset[3];
}

//effect_dispatch_data.inc has to be included after these enumerations or else the symbols are not defined when it includes this file
#include <stocklib_officerspy/shared/effect_dispatch_data>
#include <stocklib_officerspy/te_effect_dispatch>

stock void DispatchParticleEffect(const char[] sParticleName, ParticleAttachment_t iAttachType, int iEntity, const char[] sAttachmentName, bool bResetAllParticlesOnEntity = false)
{
	int iAttachment = -1;
	
	//TODO: check if entity is of CBaseAnimating?
	if (iEntity != -1)
	{
		iAttachment = LookupEntityAttachment(iEntity, sAttachmentName);
		
		if (iAttachment <= 0)
		{
			return;
		}
	}
	
	DispatchParticleEffect2(sParticleName, iAttachType, iEntity, iAttachment, bResetAllParticlesOnEntity);
}

stock void DispatchParticleEffect2(const char[] sParticleName, ParticleAttachment_t iAttachType, int iEntity = -1, int iAttachmentPoint = -1, bool bResetAllParticlesOnEntity = false)
{
	CEffectData data;
	
	data.m_nHitBox = GetParticleSystemIndex(sParticleName);
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
		data.m_fFlags |= PARTICLE_DISPATCH_FROM_ENTITY;
		BaseEntity_GetAbsOrigin(iEntity, data.m_vOrigin);
	}
	
	data.m_nDamageType = iAttachType;
	data.m_nAttachmentIndex = iAttachmentPoint;
	
	if (bResetAllParticlesOnEntity)
		data.m_fFlags |= PARTICLE_DISPATCH_RESET_PARTICLES;
	
	TE_DispatchEffect(0.0, "ParticleEffect", data);
}

stock void DispatchParticleEffect3(const char[] sParticleName, ParticleAttachment_t iAttachType, int iEntity, const char[] sAttachmentName, float vecColor1[3], float vecColor2[3], bool bUseColors = true, bool bResetAllParticlesOnEntity = false)
{
	int iAttachment = -1;
	
	//TODO: check if entity is of CBaseAnimating?
	if (iEntity != -1)
	{
		iAttachment = LookupEntityAttachment(iEntity, sAttachmentName);
		
		if (iAttachment <= 0)
		{
			return;
		}
	}
	
	CEffectData data;
	
	data.m_nHitBox = GetParticleSystemIndex(sParticleName);
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
		data.m_fFlags |= PARTICLE_DISPATCH_FROM_ENTITY;
		BaseEntity_GetAbsOrigin(iEntity, data.m_vOrigin);
	}
	
	data.m_nDamageType = iAttachType;
	data.m_nAttachmentIndex = iAttachment;
	
	if (bResetAllParticlesOnEntity)
		data.m_fFlags |= PARTICLE_DISPATCH_RESET_PARTICLES;
	
	if (bUseColors)
	{
		data.m_bCustomColors = true;
		data.m_CustomColors.m_vecColor1 = vecColor1;
		data.m_CustomColors.m_vecColor2 = vecColor2;
	}
	
	TE_DispatchEffect(0.0, "ParticleEffect", data);
}

stock void DispatchParticleEffect4(int iEffectIndex, float vecOrigin[3], float vecStart[3], float vecAngles[3], int iEntity = -1)
{
	CEffectData data;
	
	data.m_nHitBox = iEffectIndex;
	data.m_vOrigin = vecOrigin;
	data.m_vStart = vecStart;
	data.m_vAngles = vecAngles;
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
		data.m_fFlags |= PARTICLE_DISPATCH_FROM_ENTITY;
		data.m_nDamageType = PATTACH_CUSTOMORIGIN;
	}
	else
	{
		data.m_nEntIndex = 0;
	}
	
	TE_DispatchEffect(0.0, "ParticleEffect", data);
}

stock void DispatchParticleEffect5(const char[] sParticleName, float vecOrigin[3], float vecAngles[3], float vecColor1[3], float vecColor2[3], bool bUseColors = true, int iEntity = -1, int iAttachType = PATTACH_CUSTOMORIGIN)
{
	int iEffectIndex = GetParticleSystemIndex(sParticleName);
	
	CEffectData data;
	
	data.m_nHitBox = iEffectIndex;
	data.m_vOrigin = vecOrigin;
	data.m_vAngles = vecAngles;
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
		data.m_fFlags |= PARTICLE_DISPATCH_FROM_ENTITY;
		data.m_nDamageType = PATTACH_CUSTOMORIGIN;
	}
	else
	{
		data.m_nEntIndex = 0;
	}
	
	if (bUseColors)
	{
		data.m_bCustomColors = true;
		data.m_CustomColors.m_vecColor1 = vecColor1;
		data.m_CustomColors.m_vecColor2 = vecColor2;
	}
	
	TE_DispatchEffect(0.0, "ParticleEffect", data);
}

stock void DispatchParticleEffect6(const char[] sParticleName, float vecOrigin[3], float vecAngles[3], int iEntity = -1)
{
	int iIndex = GetParticleSystemIndex(sParticleName);
	DispatchParticleEffect4(iIndex, vecOrigin, vecOrigin, vecAngles, iEntity);
}

stock void DispatchParticleEffect7(const char[] sParticleName, float vecOrigin[3], float vecStart[3], float vecAngles[3], int iEntity = -1)
{
	int iIndex = GetParticleSystemIndex(sParticleName);
	DispatchParticleEffect4(iIndex, vecOrigin, vecStart, vecAngles, iEntity);
}

//Alternatively you can fire input DispatchEffect with param ParticleEffectStop
stock void StopParticleEffects(int iEntity)
{
	CEffectData data;
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
	}
	
	TE_DispatchEffect(0.0, "ParticleEffectStop", data);
}

stock void OSLib_DispatchParticleEffect(const char[] sParticleName, ParticleAttachment_t iAttachType, int iEntity, const char[] sAttachmentName, float vecOrigin[3], bool bHasOrigin, float vecColor1[3], float vecColor2[3], bool bUseColors, bool bResetAllParticlesOnEntity, te_tf_particle_effects_control_point_t controlPoint)
{
	int iAttachment = -1;
	
	if (iEntity != -1 && sAttachmentName[0])
	{
		iAttachment = LookupEntityAttachment(iEntity, sAttachmentName);
		
		if (iAttachment <= 0)
			return;
	}
	
	CEffectData data;
	
	data.m_nHitBox = GetParticleSystemIndex(sParticleName);
	
	if (bHasOrigin)
		data.m_vOrigin = vecOrigin;
	
	if (iEntity != -1)
	{
		data.m_nEntIndex = iEntity;
		data.m_fFlags |= PARTICLE_DISPATCH_FROM_ENTITY;
		
		if (!bHasOrigin)
			BaseEntity_GetAbsOrigin(iEntity, data.m_vOrigin);
	}
	
	data.m_nDamageType = iAttachType;
	data.m_nAttachmentIndex = iAttachment;
	
	if (bResetAllParticlesOnEntity)
		data.m_fFlags |= PARTICLE_DISPATCH_RESET_PARTICLES;
	
	if (bUseColors)
	{
		data.m_bCustomColors = true;
		data.m_CustomColors.m_vecColor1 = vecColor1;
		data.m_CustomColors.m_vecColor2 = vecColor2;
	}
	
	data.m_bControlPoint1 = true;
	data.m_ControlPoint1.m_eParticleAttachment = controlPoint.m_eParticleAttachment;
	data.m_ControlPoint1.m_vecOffset = controlPoint.m_vecOffset;
	
	TE_DispatchEffect(0.0, "ParticleEffect", data);
}