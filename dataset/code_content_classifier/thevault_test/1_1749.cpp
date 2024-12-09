void CWeaponBinoculars::CacheSoundSources( void )
{
	EHANDLE			*pSources = m_hSources;
	CBaseEntity		*pEnt;
	
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	Assert( pPlayer != NULL );
	if (pPlayer == NULL)
	{
		return;
	}

	pEnt = UTIL_EntitiesInPVS( pPlayer, NULL );
	int count = 0;
	
	while( pEnt )
	{
		// INSOLENCE HACK: For now consider only ambient_generic's as sound sources
		// This is necessary because Source 2013 doesnt have "IsSoundSource()"
		if( !strcmp( pEnt->GetClassname(), "ambient_generic" ) )
		{
			*pSources = pEnt;
			pSources++;
			count++;
		}

		if( count == ( BINOCULARS_MAXSOURCES - 1 ) )
		{
			Msg( "*** BINOCULARS: TOO MANY SOUND SOURCES!\n" );
			break;
		}

		pEnt = UTIL_EntitiesInPVS( pPlayer, pEnt );
	}

	pSources = NULL;
	m_NextCacheTime = gpGlobals->curtime + BINOCULARS_CACHEFREQ;
}