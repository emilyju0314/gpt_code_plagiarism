int CWretch::MeleeAttack1Conditions( float flDot, float flDist )
{
	if ( !GetEnemy() )
	{
		return COND_NONE;
	}

	if( !(GetFlags() & FL_ONGROUND) )
	{
		// Have to be on the ground!
		return COND_NONE;
	}

	if( gpGlobals->curtime < m_flNextMeleeAttack )
	{
		return COND_NONE;
	}
	
	int baseResult = BaseClass::MeleeAttack1Conditions( flDot, flDist );

	// @TODO (toml 07-21-04): follow up with Steve to find out why fz was explicitly not using these conditions
	if ( baseResult == COND_TOO_FAR_TO_ATTACK || baseResult == COND_NOT_FACING_ATTACK )
	{
		return COND_NONE;
	}

	return baseResult;
}