#if defined _stock_officerspy_utilshared_included
	#endinput
#endif
#define _stock_officerspy_utilshared_included

#include <stocklib_officerspy/baseentity>
#include <stocklib_officerspy/public/model_types>

#define INTERVALTIMER_OFFSET_TIMESTAMP	0x4
#define COUNTDOWNTIMER_OFFSET_DURATION	0x4
#define COUNTDOWNTIMER_OFFSET_TIMESTAMP	0x8

methodmap IntervalTimer < Address
{
	property float m_timestamp
	{
		public get()
		{
			return LoadFromAddress(this + INTERVALTIMER_OFFSET_TIMESTAMP, NumberType_Int32);
		}
		public set(float value)
		{
			StoreToAddress(this + INTERVALTIMER_OFFSET_TIMESTAMP, value, NumberType_Int32, false);
		}
	}
	public void Reset()
	{
		this.m_timestamp = GetGameTime();
	}
	public void Start()
	{
		this.m_timestamp = GetGameTime();
	}
	public void Invalidate()
	{
		this.m_timestamp = -1.0;
	}
	public bool HasStarted()
	{
		return this.m_timestamp > 0.0;
	}
	public float GetElapsedTime()
	{
		return this.HasStarted() ? GetGameTime() - this.m_timestamp : 99999.9;
	}
	public bool IsLessThen(float duration)
	{
		return GetGameTime() - this.m_timestamp < duration ? true : false;
	}
	public bool IsGreaterThen(float duration)
	{
		return GetGameTime() - this.m_timestamp > duration ? true : false;
	}
}

methodmap CountdownTimer < Address
{
	property float m_duration
	{
		public get()
		{
			return LoadFromAddress(this + COUNTDOWNTIMER_OFFSET_DURATION, NumberType_Int32);
		}
		public set(float value)
		{
			StoreToAddress(this + COUNTDOWNTIMER_OFFSET_DURATION, value, NumberType_Int32, false);
		}
	}
	property float m_timestamp
	{
		public get()
		{
			return LoadFromAddress(this + COUNTDOWNTIMER_OFFSET_TIMESTAMP, NumberType_Int32);
		}
		public set(float value)
		{
			StoreToAddress(this + COUNTDOWNTIMER_OFFSET_TIMESTAMP, value, NumberType_Int32, false);
		}
	}
	public void Reset()
	{
		this.m_timestamp = GetGameTime() + m_duration;
	}
	public void Start(float duration)
	{
		this.m_timestamp = GetGameTime() + duration;
		this.m_duration = duration;
	}
	public void Invalidate()
	{
		this.m_timestamp = -1.0;
	}
	public bool HasStarted()
	{
		return this.m_timestamp > 0.0;
	}
	public bool IsElapsed()
	{
		return GetGameTime() > this.m_timestamp;
	}
	public float GetElapsedTime()
	{
		return GetGameTime() - this.m_timestamp + this.m_duration;
	}
	public float GetRemainingTime()
	{
		return this.m_timestamp - GetGameTime();
	}
	public float GetCountdownDuration()
	{
		return this.m_timestamp > 0.0 ? this.m_duration : 0.0;
	}
}

//NOTE: IHandleEntity is not used here as these are meant for TraceEntityFilter callbacks

stock bool PassServerEntityFilter(int iTouch, int iPass)
{
	/* if (!IsValidEntity(iPass))
		return false; */
	
	if (iTouch == iPass)
		return false;
	
	/* if (!IsValidEntity(iTouch) || !IsValidEntity(iPass))
		return true; */
	
	if (BaseEntity_GetOwnerEntity(iTouch) == iPass)
		return false;
	
	if (BaseEntity_GetOwnerEntity(iPass) == iTouch)
		return false;
	
	return true;
}

stock bool StandardFilterRules(int iEntity, int fContentsMask)
{
	/* if (!IsValidEntity(iEntity))
		return true; */
	
	SolidType_t solid = BaseEntity_GetSolid(iEntity);
	//MISSING: const model_t *pModel = pCollide->GetModel();
	
	if ((GetModelType(iEntity) != mod_brush) || (solid != SOLID_BSP && solid != SOLID_VPHYSICS))
	{
		if (fContentsMask & CONTENTS_MONSTER == 0)
			return false;
	}
	
	if (!(fContentsMask & CONTENTS_WINDOW) && BaseEntity_IsTransparent(iEntity))
		return false;
	
	if (!(fContentsMask & CONTENTS_MOVEABLE) && GetEntityMoveType(iEntity) == MOVETYPE_PUSH)
		return false;
	
	return true;
}

//Hack method, really should be getting it from CModelInfo but that is out of our scope here
static stock modtype_t GetModelType(int entity)
{
	char modelName[PLATFORM_MAX_PATH]; GetEntPropString(entity, Prop_Data, "m_ModelName", modelName, sizeof(modelName));
	
	if (modelName[0])
	{
		//TODO: get actual file extension, this just assumes the substring will only ever occur once in the path
		if (StrContains(modelName, ".spr", false) != -1 || StrContains(modelName, ".vmt", false) != -1)
		{
			return mod_sprite;
		}
		else if (StrContains(modelName, ".bsp", false) != -1)
		{
			return mod_brush;
		}
		else if (StrContains(modelName, ".mdl", false) != -1)
		{
			return mod_studio;
		}
	}
	
	return mod_bad;
}