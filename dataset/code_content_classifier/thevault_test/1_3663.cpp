bool CEconItemSchema::BInit( const char *fileName, const char *pathID, CUtlVector<CUtlString> *pVecErrors /* = NULL */)
{
	Reset();
	m_pKVRawDefinition = new KeyValues( "CEconItemSchema" );
	m_pKVRawDefinition->UsesEscapeSequences( true );
	if ( !m_pKVRawDefinition->LoadFromFile( g_pFullFileSystem, fileName, pathID ) )
	{
		m_pKVRawDefinition->deleteThis();
		m_pKVRawDefinition = NULL;
	}

	if ( m_pKVRawDefinition )
	{
#if defined( CLIENT_DLL )
		if ( KeyValues *kvLiveTemplate = m_pKVRawDefinition->FindKey( "items_game_live" ) )
		{
			// for client code we also load the live file to supplement certain portions of schema
			char chLiveFilename[MAX_PATH];
			V_strcpy_safe( chLiveFilename, fileName );
			if ( char *chExt = V_strrchr( chLiveFilename, '.' ) )
			{
				char chSuffix[ 64 ] = {};
				V_sprintf_safe( chSuffix, "_live%s", chExt );
				
				*chExt = 0;
				V_strcat_safe( chLiveFilename, chSuffix );

				KeyValues *kvLive = new KeyValues( "CEconItemSchema" );
				kvLive->UsesEscapeSequences( true );

				if ( kvLive->LoadFromFile( g_pFullFileSystem, chLiveFilename, pathID ) )
				{
					Helper_MergeKeyValuesUsingTemplate( m_pKVRawDefinition, kvLive, kvLiveTemplate );
				}

#if MERGE_LIVE_PLAYERS_CODE
				if ( KeyValues *kvDump = m_pKVRawDefinition->FindKey( "pro_players" ) )
				{
					kvDump->SaveToFile( g_pFullFileSystem, "pro_players_merged.txt" );
				}
#endif

				kvLive->deleteThis();
				kvLive = NULL;
			}
		}
#endif
		return BInitSchema( m_pKVRawDefinition, pVecErrors );
	}
	else
	{
#if !defined(CSTRIKE_DLL)
		Warning( "No %s file found. May be unable to create items.\n", fileName );
#endif // CSTRIKE_DLL
		return false;
	}	
}