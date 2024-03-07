#if defined _stock_officerspy_gamerules_included
	#endinput
#endif
#define _stock_officerspy_gamerules_included

stock int CGameRules_DefaultFOV()
{
	switch(GetEngineVersion())
	{
		case Engine_CSS:
		{
			//CCSGameRules::DefaultFOV
			return 90;
		}
		case Engine_TF2:
		{
			//CTFGameRules::DefaultFOV
			return 75;
		}
	}
	
	return 90;
}