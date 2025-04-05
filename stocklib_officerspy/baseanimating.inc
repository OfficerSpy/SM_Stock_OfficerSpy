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
	
	public void SetCycle(float flCycle)
	{
		BaseAnimating_SetCycle(this.index, flCycle);
	}
	
	public float GetCycle()
	{
		return BaseAnimating_GetCycle(this.index);
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
	
	public bool IsActivityFinished()
	{
		return BaseAnimating_IsActivityFinished(this.index);
	}
	
	public bool IsSequenceFinished()
	{
		return BaseAnimating_IsSequenceFinished(this.index);
	}
	
	public bool SequenceLoops()
	{
		return BaseAnimating_SequenceLoops(this.index);
	}
	
	public void StopAnimation()
	{
		BaseAnimating_StopAnimation(this.index);
	}
	
	public int GetSkin()
	{
		return BaseAnimating_GetSkin(this.index);
	}
	
	public void SetSkin(int nSkin)
	{
		BaseAnimating_SetSkin(this.index, nSkin);
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

stock void BaseAnimating_SetCycle(int entity, float flCycle)
{
	SetEntPropFloat(entity, Prop_Data, "m_flCycle", flCycle);
}

stock float BaseAnimating_GetCycle(int entity)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flCycle");
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

stock bool BaseAnimating_IsActivityFinished(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Data, "m_bSequenceFinished"));
}

stock bool BaseAnimating_IsSequenceFinished(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Data, "m_bSequenceFinished"));
}

stock bool BaseAnimating_SequenceLoops(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Data, "m_bSequenceLoops"));
}

stock void BaseAnimating_StopAnimation(int entity)
{
	SetEntPropFloat(entity, Prop_Data, "m_flPlaybackRate", 0.0);
}

stock int BaseAnimating_GetSkin(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_nSkin");
}

stock void BaseAnimating_SetSkin(int entity, int nSkin)
{
	SetEntProp(entity, Prop_Data, "m_nSkin", nSkin);
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