#define TEAM_ANY	-2
#define	TEAM_INVALID	-1
#define TEAM_UNASSIGNED	0
#define TEAM_SPECTATOR	1
#define LAST_SHARED_TEAM	TEAM_SPECTATOR

#define FIRST_GAME_TEAM	LAST_SHARED_TEAM + 1

#define MAX_TEAMS	32
#define MAX_TEAM_NAME_LENGTH	32

//Vision filters
//These exist in the source-sdk-2013, but they seem to be TF2 specific
#define TF_VISION_FILTER_NONE			0
#define TF_VISION_FILTER_PYRO			(1<<0)
#define TF_VISION_FILTER_HALLOWEEN		(1<<1)
#define TF_VISION_FILTER_ROME			(1<<2)