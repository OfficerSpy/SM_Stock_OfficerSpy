#if defined _stock_officerspy_baseentity_included
	#endinput
#endif
#define _stock_officerspy_baseentity_included

#include <stocklib_officerspy/shared/shareddefs>
#include <stocklib_officerspy/public/const>
#include <stocklib_officerspy/public/bspflags>

methodmap OSBaseEntity
{
	public OSBaseEntity(int index)
	{
		return view_as<OSBaseEntity>(index);
	}
	
	property int index
	{
		public get()	{ return view_as<int>(this); }
	}
	
	property int m_lifeState
	{
		public get()	{ return GetEntProp(this.index, Prop_Data, "m_lifeState"); }
		public set(int value)	{ SetEntProp(this.index, Prop_Data, "m_lifeState", value); }
	}
	
	property int m_takedamage
	{
		public get()	{ return GetEntProp(this.index, Prop_Data, "m_takedamage"); }
		public set(int value)	{ SetEntProp(this.index, Prop_Data, "m_takedamage", value); }
	}
	
	property int m_iMaxHealth
	{
		public get()	{ return GetEntProp(this.index, Prop_Data, "m_iMaxHealth"); }
		public set(int value)	{ SetEntProp(this.index, Prop_Data, "m_iMaxHealth", value); }
	}
	
	property int m_iHealth
	{
		public get()	{ return GetEntProp(this.index, Prop_Data, "m_iHealth"); }
		public set(int value)
		{
			SetEntProp(this.index, Prop_Data, "m_iHealth", value);
		}
	}
	
	public void ClearModelIndexOverrides()
	{
		BaseEntity_ClearModelIndexOverrides(this.index);
	}
	
	public void SetModelIndexOverride(int index, int nValue)
	{
		BaseEntity_SetModelIndexOverride(this.index, index, nValue);
	}
	
	public void SetOwnerEntity(int pOwner)
	{
		SetEntityOwner(this.index, pOwner);
	}
	
	public int GetMaxHealth()
	{
		return BaseEntity_GetMaxHealth(this.index);
	}
	
	public void SetMaxHealth(int amt)
	{
		BaseEntity_SetMaxHealth(this.index, amt);
	}
	
	public int GetHealth()
	{
		return BaseEntity_GetHealth(this.index);
	}
	
	public void SetHealth(int amt)
	{
		SetEntityHealth(this.index, amt);
	}
	
	public void ChangeTeam(int iTeamNum)
	{
		BaseEntity_ChangeTeam(this.index, iTeamNum);
	}
	
	public int GetMoveParent()
	{
		return BaseEntity_GetMoveParent(this.index);
	}
	
	public int FirstMoveChild()
	{
		return BaseEntity_FirstMoveChild(this.index);
	}
	
	public int NextMovePeer()
	{
		return BaseEntity_NextMovePeer(this.index);
	}
	
	public int GetParent()
	{
		return BaseEntity_GetParent(this.index);
	}
	
	public int GetParentAttachment()
	{
		return BaseEntity_GetParentAttachment(this.index);
	}
	
	public void GetEntityName(char[] buffer, int maxlen)
	{
		BaseEntity_GetEntityName(this.index, buffer, maxlen);
	}
	
	public void SetName(char[] newName)
	{
		BaseEntity_SetName(this.index, newName);
	}
	
	public int GetSpawnFlags()
	{
		return BaseEntity_GetSpawnFlags(this.index);
	}
	
	public void AddSpawnFlags(int nFlags)
	{
		BaseEntity_AddSpawnFlags(this.index, nFlags);
	}
	
	public void RemoveSpawnFlags(int nFlags)
	{
		BaseEntity_RemoveSpawnFlags(this.index, nFlags);
	}
	
	public void ClearSpawnFlags()
	{
		BaseEntity_ClearSpawnFlags(this.index);
	}
	
	public bool HasSpawnFlags(int nFlags)
	{
		return BaseEntity_HasSpawnFlags(this.index, nFlags);
	}
	
	public void GetLocalOrigin(float buffer[3])
	{
		BaseEntity_GetLocalOrigin(this.index, buffer);
	}
	
	public void GetLocalAngles(float buffer[3])
	{
		BaseEntity_GetLocalAngles(this.index, buffer);
	}
	
	public void GetAbsOrigin(float buffer[3])
	{
		BaseEntity_GetAbsOrigin(this.index, buffer);
	}
	
	public void GetAbsAngles(float buffer[3])
	{
		BaseEntity_GetAbsAngles(this.index, buffer);
	}
	
	public SolidType_t GetSolid()
	{
		return BaseEntity_GetSolid(this.index);
	}
	
	public int GetSolidFlags()
	{
		return BaseEntity_GetSolidFlags(this.index);
	}
	
	public int GetEFlags()
	{
		return BaseEntity_GetEFlags(this.index);
	}
	
	public void SetEFlags(int iEFlags)
	{
		BaseEntity_SetEFlags(this.index, iEFlags);
	}
	
	public void AddEFlags(int nEFlagMask)
	{
		BaseEntity_AddEFlags(this.index, nEFlagMask);
	}
	
	public void RemoveEFlags(int nEFlagMask)
	{
		BaseEntity_RemoveEFlags(this.index, nEFlagMask);
	}
	
	public bool IsEFlagSet(int nEFlagMask)
	{
		return BaseEntity_IsEFlagSet(this.index, nEFlagMask);
	}
	
	public bool IsTransparent()
	{
		return BaseEntity_IsTransparent(this.index);
	}
	
	public void GetLocalVelocity(float buffer[3])
	{
		BaseEntity_GetLocalVelocity(this.index, buffer);
	}
	
	public void GetAbsVelocity(float buffer[3])
	{
		BaseEntity_GetAbsVelocity(this.index, buffer);
	}
	
	public void GetLocalAngularVelocity(float buffer[3])
	{
		BaseEntity_GetLocalAngularVelocity(this.index, buffer);
	}
	
	public void GetBaseVelocity(float buffer[3])
	{
		BaseEntity_GetBaseVelocity(this.index, buffer);
	}
	
	public void SetBaseVelocity(float vec[3])
	{
		BaseEntity_SetBaseVelocity(this.index, vec);
	}
	
	public float GetGravity()
	{
		return GetEntityGravity(this.index);
	}
	
	public void SetGravity(float gravity)
	{
		SetEntityGravity(this.index, gravity);
	}
	
	public bool IsPlayerSimulated()
	{
		return BaseEntity_IsPlayerSimulated(this.index);
	}
	
	public MoveType GetMoveType()
	{
		return GetEntityMoveType(this.index);
	}
	
	public int GetMoveCollide()
	{
		return BaseEntity_GetMoveCollide(this.index);
	}
	
	public int GetCollisionGroup()
	{
		return BaseEntity_GetCollisionGroup(this.index);
	}
	
	public int GetFlags()
	{
		return GetEntityFlags(this.index);
	}
	
	public bool IsAlive()
	{
		return BaseEntity_IsAlive(this.index);
	}
	
	public int GetOwnerEntity()
	{
		return BaseEntity_GetOwnerEntity(this.index);
	}
	
	public bool IsBaseObject()
	{
		return BaseEntity_IsBaseObject(this.index);
	}
	
	public bool FVisible1(int pEntity, int traceMask, int ppBlocker = -1)
	{
		return BaseEntity_FVisible1(this.index, pEntity, traceMask, ppBlocker);
	}
	
	public int GetTeamNumber()
	{
		return BaseEntity_GetTeamNumber(this.index);
	}
	
	public void EyePosition(float buffer[3])
	{
		BaseEntity_EyePosition(this.index, buffer);
	}
	
	public void EyeAngles(float buffer[3])
	{
		BaseEntity_EyeAngles(this.index, buffer);
	}
	
	public void LocalEyeAngles(float buffer[3])
	{
		BaseEntity_LocalEyeAngles(this.index, buffer);
	}
	
	public void EarPosition(float buffer[3])
	{
		BaseEntity_EarPosition(this.index, buffer);
	}
	
	public void SetViewOffset(float vec[3])
	{
		BaseEntity_SetViewOffset(this.index, vec);
	}
	
	public void GetViewOffset(float buffer[3])
	{
		BaseEntity_GetViewOffset(this.index, buffer);
	}
	
	public void ApplyAbsVelocityImpulse(const float inVecImpulse[3])
	{
		BaseEntity_ApplyAbsVelocityImpulse(this.index, inVecImpulse);
	}
	
	public void WorldSpaceCenter(float buffer[3])
	{
		BaseEntity_WorldSpaceCenter(this.index, buffer);
	}
	
	public void AddEffects(int nEffects)
	{
		BaseEntity_AddEffects(this.index, nEffects);
	}
	
	public void RemoveEffects(int nEffects)
	{
		BaseEntity_RemoveEffects(this.index, nEffects);
	}
	
	public bool IsPlayer()
	{
		return BaseEntity_IsPlayer(this.index);
	}
	
	public bool IsCombatItem()
	{
		return BaseEntity_IsCombatItem(this.index);
	}
	
	public bool ShouldCollide(int collisionGroup, int contentsMask)
	{
		return BaseEntity_ShouldCollide(this.index, collisionGroup, contentsMask);
	}
	
	//The following functions are for vscript mods only
	
	public void MarkNeedsNamePurge()
	{
		BaseEntity_MarkNeedsNamePurge(this.index);
	}
	
	public void TerminateScriptScope()
	{
		BaseEntity_TerminateScriptScope(this.index);
	}
}

