#if defined _stock_officerspy_vector_included
	#endinput
#endif
#define _stock_officerspy_vector_included

//All this does is return a normalized vector which is kind of redundant 
//It would be better off just using NormalizeVector directly
stock float[] Vector_Normalized(float vector[3])
{
	float norm[3]; norm = vector;
	NormalizeVector(norm, norm);
	return norm;
}

stock bool Vector_IsLengthGreaterThan(float vector[3], float val)
{
	return GetVectorLength(vector, true) > val * val;
}

stock bool Vector_IsLengthLessThan(float vector[3], float val)
{
	return GetVectorLength(vector, true) < val * val;
}