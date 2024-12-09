void Host_ShutdownServer( void )
{
	if ( !sv.IsActive() )
		return;

	if ( IGameEvent *event = g_GameEventManager.CreateEvent( "server_pre_shutdown" ) )
	{
		event->SetString( "reason", "restart" );
		g_GameEventManager.FireEvent( event );
	}

	// clear structures
#if !defined( DEDICATED )
	g_pShadowMgr->LevelShutdown();
#endif
	StaticPropMgr()->LevelShutdown();

	Host_FreeStateAndWorld( true );
	sv.Shutdown();// sv.Shutdown() references some heap memory, so run it before Host_FreeToLowMark()
	Host_FreeToLowMark( true ); 

#if defined( REPLAY_ENABLED )
	if ( g_pServerReplayHistoryManager )
	{
		g_pServerReplayHistoryManager->Shutdown();
		g_pServerReplayHistoryManager = NULL;
	}
#endif

	if ( IGameEvent *event = g_GameEventManager.CreateEvent( "server_shutdown" ) )
	{
		event->SetString( "reason", "restart" );
		g_GameEventManager.FireEvent( event );
	}

	g_Log.Close();
}