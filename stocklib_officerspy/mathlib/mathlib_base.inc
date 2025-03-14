#if defined _stock_officerspy_mathlib_base_included
	#endinput
#endif
#define _stock_officerspy_mathlib_base_included

#include <stocklib_officerspy/mathlib/mathlib>

stock float Approach(float target, float value, float speed)
{
	float delta = target - value;

	if (delta > speed)
		value += speed;
	else if (delta < -speed)
		value -= speed;
	else 
		value = target;

	return value;
}

stock float ApproachAngle(float target, float value, float speed)
{
	target = anglemod(target);
	value = anglemod(value);
	
	float delta = target - value;

	if (speed < 0)
		speed = -speed;

	if (delta < -180)
		delta += 360;
	else if (delta > 180)
		delta -= 360;

	if (delta > speed)
		value += speed;
	else if (delta < -speed)
		value -= speed;
	else 
		value = target;

	return value;
}