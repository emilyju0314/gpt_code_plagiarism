void CWeaponBinoculars::Zoom( ZoomMode_t eMode )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if ( !pPlayer )
	{
		return;
	}

	switch ( eMode )
	{
		//
		// Stop zooming with the binoculars.
		//
		case Zoom_Exit:
		{
			if ( m_nZoomLevel != 0 )
			{
				pPlayer->ShowViewModel(true);
				WeaponSound( SPECIAL2 );
				pPlayer->SetFOV( this, 0, 0.1f );
				m_nZoomLevel = 0;
			}
			break;
		}

		//
		// Zoom in.
		//
		case Zoom_In:
		{
			if (( m_nZoomLevel + 1 ) < ( sizeof( g_nZoomFOV ) / sizeof( g_nZoomFOV[0] )))
			{
				m_nZoomLevel++;
				WeaponSound( SPECIAL1 );
				pPlayer->SetFOV( this, g_nZoomFOV[m_nZoomLevel], 0.1f );

				if (g_nZoomFOV[m_nZoomLevel] != 0)
				{
					pPlayer->ShowViewModel(false);
				}
			}
			else
			{
				// Can't zoom in any further; play a special sound.
				WeaponSound( RELOAD );
			}

			m_fNextZoom = gpGlobals->curtime + BINOCULARS_ZOOM_RATE;
			break;
		}

		//
		// Zoom out.
		//
		case Zoom_Out:
		{
			if ( m_nZoomLevel > 0 )
			{
				m_nZoomLevel--;
				WeaponSound( SPECIAL2 );
				pPlayer->SetFOV( this, g_nZoomFOV[m_nZoomLevel], 0.2f );

				if ( g_nZoomFOV[m_nZoomLevel] == 0 )
				{
					pPlayer->ShowViewModel(true);
				}
			}

			m_fNextZoom = gpGlobals->curtime + BINOCULARS_ZOOM_RATE;
			break;
		}

		default:
		{
			break;
		}
	}
}