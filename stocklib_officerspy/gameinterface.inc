#if defined _stock_officerspy_gameinterface_included
	#endinput
#endif
#define _stock_officerspy_gameinterface_included

stock int GetParticleSystemIndex(const char[] pParticleSystemName)
{
	if (pParticleSystemName[0])
	{
		int iStringTableParticleEffectNamesIndex = FindStringTable("ParticleEffectNames");
		if (iStringTableParticleEffectNamesIndex == INVALID_STRING_TABLE)
		{
			LogError("Missing string table \"ParticleEffectNames\"!");
			return 0;
		}
		
		int nIndex = FindStringIndex(iStringTableParticleEffectNamesIndex, pParticleSystemName);
		if (nIndex == INVALID_STRING_INDEX)
		{
			LogError("Missing precache for particle system \"%s\"!", pParticleSystemName);
			return 0;
		}
		
		return nIndex;
	}

	return 0;
}