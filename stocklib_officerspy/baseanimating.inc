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
	
	property int m_nSkin
	{
		public get()	{ return GetEntProp(this.index, Prop_Data, "m_nSkin"); }
		public set(int value)
		{
			SetEntProp(this.index, Prop_Data, "m_nSkin", value);
		}
	}
	
	public float GetPlaybackRate()
	{
		return BaseAnimating_GetPlaybackRate(this.index);
	}
	
	public void SetPlaybackRate(float rate)
	{
		BaseAnimating_SetPlaybackRate(this.index, rate);
	}
	
	public int GetSequence()
	{
		return BaseAnimating_GetSequence(this.index);
	}
	
	public void SetModelScale(float scale, float change_duration = 0.0)
	{
		BaseAnimating_SetModelScale(this.index, scale, change_duration);
	}
	
	public float GetModelScale()
	{
		return BaseAnimating_GetModelScale(this.index);
	}
}

stock float BaseAnimating_GetPlaybackRate(int entity)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flPlaybackRate");
}

stock void BaseAnimating_SetPlaybackRate(int entity, float rate)
{
	SetEntPropFloat(entity, Prop_Data, "m_flPlaybackRate", rate);
}

stock int BaseAnimating_GetSequence(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_nSequence");
}

stock void BaseAnimating_SetModelScale(int entity, float scale, float change_duration = 0.0)
{
	float vec[3];
	vec[0] = scale;
	vec[1] = change_duration;
	
	SetVariantVector3D(vec);
	AcceptEntityInput(entity, "SetModelScale");
}

stock float BaseAnimating_GetModelScale(int entity)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flModelScale");
}