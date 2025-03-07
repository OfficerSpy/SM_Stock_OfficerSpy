#if defined _stock_officerspy_effectdispatchdata_included
	#endinput
#endif
#define _stock_officerspy_effectdispatchdata_included

#include <stocklib_officerspy/shared/particle_parse>

#define EFFECTDATA_NO_RECORD	0x80000000

#define MAX_EFFECT_FLAG_BITS	8

#define CUSTOM_COLOR_CP1	9
#define CUSTOM_COLOR_CP2	10

//In code this is actually a class, but we will pass this as a structure here since this isn't going to be wrapped around any specific object
enum struct CEffectData
{
	float m_vOrigin[3];
	float m_vStart[3];
	float m_vNormal[3];
	float m_vAngles[3];
	int m_fFlags;
	int m_nEntIndex;
	float m_flScale;
	float m_flMagnitude;
	float m_flRadius;
	int m_nAttachmentIndex;
	int m_nSurfaceProp;
	int m_nMaterial;
	int m_nDamageType;
	int m_nHitBox;
	int m_nColor;
	bool m_bCustomColors;
	te_tf_particle_effects_colors_t	m_CustomColors;
	bool m_bControlPoint1;
	te_tf_particle_effects_control_point_t	m_ControlPoint1;
	int m_iEffectName;
}