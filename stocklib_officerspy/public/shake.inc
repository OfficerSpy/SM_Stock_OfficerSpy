#if defined _stock_officerspy_shake_included
	#endinput
#endif
#define _stock_officerspy_shake_included

#if !defined ShakeCommand_t_ENABLED
enum ShakeCommand_t
{
	SHAKE_START = 0,
	SHAKE_STOP,
	SHAKE_AMPLITUDE,
	SHAKE_FREQUENCY,
	SHAKE_START_RUMBLEONLY,
	SHAKE_START_NORUMBLE
};
#define ShakeCommand_t_ENABLED
#endif

#if !defined FFADE_IN
#define FFADE_IN	0x0001
#define FFADE_OUT	0x0002
#define FFADE_MODULATE	0x0004
#define FFADE_STAYOUT	0x0008
#define FFADE_PURGE	0x0010
#endif

#define SCREENFADE_FRACBITS	9