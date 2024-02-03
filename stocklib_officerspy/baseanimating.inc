#if defined _stock_officerspy_baseanimating_included
	#endinput
#endif
#define _stock_officerspy_baseanimating_included

stock void BaseAnimating_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	SetVariantVector3D({scale, change_duration, 0.0});
	AcceptEntityInput(entity, "SetModelScale");
}