#include <stocklib_officerspy/player>
#include <stocklib_officerspy/vscript>

stock void TF2_PushAllPlayersAway(const float vFromThisPoint[3], float flRange, float flForce, TFTeam nTeam)
{
	ArrayList adtPlayer;
	CollectPlayers(adtPlayer, view_as<int>(nTeam), true);
	
	for (int i = 0; i < adtPlayer.Length; i++)
	{
		int player = adtPlayer.Get(i);
		
		float eyePosition[3];	GetClientEyePosition(player, eyePosition);
		
		float toPlayer[3];	SubtractVectors(eyePosition, vFromThisPoint, toPlayer);
		
		if (GetVectorLength(toPlayer, true) < flRange * flRange)
		{
			toPlayer[2] = 0.0;
			NormalizeVector(toPlayer, toPlayer);
			toPlayer[2] = 1.0;
			
			float vPush[3];	vPush = toPlayer;
			ScaleVector(vPush, flForce);
			
			VS_ApplyAbsVelocityImpulse(player, vPush);
		}
	}
}