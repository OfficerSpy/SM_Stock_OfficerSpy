#if defined _stock_officerspy_teamobjectiveresource_included
	#endinput
#endif
#define _stock_officerspy_teamobjectiveresource_included

#include <stocklib_officerspy/baseentity>

methodmap OSBaseTeamObjectiveResource < OSBaseEntity
{
	public OSBaseTeamObjectiveResource(int index)
	{
		return view_as<OSBaseTeamObjectiveResource>(index);
	}
}