void UseDefaultBindings( void )
{
	FileHandle_t f;
	char szFileName[ _MAX_PATH ];
	char token[ 1024 ];
	char szKeyName[ 256 ];

	// read kb_def file to get default key binds
	Q_snprintf( szFileName, sizeof( szFileName ), "%skb_def.lst", SCRIPT_DIR );
	f = g_pFileSystem->Open( szFileName, "r");
	if ( !f )
	{
		ConMsg( "Couldn't open kb_def.lst\n" );
		return;
	}

	// read file into memory
	int size = g_pFileSystem->Size(f);
	char *startbuf = new char[ size ];
	g_pFileSystem->Read( startbuf, size, f );
	g_pFileSystem->Close( f );

	const char *buf = startbuf;
	while ( 1 )
	{
		buf = COM_ParseFile( buf, token, sizeof( token ) );
		if ( strlen( token ) <= 0 )
			break;
		Q_strncpy ( szKeyName, token, sizeof( szKeyName ) );

		buf = COM_ParseFile( buf, token, sizeof( token ) );
		if ( strlen( token ) <= 0 )  // Error
			break;

		// finally, bind key
		Key_SetBinding ( g_pInputSystem->StringToButtonCode( szKeyName ), token );
	}
	delete [] startbuf;		// cleanup on the way out
}