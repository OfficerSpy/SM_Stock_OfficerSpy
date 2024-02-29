#if defined _stock_officerspy_cppvalve_included
	#endinput
#endif
#define _stock_officerspy_cppvalve_included

stock int ClampInt(const int val, const int minVal, const int maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}

stock float ClampFloat(const float val, const float minVal, const float maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}

stock int MinInt(const int val1, const int val2)
{
	return val1 < val2 ? val1 : val2;
}

stock float MinFloat(const float val1, const float val2)
{
	return val1 < val2 ? val1 : val2;
}

stock int MaxInt(const int val1, const int val2)
{
	return val1 > val2 ? val1 : val2;
}

stock float MaxFloat(const float val1, const float val2)
{
	return val1 > val2 ? val1 : val2;
}