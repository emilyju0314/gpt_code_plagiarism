void ClientModeShared::StartMessageMode( int iMessageModeType )
{
	// Can only show chat UI in multiplayer!!!
	if ( gpGlobals->maxClients == 1 )
	{
		return;
	}
#if defined( INCLUDE_SCALEFORM )
	SFHudChat* pChat = GET_HUDELEMENT( SFHudChat );
	if ( pChat )
	{
		pChat->StartMessageMode( iMessageModeType );
	}
#elif defined( INCLUDE_ROCKETUI )
	RkHudChat* pChat = GET_HUDELEMENT( RkHudChat );
	if( pChat )
	    pChat->StartMessageMode( iMessageModeType );
#endif
}