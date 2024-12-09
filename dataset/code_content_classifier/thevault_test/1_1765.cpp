void CWeaponSniperRifle::Zoom( void )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if (!pPlayer)
	{
		return;
	}

	color32 lightRed = { 255, 50, 50, 32 };

	if (m_nZoomLevel >= sizeof(g_nZoomFOV) / sizeof(g_nZoomFOV[0]))
	{
		pPlayer->ShowViewModel(true);

		// Zoom out to the default zoom level
		WeaponSound(SPECIAL2);
		pPlayer->SetFOV( this, 0, 0.2f );
		m_nZoomLevel = 0;

		UTIL_ScreenFade( pPlayer, lightRed, 0.2f, 0, (FFADE_IN|FFADE_PURGE) );
	}
	else
	{
		pPlayer->ShowViewModel(false);

		WeaponSound(SPECIAL1);
		pPlayer->SetFOV( this, g_nZoomFOV[m_nZoomLevel], 0.1f );

		if (m_nZoomLevel == 0)
		{
			UTIL_ScreenFade( pPlayer, lightRed, 0.2f, 0, (FFADE_OUT|FFADE_PURGE|FFADE_STAYOUT) );	
		}

		m_nZoomLevel++;
	}

	m_fNextZoom = gpGlobals->curtime + SNIPER_ZOOM_RATE;
}