stock void BaseEntity_ClearModelIndexOverrides(int entity)
{
	for (int i = 0; i < MAX_VISION_MODES; i++)
		SetEntProp(entity, Prop_Send, "m_nModelIndexOverrides", 0, _, i);
}

stock void BaseEntity_SetModelIndexOverride(int entity, int index, int nValue)
{
	SetEntProp(entity, Prop_Send, "m_nModelIndexOverrides", nValue, _, index);
}

#pragma deprecated Use SetEntityOwner instead
stock void BaseEntity_SetOwnerEntity(int entity, int pOwner)
{
	SetEntPropEnt(entity, Prop_Send, "m_hOwnerEntity", pOwner);
}

stock int BaseEntity_GetMaxHealth(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iMaxHealth");
}

stock void BaseEntity_SetMaxHealth(int entity, int amt)
{
	SetEntProp(entity, Prop_Data, "m_iMaxHealth", amt);
}

stock int BaseEntity_GetHealth(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iHealth");
}

stock void BaseEntity_SetHealth(int entity, int amt)
{
	SetEntityHealth(entity, amt);
}

stock void BaseEntity_ChangeTeam(int entity, int iTeamNum)
{
	SetVariantInt(iTeamNum);
	AcceptEntityInput(entity, "SetTeam");
}

