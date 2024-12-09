void CWretch::OnChangeActivity( Activity NewActivity )
{
	if ( NewActivity == ACT_WRETCH_FRENZY )
	{
		// Scream!!!!
		EmitSound( "NPC_Wretch.Frenzy" );
		SetPlaybackRate( random->RandomFloat( .9, 1.1 ) );	
	}

	if( NewActivity == ACT_JUMP )
	{
		BeginNavJump();
	}
	else if( GetActivity() == ACT_JUMP )
	{
		EndNavJump();
	}

	if ( NewActivity == ACT_LAND )
	{
		m_flNextAttack = gpGlobals->curtime + 1.0;
	}

	if ( NewActivity == ACT_GLIDE )
	{
		// Started a jump.
		BeginNavJump();
	}
	else if ( GetActivity() == ACT_GLIDE )
	{
		// Landed a jump
		EndNavJump();

		if ( m_pMoanSound )
			ENVELOPE_CONTROLLER.SoundChangePitch( m_pMoanSound, WRETCH_MIN_PITCH, 0.3 );
	}

	if ( NewActivity == ACT_CLIMB_UP )
	{
		// Started a climb!
		if ( m_pMoanSound )
			ENVELOPE_CONTROLLER.SoundChangeVolume( m_pMoanSound, 0.0, 0.2 );

		SetTouch( &CWretch::ClimbTouch );
	}
	else if ( GetActivity() == ACT_CLIMB_DISMOUNT || ( GetActivity() == ACT_CLIMB_UP && NewActivity != ACT_CLIMB_DISMOUNT ) )
	{
		// Ended a climb
		if ( m_pMoanSound )
			ENVELOPE_CONTROLLER.SoundChangeVolume( m_pMoanSound, 1.0, 0.2 );

		SetTouch( NULL );
	}

	BaseClass::OnChangeActivity( NewActivity );
}