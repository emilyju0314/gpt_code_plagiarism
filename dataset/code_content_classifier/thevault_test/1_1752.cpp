void CWeaponBinoculars::ItemPostFrame( void )
{
	// This should really be PREFRAME.
	if( gpGlobals->curtime >= m_NextCacheTime && m_nZoomLevel != 0 )
	{
		CacheSoundSources();
	}

	CBaseEntity *pSound;

	pSound = LocateBestSound();
	
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if (pPlayer == NULL)
	{
		return;
	}

	float flStaticVolume;
	float flSignalVolume;
	float flDot;

	if( m_nZoomLevel != 0 )
	{
		Vector vecToSound;
		Vector vecFacing;

		pPlayer->EyeVectors( &vecFacing );

		if( pSound )
		{
			// Trying to tune a sound in.
			vecToSound = pSound->GetLocalOrigin() - pPlayer->GetLocalOrigin();
			VectorNormalize( vecToSound );

			flDot = DotProduct( vecToSound, vecFacing );

			/*
			// FIXME: Disabled this, the code for doing this must exist on the client
			if( flDot > 0.95 )
			{
				engine->EnableHOrigin( true );
				engine->SetHOrigin( pSound->GetLocalOrigin() );
			}
			else
			{
				engine->EnableHOrigin( false );
			}
			*/

			// static volume gets louder the farther you are from sound
			// signal volume gets louder as you near sound.
			flStaticVolume = ( 1.0 - flDot ) * 2.0;

			// signal volume gets louder as you near, quieter as you get VERY near.
			if( flDot < 0.90 || flDot > 0.9995 )
			{
				flSignalVolume = 0.1;
			}
			else
			{
				//flSignalVolume = (flDot - 0.6) * 2;
				flSignalVolume = flDot;
			}
		}
		else
		{
			// No sound. Static.
			flSignalVolume = 0.0;
			flStaticVolume = 1.0;
			
			//engine->EnableHOrigin( false );
		}

#if 0
		Msg( "Dot:%f - Static:%f - Signal:%f\n", flDot, flStaticVolume, flSignalVolume );
#endif
	}
	else
	{
		flStaticVolume = flSignalVolume = 0.0;
		//engine->EnableHOrigin( false );
	}

	CSoundEnvelopeController &controller = CSoundEnvelopeController::GetController();
	controller.SoundChangeVolume( m_pSoundStatic, flStaticVolume, 0.1 );
	controller.SoundChangeVolume( m_pSoundSignal, flSignalVolume, 0.1 );

	if ( pPlayer->m_nButtons & IN_ATTACK )
	{
		if ( m_fNextZoom <= gpGlobals->curtime )
		{
			Zoom( Zoom_In );
			pPlayer->m_nButtons &= ~IN_ATTACK;
		}
	}
	else if ( pPlayer->m_nButtons & IN_ATTACK2 )
	{
		if ( m_fNextZoom <= gpGlobals->curtime )
		{
			Zoom( Zoom_Out );
			pPlayer->m_nButtons &= ~IN_ATTACK2;
		}
	}

	//
	// No buttons down.
	//
	if (!(( pPlayer->m_nButtons & IN_ATTACK ) || ( pPlayer->m_nButtons & IN_ATTACK2 )))
	{
		WeaponIdle();
		return;
	}
}