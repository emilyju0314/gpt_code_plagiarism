bool CWeaponSniperRifle::Reload( void )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if (!pPlayer)
	{
		return false;
	}

	bool fRet;

	if (m_nZoomLevel > 0)
	{
		color32 lightRed = { 255, 50, 50, 32 };

		pPlayer->ShowViewModel(true);

		// Zoom out to the default zoom level
		WeaponSound(SPECIAL2);
		pPlayer->SetFOV( this, 0, 0.2f );

		UTIL_ScreenFade( pPlayer, lightRed, 0.2f, 0, (FFADE_IN|FFADE_PURGE) );
	}

	fRet = BaseClass::Reload();
	if ( fRet )
	{
		WeaponSound(RELOAD);
	}

	return fRet;
}