stock int BaseEntity_GetMoveParent(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMoveParent");
}

stock int BaseEntity_FirstMoveChild(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMoveChild");
}

stock int BaseEntity_NextMovePeer(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_hMovePeer");
}

stock int BaseEntity_GetParent(int entity)
{
	return GetEntPropEnt(entity, Prop_Data, "m_pParent");
}

stock int BaseEntity_GetParentAttachment(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iParentAttachment");
}

stock void BaseEntity_GetEntityName(int entity, char[] buffer, int maxlen)
{
	GetEntPropString(entity, Prop_Data, "m_iName", buffer, maxlen);
}

stock void BaseEntity_SetName(int entity, char[] newName)
{
	DispatchKeyValue(entity, "targetname", newName);
}

stock int BaseEntity_GetSpawnFlags(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_spawnflags");
}

stock void BaseEntity_AddSpawnFlags(int entity, int nFlags)
{
	int flags = GetEntProp(entity, Prop_Data, "m_spawnflags");
	flags |= nFlags;
	SetEntProp(entity, Prop_Data, "m_spawnflags", flags);
}

stock void BaseEntity_RemoveSpawnFlags(int entity, int nFlags)
{
	int flags = GetEntProp(entity, Prop_Data, "m_spawnflags");
	flags &= ~nFlags;
	SetEntProp(entity, Prop_Data, "m_spawnflags", flags);
}

