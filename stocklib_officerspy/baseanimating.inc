#if defined _stock_officerspy_baseanimating_included
	#endinput
#endif
#define _stock_officerspy_baseanimating_included

#include <stocklib_officerspy/baseentity>

methodmap OSBaseAnimating < OSBaseEntity
{
	public OSBaseAnimating(int index)
	{
		return view_as<OSBaseAnimating>(index);
	}
	
	public void SetModelScale(float scale, float change_duration = 0.0)
	{
		BaseAnimating_SetModelScale(this.index, scale, change_duration);
	}
}

stock void BaseAnimating_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	float vec[3];
	vec[0] = scale;
	vec[1] = change_duration;
	
	SetVariantVector3D(vec);
	AcceptEntityInput(entity, "SetModelScale");
}