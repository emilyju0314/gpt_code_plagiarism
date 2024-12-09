void CWretch::BeginNavJump( void )
{
	m_fIsNavJumping = true;
	m_fHitApex = false;

	ENVELOPE_CONTROLLER.SoundPlayEnvelope( m_pLayer2, SOUNDCTRL_CHANGE_VOLUME, envWretchVolumeJump, ARRAYSIZE(envWretchVolumeJump) );
}