stock void BaseEntity_ClearSpawnFlags(int entity)
{
	SetEntProp(entity, Prop_Data, "m_spawnflags", 0);
}

stock bool BaseEntity_HasSpawnFlags(int entity, int nFlags)
{
	return GetEntProp(entity, Prop_Data, "m_spawnflags") & nFlags != 0;
}

stock void BaseEntity_GetLocalOrigin(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecOrigin", buffer);
}

stock void BaseEntity_GetLocalAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angRotation", buffer);
}

stock void BaseEntity_GetAbsOrigin(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAbsOrigin", buffer);
}

stock void BaseEntity_GetAbsAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angAbsRotation", buffer);
}

stock SolidType_t BaseEntity_GetSolid(int entity)
{
	//CCollisionProperty::GetSolid
	return view_as<SolidType_t>(GetEntProp(entity, Prop_Data, "m_nSolidType"));
}

stock int BaseEntity_GetSolidFlags(int entity)
{
	//CCollisionProperty::GetSolidFlags
	return GetEntProp(entity, Prop_Data, "m_usSolidFlags");
}

stock int BaseEntity_GetEFlags(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_iEFlags");
}

stock void BaseEntity_SetEFlags(int entity, int iEFlags)
{
	SetEntProp(entity, Prop_Data, "m_iEFlags", iEFlags);
	
	if (iEFlags & (EFL_FORCE_CHECK_TRANSMIT | EFL_IN_SKYBOX))
	{
		//MISSING: DispatchUpdateTransmitState();
	}
}

stock void BaseEntity_AddEFlags(int entity, int nEFlagMask)
{
	SetEntProp(entity, Prop_Data, "m_iEFlags", GetEntProp(entity, Prop_Data, "m_iEFlags") | nEFlagMask);
	
	if (nEFlagMask & (EFL_FORCE_CHECK_TRANSMIT | EFL_IN_SKYBOX))
	{
		//MISSING: DispatchUpdateTransmitState();
	}
}

stock void BaseEntity_RemoveEFlags(int entity, int nEFlagMask)
{
	SetEntProp(entity, Prop_Data, "m_iEFlags", GetEntProp(entity, Prop_Data, "m_iEFlags") & ~nEFlagMask);
	
	if (nEFlagMask & (EFL_FORCE_CHECK_TRANSMIT | EFL_IN_SKYBOX))
	{
		//MISSING: DispatchUpdateTransmitState();
	}
}

stock bool BaseEntity_IsEFlagSet(int entity, int nEFlagMask)
{
	return GetEntProp(entity, Prop_Data, "m_iEFlags") & nEFlagMask != 0;
}

stock bool BaseEntity_IsTransparent(int entity)
{
	return GetEntityRenderMode(entity) != RENDER_NORMAL;
}

stock void BaseEntity_GetLocalVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecVelocity", buffer);
}

stock void BaseEntity_GetAbsVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAbsVelocity", buffer);
}

stock void BaseEntity_GetLocalAngularVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecAngVelocity", buffer);
}

stock void BaseEntity_GetBaseVelocity(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecBaseVelocity", buffer);
}

stock void BaseEntity_SetBaseVelocity(int entity, float vec[3])
{
	SetEntPropVector(entity, Prop_Data, "m_vecBaseVelocity", vec);
}

#pragma deprecated Use GetEntityGravity instead
stock float BaseEntity_GetGravity(int entity)
{
	return GetEntPropFloat(entity, Prop_Data, "m_flGravity");
}

#pragma deprecated Use SetEntityGravity instead
stock void BaseEntity_SetGravity(int entity, float gravity)
{
	SetEntPropFloat(entity, Prop_Data, "m_flGravity", gravity);
}

stock bool BaseEntity_IsPlayerSimulated(int entity)
{
	return view_as<bool>(GetEntProp(entity, Prop_Send, "m_bIsPlayerSimulated"));
}

#pragma deprecated Use GetEntityMoveType instead
stock MoveType BaseEntity_GetMoveType(int entity)
{
	return view_as<MoveType>(GetEntProp(entity, Prop_Data, "m_MoveType"));
}

