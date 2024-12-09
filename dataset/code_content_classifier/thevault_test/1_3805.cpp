void TryToLoadSteamOverlayDLL()
{
#if defined( WIN32 ) && !defined( _X360 )
	// First, check if the module is already loaded, perhaps because we were run from Steam directly
	HMODULE hMod = GetModuleHandle( "GameOverlayRenderer.dll" );
	if ( hMod )
	{
		return;
	}

	const char *pchSteamInstallPath = SteamAPI_GetSteamInstallPath();
	if ( pchSteamInstallPath )
	{
		char rgchSteamPath[MAX_PATH];
		V_ComposeFileName( pchSteamInstallPath, "GameOverlayRenderer.dll", rgchSteamPath, Q_ARRAYSIZE(rgchSteamPath) );
		// This could fail, but we can't fix it if it does so just ignore failures
		LoadLibrary( rgchSteamPath );
	}
#endif
}