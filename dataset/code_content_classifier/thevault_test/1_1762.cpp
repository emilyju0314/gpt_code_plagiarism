bool CWeaponSniperRifle::Holster( CBaseCombatWeapon *pSwitchingTo )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if (pPlayer != NULL)
	{
		if ( m_nZoomLevel != 0 )
		{
			color32 lightRed = { 255, 50, 50, 32 };

			pPlayer->ShowViewModel(true);
			pPlayer->SetFOV( this, 0, 0.2f );
			m_nZoomLevel = 0;

			UTIL_ScreenFade( pPlayer, lightRed, 0.2f, 0, (FFADE_IN|FFADE_PURGE) );
		}
	}

	return BaseClass::Holster(pSwitchingTo);
}