stock int BaseEntity_GetMoveCollide(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_MoveCollide");
}

stock int BaseEntity_GetCollisionGroup(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_CollisionGroup");
}

#pragma deprecated Use GetEntityFlags instead
stock int BaseEntity_GetFlags(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_fFlags");
}

stock bool BaseEntity_IsAlive(int entity)
{
	return GetEntProp(entity, Prop_Data, "m_lifeState") == LIFE_ALIVE;
}

stock int BaseEntity_GetOwnerEntity(int entity)
{
	return GetEntPropEnt(entity, Prop_Send, "m_hOwnerEntity");
}

stock bool BaseEntity_IsBaseObject(int entity)
{
	//In TF2, only CBaseObject entities are base objects
	if (GetEngineVersion() == Engine_TF2)
		return HasEntProp(entity, Prop_Data, "CBaseObjectUpgradeThink");
	
	return false;
}

stock bool BaseEntity_FVisible1(int entity, int pEntity, int traceMask, int ppBlocker = -1)
{
	if (GetEntityFlags(pEntity) & FL_NOTARGET)
		return false;
	
	float vecLookerOrigin[3]; BaseEntity_EyePosition(entity, vecLookerOrigin);
	float vecTargetOrigin[3]; BaseEntity_EyePosition(pEntity, vecTargetOrigin);
	
	Handle trace;
	
	if (FindConVar("ai_LOS_mode").BoolValue)
	{
		trace = TR_TraceRayEx(vecLookerOrigin, vecTargetOrigin, traceMask, RayType_EndPoint);
	}
	else
	{
		if (traceMask == MASK_BLOCKLOS)
			traceMask = MASK_BLOCKLOS_AND_NPCS;
		
		if (BaseEntity_IsPlayer(entity))
			traceMask &= ~CONTENTS_BLOCKLOS;
		
		trace = TR_TraceRayFilterEx(vecLookerOrigin, vecTargetOrigin, traceMask, RayType_EndPoint, TraceFilterLOS);
	}
	
	if (TR_GetFraction(trace) != 1.0 || TR_StartSolid(trace))
	{
		if (TR_GetEntityIndex(trace) == pEntity)
		{
			delete trace;
			return true;
		}
		
		//TODO: vehicle stuff?
		
		if (ppBlocker > 0)
			ppBlocker = TR_GetEntityIndex(trace);
		
		delete trace;
		return false;
	}
	
	delete trace;
	return true;
}

stock int BaseEntity_GetTeamNumber(int entity)
{
	return GetEntProp(entity, Prop_Send, "m_iTeamNum");
}

stock void BaseEntity_EyePosition(int entity, float buffer[3])
{
	if (BaseEntity_IsPlayer(entity))
	{
		GetClientEyePosition(entity, buffer);
		return;
	}
	
	float absOrigin[3]; GetEntPropVector(entity, Prop_Data, "m_vecAbsOrigin", absOrigin); //GetAbsOrigin
	float viewOffset[3]; GetEntPropVector(entity, Prop_Data, "m_vecViewOffset", viewOffset); //GetViewOffset
	
	AddVectors(absOrigin, viewOffset, buffer);
}

stock void BaseEntity_EyeAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angAbsRotation", buffer); //GetAbsAngles
}

stock void BaseEntity_LocalEyeAngles(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_angRotation", buffer); //GetLocalAngles
}

stock void BaseEntity_EarPosition(int entity, float buffer[3])
{
	BaseEntity_EyePosition(entity, buffer);
}

stock void BaseEntity_SetViewOffset(int entity, float vec[3])
{
	SetEntPropVector(entity, Prop_Data, "m_vecViewOffset", vec);
}

stock void BaseEntity_GetViewOffset(int entity, float buffer[3])
{
	GetEntPropVector(entity, Prop_Data, "m_vecViewOffset", buffer);
}

