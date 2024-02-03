#if defined _stock_officerspy_baseentity_included
	#endinput
#endif
#define _stock_officerspy_baseentity_included

#include <stocklib_officerspy/baseentity_shared>

#define BASEENT_LIFE_ALIVE				0
#define BASEENT_LIFE_DYING				1
#define BASEENT_LIFE_DEAD				2
#define BASEENT_LIFE_RESPAWNABLE		3
#define BASEENT_LIFE_DISCARDBODY		4

#define BASEENT_CONTENTS_BLOCKLOS	CONTENTS_MIST

#define BASEENT_MASK_BLOCKLOS			CONTENTS_SOLID|CONTENTS_MOVEABLE|BASEENT_CONTENTS_BLOCKLOS
#define BASEENT_MASK_BLOCKLOS_AND_NPCS	BASEENT_MASK_BLOCKLOS|CONTENTS_MONSTER

enum
{
	VISION_MODE_NONE = 0,
	VISION_MODE_PYRO,
	VISION_MODE_HALLOWEEN,
	VISION_MODE_ROME,
	MAX_VISION_MODES
};

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
	SetEntProp(entity, Prop_Data, "m_iHealth", amt);
}

stock void BaseEntity_ChangeTeam(int entity, int iTeamNum)
{
	SetEntProp(entity, Prop_Send, "m_iTeamNum", iTeamNum);
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

//Alternatively, you can set the keyvalue "targetname"
stock void BaseEntity_SetName(int entity, char[] newName)
{
	SetEntPropString(entity, Prop_Data, "m_iName", newName);
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
	return GetEntProp(entity, Prop_Data, "m_lifeState") == BASEENT_LIFE_ALIVE;
}

stock bool BaseEntity_FVisible1(int entity, int pEntity, int traceMask, int ppBlocker = -1)
{
	if (GetEntityFlags(pEntity) & FL_NOTARGET)
		return false;
	
	float vecLookerOrigin[3]; BaseEntity_EyePosition(entity, vecLookerOrigin);
	float vecTargetOrigin[3]; BaseEntity_EyePosition(pEntity, vecTargetOrigin);
	
	Handle trace;
	
	if (GetConVarBool(FindConVar("ai_LOS_mode")))
	{
		trace = TR_TraceRayEx(vecLookerOrigin, vecTargetOrigin, traceMask, RayType_EndPoint);
	}
	else
	{
		if (traceMask == BASEENT_MASK_BLOCKLOS)
			traceMask = BASEENT_MASK_BLOCKLOS_AND_NPCS;
		
		if (entity > 0 && entity <= MaxClients)
			traceMask &= ~BASEENT_CONTENTS_BLOCKLOS;
		
		//TODO: filter?
		trace = TR_TraceRayEx(vecLookerOrigin, vecTargetOrigin, traceMask, RayType_EndPoint);
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