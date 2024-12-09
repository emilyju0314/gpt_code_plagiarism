void CWretch::StopLoopingSounds( void )
{
	if ( m_pMoanSound )
	{
		ENVELOPE_CONTROLLER.SoundDestroy( m_pMoanSound );
		m_pMoanSound = NULL;
	}

	if ( m_pLayer2 )
	{
		ENVELOPE_CONTROLLER.SoundDestroy( m_pLayer2 );
		m_pLayer2 = NULL;
	}

	BaseClass::StopLoopingSounds();
}