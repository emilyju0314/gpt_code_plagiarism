void CWretch::PainSound( const CTakeDamageInfo &info )
{
	if ( m_pLayer2 )
		ENVELOPE_CONTROLLER.SoundPlayEnvelope( m_pLayer2, SOUNDCTRL_CHANGE_VOLUME, envWretchVolumePain, ARRAYSIZE(envWretchVolumePain) );
	if ( m_pMoanSound )
		ENVELOPE_CONTROLLER.SoundPlayEnvelope( m_pMoanSound, SOUNDCTRL_CHANGE_VOLUME, envWretchInverseVolumePain, ARRAYSIZE(envWretchInverseVolumePain) );
}