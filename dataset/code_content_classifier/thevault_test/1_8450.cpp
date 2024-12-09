void CSTrooper :: Precache()
{
	PRECACHE_MODEL("models/strooper.mdl");
	m_iVgib = PRECACHE_MODEL("models/strooper_gibs.mdl");

	PRECACHE_SOUND( "shocktrooper/shock_trooper_attack.wav" );
	
	PRECACHE_SOUND( "shocktrooper/shock_trooper_die1.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_die2.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_die3.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_die4.wav" );

	PRECACHE_SOUND( "shocktrooper/shock_trooper_pain1.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_pain2.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_pain3.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_pain4.wav" );
	PRECACHE_SOUND( "shocktrooper/shock_trooper_pain5.wav" );

	PRECACHE_SOUND( "weapons/sbarrel1.wav" );

	PRECACHE_SOUND("zombie/claw_miss2.wav");// because we use the basemonster SWIPE animation event

	UTIL_PrecacheOther( "shock" );
	UTIL_PrecacheOther( "monster_shockroach" );
	// get voice pitch
	if (RANDOM_LONG(0,1))
		m_voicePitch = 109 + RANDOM_LONG(0,7);
	else
		m_voicePitch = 100;

}