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

stock bool CGameRules_ShouldCollide(int collisionGroup0, int collisionGroup1)
{
	if (collisionGroup0 > collisionGroup1)
	{
		//Swap places
		int old = collisionGroup0;
		collisionGroup0 = collisionGroup1;
		collisionGroup1 = old;
	}
	
	if (collisionGroup0 == COLLISION_GROUP_DEBRIS && collisionGroup1 == COLLISION_GROUP_PUSHAWAY)
		return true;
	
	if (collisionGroup0 == COLLISION_GROUP_IN_VEHICLE || collisionGroup1 == COLLISION_GROUP_IN_VEHICLE)
		return false;
	
	if (collisionGroup1 == COLLISION_GROUP_DOOR_BLOCKER && collisionGroup0 != COLLISION_GROUP_NPC)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_PLAYER && collisionGroup1 == COLLISION_GROUP_PASSABLE_DOOR)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_DEBRIS || collisionGroup0 == COLLISION_GROUP_DEBRIS_TRIGGER)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_DISSOLVING || collisionGroup1 == COLLISION_GROUP_DISSOLVING)
		if (collisionGroup0 != COLLISION_GROUP_NONE)
			return false;
	
	if (collisionGroup0 == COLLISION_GROUP_INTERACTIVE_DEBRIS && collisionGroup1 == COLLISION_GROUP_INTERACTIVE_DEBRIS)
		return false;
	
	if (collisionGroup0 == COLLISION_GROUP_BREAKABLE_GLASS && collisionGroup1 == COLLISION_GROUP_BREAKABLE_GLASS)
		return false;
	
	if (collisionGroup1 == COLLISION_GROUP_INTERACTIVE && collisionGroup0 != COLLISION_GROUP_NONE)
		return false;
	
	if (collisionGroup1 == COLLISION_GROUP_PROJECTILE)
		if (collisionGroup0 == COLLISION_GROUP_DEBRIS || collisionGroup0 == COLLISION_GROUP_WEAPON || collisionGroup0 == COLLISION_GROUP_PROJECTILE)
			return false;
	
	if (collisionGroup1 == COLLISION_GROUP_WEAPON)
		if (collisionGroup0 == COLLISION_GROUP_VEHICLE || collisionGroup0 == COLLISION_GROUP_PLAYER || collisionGroup0 == COLLISION_GROUP_NPC)
			return false;
	
	if (collisionGroup0 == COLLISION_GROUP_VEHICLE_CLIP || collisionGroup1 == COLLISION_GROUP_VEHICLE_CLIP)
	{
		if (collisionGroup0 == COLLISION_GROUP_VEHICLE)
			return true;
		
		return false;
	}
	
	return true;
}