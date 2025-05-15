#if defined _stock_officerspy_mathlib_included
	#endinput
#endif
#define _stock_officerspy_mathlib_included

stock float ClampFloat(const float val, const float minVal, const float maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}

stock int ClampInt(const int val, const int minVal, const int maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}

stock float anglemod(float a)
{
	a = (360.0 / 65536) * (RoundToNearest(a * (65536.0 / 360.0)) & 65535);
	return a;
}

stock float RemapVal(float val, float A, float B, float C, float D)
{
	if (A == B)
		return val >= B ? D : C;
	
	return C + (D - C) * (val - A) / (B - A);
}

stock float RemapValClamped(float val, float A, float B, float C, float D)
{
	if (A == B)
		return val >= B ? D : C;
	
	float cVal = (val - A) / (B - A);
	cVal = ClampFloat(cVal, 0.0, 1.0);
	
	return C + (D - C) * cVal;
}

stock float SimpleSpline(float value)
{
	float valueSquared = value * value;
	return (3 * valueSquared - 2 * valueSquared * value);
}

stock float SimpleSplineRemapVal(float val, float A, float B, float C, float D)
{
	if ( A == B )
		return val >= B ? D : C;
	
	float cVal = (val - A) / (B - A);
	return C + (D - C) * SimpleSpline( cVal );
}

stock float SimpleSplineRemapValClamped(float val, float A, float B, float C, float D)
{
	if ( A == B )
		return val >= B ? D : C;
	
	float cVal = (val - A) / (B - A);
	cVal = ClampFloat(cVal, 0.0, 1.0);
	
	return C + (D - C) * SimpleSpline( cVal );
}