stock void BaseEntity_ApplyAbsVelocityImpulse(int entity, const float inVecImpulse[3])
{
	if (!IsNullVector(inVecImpulse))
	{
		float vecImpulse[3]; vecImpulse = inVecImpulse;
		
		//MISSING: safety checks?
		
		if (GetEntityMoveType(entity) == MOVETYPE_VPHYSICS)
		{
			//MISSING: VPhysicsGetObject()->AddVelocity( &vecImpulse, NULL );
		}
		else
		{
			float vAbsVelocity[3]; GetEntPropVector(entity, Prop_Data, "m_vecAbsVelocity", vAbsVelocity); //GetAbsVelocity
			
			float vecResult[3];
			AddVectors(vAbsVelocity, vecImpulse, vecResult);
			TeleportEntity(entity, NULL_VECTOR, NULL_VECTOR, vecResult); //SetAbsVelocity
		}
	}
}

stock void BaseEntity_WorldSpaceCenter(int entity, float buffer[3])
{
	/* The actual function goes through like this:
	CBaseEntity::WorldSpaceCenter < CCollisionProperty::WorldSpaceCenter */
	
	//NOTE: for now, let's just use this method created by Mikusch
	float vecOrigin[3], vecMins[3], vecMaxs[3], vecOffset[3];
	GetEntPropVector(entity, Prop_Data, "m_vecAbsOrigin", vecOrigin);
	GetEntPropVector(entity, Prop_Data, "m_vecMins", vecMins);
	GetEntPropVector(entity, Prop_Data, "m_vecMaxs", vecMaxs);
	
	AddVectors(vecMins, vecMaxs, vecOffset);
	ScaleVector(vecOffset, 0.5);
	AddVectors(vecOrigin, vecOffset, buffer);
}

stock void BaseEntity_AddEffects(int entity, int nEffects)
{
	SetEntProp(entity, Prop_Send, "m_fEffects", GetEntProp(entity, Prop_Send, "m_fEffects") | nEffects);
	
	if (nEffects & EF_NODRAW)
	{
		//MISSING: DispatchUpdateTransmitState
	}
}

stock void BaseEntity_RemoveEffects(int entity, int nEffects)
{
	SetEntProp(entity, Prop_Send, "m_fEffects", GetEntProp(entity, Prop_Send, "m_fEffects") & ~nEffects);
	
	if (nEffects & EF_NODRAW)
	{
		/* MISSING:
		NetworkProp()->MarkPVSInformationDirty();
		DispatchUpdateTransmitState(); */
	}
}

stock bool BaseEntity_IsPlayer(int entity)
{
	//Is there not a better way to do this?
	return entity > 0 && entity <= MaxClients;
}

stock bool BaseEntity_IsCombatItem(int entity)
{
	char classname[PLATFORM_MAX_PATH]; GetEdictClassname(entity, classname, sizeof(classname));
	
	if (GetEngineVersion() == Engine_TF2)
	{
		//Only these entities are combat items currently
		return StrEqual(classname, "entity_medigun_shield") || StrEqual(classname, "entity_revive_marker");
	}
	
	return false;
}

stock bool BaseEntity_ShouldCollide(int entity, int collisionGroup, int contentsMask)
{
	if (GetEntProp(entity, Prop_Send, "m_CollisionGroup") == COLLISION_GROUP_DEBRIS)
		if (!(contentsMask & CONTENTS_DEBRIS))
			return false;
	
	return true;
}

stock bool BaseEntity_BlocksLOS(int entity)
{
	return !(GetEntProp(entity, Prop_Data, "m_iEFlags") & EFL_DONTBLOCKLOS);
}

//BELOW FUNCTIONS ARE FOR VSCRIPT GAMES ONLY

stock void BaseEntity_MarkNeedsNamePurge(int entity)
{
	SetEntProp(entity, Prop_Data, "m_bForcePurgeFixedupStrings", true);
}

stock void BaseEntity_TerminateScriptScope(int entity)
{
	AcceptEntityInput(entity, "TerminateScriptScope");
}

// EXTRA UTILITY FUNCTIONS

static bool TraceFilterLOS(int entity, int contentsMask, any data)
{
	if (!BaseEntity_BlocksLOS(entity))
		return false;
	
	//TODO: finish me
	return true;
}