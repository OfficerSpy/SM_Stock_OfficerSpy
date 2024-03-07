#if defined _stock_officerspy_vector_included
	#endinput
#endif
#define _stock_officerspy_vector_included

stock bool PointWithinViewAngle(const float vecSrcPosition[3], const float vecTargetPosition[3], const float vecLookDirection[3], float flCosHalfFOV)
{
	float vecDelta[3]; SubtractVectors(vecTargetPosition, vecSrcPosition, vecDelta);
	float cosDiff = GetVectorDotProduct(vecLookDirection, vecDelta);
	
	if (cosDiff < 0)
		return false;
	
	float flLen2 = GetVectorLength(vecDelta, true);
	
	return cosDiff * cosDiff > flLen2 * flCosHalfFOV * flCosHalfFOV;
}

stock float Vector_NormalizeInPlace(float vec[3])
{
	return NormalizeVector(vec, vec);
}

//All this does is return a normalized vector which is kind of redundant 
//It would be better off just using NormalizeVector directly
stock float[] Vector_Normalized(float vec[3])
{
	float norm[3]; norm = vec;
	NormalizeVector(norm, norm);
	return norm;
}

stock bool Vector_IsLengthGreaterThan(float vec[3], float val)
{
	return GetVectorLength(vec, true) > val * val;
}

stock bool Vector_IsLengthLessThan(float vec[3], float val)
{
	return GetVectorLength(vec, true) < val * val;
}