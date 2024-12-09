void Host_UpdateSounds( void )
{
	SNPROF("Host_UpdateSounds");

#if !defined( DEDICATED )
	MDLCACHE_COARSE_LOCK_(g_pMDLCache);
	// update audio
	if ( GetBaseLocalClient().IsActive() )
	{
		S_Update( &s_AudioState );	
	}
	else
	{
		S_Update( NULL );
	}
#endif
}