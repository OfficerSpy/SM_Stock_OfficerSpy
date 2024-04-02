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

stock float RemapValClamped(float val, float A, float B, float C, float D)
{
	if (A == B)
		return val >= B ? D : C;
	
	float cVal = (val - A) / (B - A);
	cVal = ClampFloat(cVal, 0.0, 1.0);
	
	return C + (D - C) * cVal;
}