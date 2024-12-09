LauncherMain_t GetLaunchEntryPoint( char *pNewCommandLine )
{
	HMODULE		hModule;
	char		*pCmdLine;

	// determine source of our invocation, internal or external
	// a valid launch payload will have an embedded command line
	// command line could be from internal restart in dev or retail mode
	CXboxLaunch xboxLaunch;
	int payloadSize;
	unsigned int launchID;
	char *pPayload;
	bool bInternalRestart = xboxLaunch.GetLaunchData( &launchID, (void**)&pPayload, &payloadSize );
	if ( !bInternalRestart || !payloadSize || launchID != VALVE_LAUNCH_ID )
	{
		// could be first time, get command line from system
		pCmdLine = GetCommandLine();
		if ( !stricmp( pCmdLine, "\"default.xex\"" ) )
		{
			// matches retail xex and no arguments, mut be first time retail launch
			pCmdLine = "default.xex";
#if defined( _MEMTEST )
			pCmdLine = "default.xex +mat_picmip 2";
#endif
		}
	}
	else
	{
		// get embedded command line from payload
		pCmdLine = pPayload;
	}

	int launchFlags = 0;
	if ( launchID == VALVE_LAUNCH_ID )
	{
		launchFlags = xboxLaunch.GetLaunchFlags();
	}
#if !defined( _CERT )
	if ( launchFlags & LF_ISDEBUGGING )
	{
		while ( !DmIsDebuggerPresent() )
		{
		}

		Sleep( 1000 );
		Spew( "Resuming debug session.\n" );
	}
#endif

	// unforunately, the xbox erases its internal store upon first fetch
	// must re-establish it so the payload that contains other data (past command line) can be accessed by the game
	// the launch data will be owned by tier0 and supplied to game
	if ( launchID == VALVE_LAUNCH_ID )
	{
		xboxLaunch.SetLaunchData( pPayload, payloadSize, launchFlags );
	}
#if defined( _DEMO )
	else if ( pPayload && payloadSize )
	{
		// not our data
		// restore the launch data as expected
		xboxLaunch.SetLaunchData( pPayload, payloadSize, LF_UNKNOWNDATA );
	}
#endif

#if defined( _DEMO )
	// the demo version cannot trust launch environment
	// Kiosk or Magazines launch in unpredictable ways with unknown paths
	// MUST slam the command line!!!
#if !defined( _CERT )
	// take the command line as specified by the debugger
	if ( !DmIsDebuggerPresent() )
	{
		pCmdLine = "default.xex";
	}
#else
	pCmdLine = "default.xex";
#endif
#endif

	// The 360 has no paths and therefore the xex must reside in the same location as the dlls.
	// Only the xex must reside locally, on the box, but the dlls can be mounted from the remote share.
	// Resolve all known implicitly loaded dlls to be explicitly loaded now to allow their remote location.
	const char *pImplicitDLLs[] =
	{
		"tier0_360.dll",
		"vstdlib_360.dll",
		"vxbdm_360.dll",
		"launcher_360.dll",
	};

	// Corresponds to pImplicitDLLs. A dll load failure is only an error if that dll is tagged as required.
	const bool bDllRequired[] = 
	{
		true,	// tier0
		true,	// vstdlib
		false,	// vxbdm
		true,	// ???
	};

	char gameName[32];
	if ( !ParseCommandLineArg( pCmdLine, "-game", gameName, sizeof( gameName ) ) )
	{
#if defined( VPCGAME_STRING )
		strcpy( gameName, VPCGAME_STRING );
#endif
	}
	else
	{
		// sanitize a possible absolute game path back to expected game name
		char *pSlash = strrchr( gameName, '\\' );
		if ( pSlash )
		{
			memcpy( gameName, pSlash+1, strlen( pSlash+1 )+1 );
		}
	}

	// resolve which application gets launched
	// default is to application
	pImplicitDLLs[ARRAYSIZE( pImplicitDLLs )-1] = "launcher_360.dll";

	// the base path is the where the game is predominantly anchored
	// game runs from dvd only
	// this can only be the d: by definition on the xbox
	const char *pBasePath = "d:";

	// load all the dlls specified
	char dllPath[MAX_PATH];
	for ( int i=0; i<ARRAYSIZE( pImplicitDLLs ); i++ )
	{
		hModule = NULL;
		sprintf( dllPath, "%s\\bin\\%s", pBasePath, pImplicitDLLs[i] );
		hModule = LoadLibrary( dllPath );
		if ( !hModule && bDllRequired[i] )
		{
			Spew( "FATAL: Failed to load dll: '%s'\n", dllPath );
			return NULL;
		}
	}

	char cleanCommandLine[1024];
	char tempCommandLine[1024];
	StripCommandLineArg( pCmdLine, tempCommandLine, "-basedir" );
	StripCommandLineArg( tempCommandLine, cleanCommandLine, "-game" );

	// HACK: For ratings build, unlock everything. Remove this for later testing
	const char *pAdditionalArgs = "";
#if defined( RATINGSBUILD )
	pAdditionalArgs = "-dev -unlockchapters mp_mark_all_maps_complete";
#endif

	// set the alternate command line
	sprintf( pNewCommandLine, "%s -basedir %s -game %s\\%s %s", cleanCommandLine, pBasePath, pBasePath, gameName, pAdditionalArgs );

	// the 'main' export is guaranteed to be at ordinal 1
	// the library is already loaded, this just causes a lookup that will resolve against the shortname
	const char *pLaunchDllName = pImplicitDLLs[ARRAYSIZE( pImplicitDLLs )-1];
	hModule = LoadLibrary( pLaunchDllName );
	LauncherMain_t main = (LauncherMain_t)GetProcAddress( hModule, (LPSTR)1 );
	if ( !main )
	{
		Spew( "FATAL: 'LauncherMain' entry point not found in %s\n", pLaunchDllName );
		return NULL;
	}

	return main;
}