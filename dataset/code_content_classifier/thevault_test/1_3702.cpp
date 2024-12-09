void *ShaderFactory( const char *pName, int *pReturnCode )
{
	if (pReturnCode)
	{
		*pReturnCode = IFACE_OK;
	}
	
	if ( !Q_stricmp( pName, FILESYSTEM_INTERFACE_VERSION ))
		return g_pFullFileSystem;

	if ( !Q_stricmp( pName, QUEUEDLOADER_INTERFACE_VERSION ))
		return g_pQueuedLoader;

	if ( !Q_stricmp( pName, VJOBS_INTERFACE_VERSION ) )
		return g_pVJobs;

#if defined( _X360 )
	if ( !Q_stricmp( pName, XBOXINSTALLER_INTERFACE_VERSION ))
		return g_pXboxInstaller;
#endif

	if ( !Q_stricmp( pName, SHADER_UTIL_INTERFACE_VERSION ))
		return g_pShaderUtil;

#if defined( USE_SDL )
    if ( !Q_stricmp( pName, "SDLMgrInterface001" /*SDLMGR_INTERFACE_VERSION*/ ))
		return g_pLauncherMgr;
#endif

#if PLATFORM_OSX
	if ( !Q_stricmp( pName, "CocoaMgrInterface006" /*COCOAMGR_INTERFACE_VERSION*/ ))
		return g_pLauncherMgr;
#endif

	void * pInterface = g_MaterialSystem.QueryInterface( pName );
	if ( pInterface )
		return pInterface;

	if ( pReturnCode )
	{
		*pReturnCode = IFACE_FAILED;
	}
	return NULL;	
}