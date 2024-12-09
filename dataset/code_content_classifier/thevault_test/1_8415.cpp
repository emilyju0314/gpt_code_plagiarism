void CWretch::SoundInit( void )
{
	if( !m_pMoanSound )
	{
		// !!!HACKHACK - kickstart the moan sound. (sjb)
		MoanSound( envWretchMoanVolume, ARRAYSIZE( envWretchMoanVolume ) );

		// Clear the commands that the base class gave the moaning sound channel.
		ENVELOPE_CONTROLLER.CommandClear( m_pMoanSound );
	}

	CPASAttenuationFilter filter( this );

	if( !m_pLayer2 )
	{
		// Set up layer2
		m_pLayer2 = ENVELOPE_CONTROLLER.SoundCreate( filter, entindex(), CHAN_VOICE, "NPC_Wretch.Gurgle", ATTN_NORM );

		// Start silent.
		ENVELOPE_CONTROLLER.Play( m_pLayer2, 0.0, 100 );
	}

	SetIdleSoundState();
}