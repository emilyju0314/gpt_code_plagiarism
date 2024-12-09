bool CWeaponBinoculars::Holster( CBaseCombatWeapon *pSwitchingTo )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if ( pPlayer != NULL )
	{
		if ( m_nZoomLevel != 0 )
		{
			pPlayer->ShowViewModel(true);
			pPlayer->SetFOV( this, 0, 0.2f );
			m_nZoomLevel = 0;
		}
	}

	CSoundEnvelopeController &controller = CSoundEnvelopeController::GetController();

	controller.SoundDestroy( m_pSoundStatic );
	controller.SoundDestroy( m_pSoundSignal );
	m_pSoundStatic = NULL;
	m_pSoundSignal = NULL;

	return true;
}