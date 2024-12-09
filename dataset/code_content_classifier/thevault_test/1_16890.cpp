void EnumSavedGames(char chDrive)
{
	MFCALLSTACK;

	HANDLE hFind;
	XGAME_FIND_DATA xgfd;
	char szDrive[] = "X:\\";

	*szDrive = chDrive;
	hFind = XFindFirstSaveGame( szDrive, &xgfd );

	if( INVALID_HANDLE_VALUE != hFind )
	{
		do
		{
			OutputDebugStringW( xgfd.szSaveGameName );
			OutputDebugString( "\r\n" );
		} while( XFindNextSaveGame( hFind, &xgfd ) );

		XFindClose( hFind );
	}

	return;
}