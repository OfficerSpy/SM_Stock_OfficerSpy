#if defined _stock_officerspy_teeffectdispatch_included
	#endinput
#endif
#define _stock_officerspy_teeffectdispatch_included

#include <stocklib_officerspy/shared/effect_dispatch_data>

//NOTE: we omitted Vector pos as it doesn't seem to actually be used in this
stock void TE_DispatchEffect(float delay, const char[] sName, const CEffectData data)
{
	data.m_iEffectName = OSLib_GetEffectDispatchIndex(sName);
	
	TE_Start("EffectDispatch");
	TE_WriteFloat("m_vOrigin[0]", data.m_vOrigin[0]);
	TE_WriteFloat("m_vOrigin[1]", data.m_vOrigin[1]);
	TE_WriteFloat("m_vOrigin[2]", data.m_vOrigin[2]);
	TE_WriteFloat("m_vStart[0]", data.m_vStart[0]);
	TE_WriteFloat("m_vStart[1]", data.m_vStart[1]);
	TE_WriteFloat("m_vStart[2]", data.m_vStart[2]);
	TE_WriteVector("m_vNormal", data.m_vNormal);
	TE_WriteVector("m_vAngles", data.m_vAngles);
	TE_WriteNum("m_fFlags", data.m_fFlags);
	TE_WriteNum("entindex", data.m_nEntIndex);
	
	//TODO: omit if statements whenever we give CEffectData default values
	if (data.m_flScale)
		TE_WriteFloat("m_flScale", data.m_flScale);
	
	TE_WriteFloat("m_flMagnitude", data.m_flMagnitude);
	TE_WriteFloat("m_flRadius", data.m_flRadius);
	TE_WriteNum("m_nAttachmentIndex", data.m_nAttachmentIndex);
	TE_WriteNum("m_nSurfaceProp", data.m_nSurfaceProp);
	TE_WriteNum("m_nMaterial", data.m_nMaterial);
	TE_WriteNum("m_nDamageType", data.m_nDamageType);
	TE_WriteNum("m_nHitBox", data.m_nHitBox);
	TE_WriteNum("m_nColor", data.m_nColor);
	TE_WriteNum("m_bCustomColors", data.m_bCustomColors);
	TE_WriteVector("m_CustomColors.m_vecColor1", data.m_CustomColors.m_vecColor1);
	TE_WriteVector("m_CustomColors.m_vecColor2", data.m_CustomColors.m_vecColor2);
	TE_WriteNum("m_bControlPoint1", data.m_bControlPoint1);
	TE_WriteNum("m_ControlPoint1.m_eParticleAttachment", data.m_ControlPoint1.m_eParticleAttachment);
	TE_WriteFloat("m_ControlPoint1.m_vecOffset[0]", data.m_ControlPoint1.m_vecOffset[0]);
	TE_WriteFloat("m_ControlPoint1.m_vecOffset[1]", data.m_ControlPoint1.m_vecOffset[1]);
	TE_WriteFloat("m_ControlPoint1.m_vecOffset[2]", data.m_ControlPoint1.m_vecOffset[2]);
	TE_WriteNum("m_iEffectName", data.m_iEffectName);
	TE_SendToAll(delay);
}

//Fetch the index from g_pStringTableEffectDispatch corresponding to the effect name
stock int OSLib_GetEffectDispatchIndex(const char[] sEffectName)
{
	if (sEffectName[0])
	{
		int iStringTableParticleEffectNamesIndex = FindStringTable("EffectDispatch");
		
		if (iStringTableParticleEffectNamesIndex == INVALID_STRING_TABLE)
		{
			ThrowError("Missing string table \"EffectDispatch\"!");
			return 0;
		}
		
		int nIndex = FindStringIndex(iStringTableParticleEffectNamesIndex, sEffectName);
		
		if (nIndex == INVALID_STRING_INDEX)
		{
			ThrowError("Missing precache for effect name \"%s\"!", sEffectName);
			return 0;
		}
		
		return nIndex;
	}

	return 0;
}

/* This should actually be in TE_DispatchEffect but i am intentionally leaving it out
as a standalone function as you should only need to do this once for each string name */
stock void OSLib_AddStringToEffectDispatchTable(const char[] sName)
{
	int table = INVALID_STRING_TABLE;
	
	if (table == INVALID_STRING_TABLE)
	{
		table = FindStringTable("EffectDispatch");
	}
	
	bool save = LockStringTables(false);
	AddToStringTable(table, sName);
	LockStringTables(save);
}

stock void OSLib_AddStringToParticleEffectNamesTable(const char[] sName)
{
	int table = INVALID_STRING_TABLE;
	
	if (table == INVALID_STRING_TABLE)
	{
		table = FindStringTable("ParticleEffectNames");
	}
	
	bool save = LockStringTables(false);
	AddToStringTable(table, sName);
	LockStringTables(save);
}