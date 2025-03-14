#if defined _stock_officerspy_mathlib_included
	#endinput
#endif
#define _stock_officerspy_mathlib_included

stock float anglemod(float a)
{
	a = (360.0 / 65536) * (RoundToNearest(a * (65536.0 / 360.0)) & 65535);
	return a;
}