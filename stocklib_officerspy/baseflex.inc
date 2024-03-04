#if defined _stock_officerspy_baseflex_included
	#endinput
#endif
#define _stock_officerspy_baseflex_included

#include <stocklib_officerspy/baseanimating>

methodmap OSBaseFlex < OSBaseAnimating
{
	public OSBaseFlex(int index)
	{
		return view_as<OSBaseFlex>(index);
	}
}