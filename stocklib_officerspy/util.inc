/* Though most of these functions can be easily recreated in SP, there may be some that were derived from other plugins
ScreenFade and ScreenShake are mostly taken from Sentry Buster NPC */
#define UTIL_FFADE_IN			0x0001
#define UTIL_FFADE_OUT			0x0002
#define UTIL_FFADE_MODULATE		0x0004
#define UTIL_FFADE_STAYOUT		0x0008
#define UTIL_FFADE_PURGE			0x0010
#define UTIL_SCREENFADE_FRACBITS	9

enum //ShakeCommand_t
{
	UTIL_SHAKE_START = 0,
	UTIL_SHAKE_STOP,
	UTIL_SHAKE_AMPLITUDE,
	UTIL_SHAKE_FREQUENCY,
	UTIL_SHAKE_START_RUMBLEONLY,
	UTIL_SHAKE_START_NORUMBLE,
};

stock int FixedUnsigned16(float value, int scale)
{
	int output;
	
	output = RoundToFloor(value * float(scale));
	
	if (output < 0)
		output = 0;
	
	if (output > 0xFFFF)
		output = 0xFFFF;
	
	return output;
}

stock float ComputeShakeAmplitude(const float center[3], const float shake[3], float amplitude, float radius)
{
	if (radius <= 0)
		return amplitude;
	
	float localAmplitude = -1.0;
	float delta[3];
	SubtractVectors(center, shake, delta);
	float distance = GetVectorLength(delta);
	
	if (distance <= radius)
	{
		float perc = 1.0 - (distance / radius);
		localAmplitude = amplitude * perc;
	}
	
	return localAmplitude;
}

stock void TransmitShakeEvent(int player, float localAmplitude, float frequency, float duration, int eCommand)
{
	if ((localAmplitude > 0.0) || (eCommand == UTIL_SHAKE_STOP))
	{
		if (eCommand == UTIL_SHAKE_STOP)
			localAmplitude = 0.0;
		
		BfWrite msg = UserMessageToBfWrite(StartMessageOne("Shake", player, USERMSG_RELIABLE));
		if (msg != null)
		{
			msg.WriteByte(eCommand);
			msg.WriteFloat(localAmplitude);
			msg.WriteFloat(frequency);
			msg.WriteFloat(duration);
			
			EndMessage();
		}
	}
}

const float MAX_SHAKE_AMPLITUDE = 16.0;
stock void UTIL_ScreenShake(const float center[3], float amplitude, float frequency, float duration, float radius, int eCommand, bool bAirShake)
{
	float localAmplitude;
	
	if (amplitude > MAX_SHAKE_AMPLITUDE)
		amplitude = MAX_SHAKE_AMPLITUDE;
	
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsClientInGame(i) || (!bAirShake && (eCommand == UTIL_SHAKE_START) && !(GetEntityFlags(i) & FL_ONGROUND)))
			continue;
		
		float playerCenter[3];
		playerCenter = WorldSpaceCenter(i);
		
		localAmplitude = ComputeShakeAmplitude(center, playerCenter, amplitude, radius);
		
		if (localAmplitude < 0)
			continue;
		
		TransmitShakeEvent(i, localAmplitude, frequency, duration, eCommand);
	}
}

stock void UTIL_ScreenFade(int player, int color[4], float fadeTime, float fadeHold, int flags)
{
	//Combines UTIL_ScreenFadeBuild and UTIL_ScreenFadeWrite
	//The fade is normally a ScreenFade_t objecet just passed by reference
	BfWrite bf = UserMessageToBfWrite(StartMessageOne("Fade", player, USERMSG_RELIABLE));
	if (bf != null)
	{
		bf.WriteShort(FixedUnsigned16(fadeTime, 1 << UTIL_SCREENFADE_FRACBITS));
		bf.WriteShort(FixedUnsigned16(fadeHold, 1 << UTIL_SCREENFADE_FRACBITS));
		bf.WriteShort(flags);
		bf.WriteByte(color[0]);
		bf.WriteByte(color[1]);
		bf.WriteByte(color[2]);
		bf.WriteByte(color[3]);
		
		EndMessage();
	}
}