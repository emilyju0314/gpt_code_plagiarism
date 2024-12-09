void CWretch::SetIdleSoundState( void )
{
	// Main looping sound
	if ( m_pMoanSound )
	{
		ENVELOPE_CONTROLLER.SoundChangePitch( m_pMoanSound, WRETCH_IDLE_PITCH, 1.0 );
		ENVELOPE_CONTROLLER.SoundChangeVolume( m_pMoanSound, 0.75, 1.0 );
	}

	// Second Layer
	if ( m_pLayer2 )
	{
		ENVELOPE_CONTROLLER.SoundChangePitch( m_pLayer2, 100, 1.0 );
		ENVELOPE_CONTROLLER.SoundChangeVolume( m_pLayer2, 0.0, 1.0 );
	}
}