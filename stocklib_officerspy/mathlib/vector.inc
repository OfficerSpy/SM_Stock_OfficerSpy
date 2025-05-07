#if defined _stock_officerspy_vector_included
	#endinput
#endif
#define _stock_officerspy_vector_included

stock bool Vector_IsZero(const float vec[3], float tolerance = 0.01)
{
	return vec[0] > -tolerance && vec[0] < tolerance && vec[1] > -tolerance && vec[1] < tolerance && vec[2] > -tolerance && vec[2] < tolerance;
}

stock float Vector_NormalizeInPlace(float vec[3])
{
	return NormalizeVector(vec, vec);
}

//Returns a normalized version of the vector
stock float[] Vector_Normalized(const float vec[3])
{
	float norm[3]; norm = vec;
	NormalizeVector(norm, norm);
	return norm;
}

stock bool Vector_IsLengthGreaterThan(const float vec[3], float val)
{
	return GetVectorLength(vec, true) > val * val;
}

stock bool Vector_IsLengthLessThan(const float vec[3], float val)
{
	return GetVectorLength(vec, true) < val * val;
}

stock float Vector_Length2D(const float vec[3])
{
	return (vec[0] * vec[0] + vec[1] * vec[1]);
}

stock float Vector_Length2DSqr(const float vec[3])
{
	return (vec[0] * vec[0] + vec[1] * vec[1]);
}

stock bool PointWithinViewAngle(const float vecSrcPosition[3], const float vecTargetPosition[3], const float vecLookDirection[3], float flCosHalfFOV)
{
	float vecDelta[3]; SubtractVectors(vecTargetPosition, vecSrcPosition, vecDelta);
	float cosDiff = GetVectorDotProduct(vecLookDirection, vecDelta);
	
	if (cosDiff < 0)
		return false;
	
	float flLen2 = GetVectorLength(vecDelta, true);
	
	return cosDiff * cosDiff > flLen2 * flCosHalfFOV * flCosHalfFOV;
}