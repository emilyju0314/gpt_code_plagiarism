HScheme CSchemeManager::LoadSchemeFromFileEx( VPANEL sizingPanel, const char *pFilename, const char *tag)
{
	VPROF("CSchemeManager::LoadSchemeFromFile");

	// Look to see if we've already got this scheme...
	HScheme hScheme = FindLoadedScheme( pFilename );
	CScheme *pScheme = NULL;

	if ( hScheme != 0 )
	{
		pScheme = m_Schemes[ hScheme ];
		if ( pScheme->IsActive() )
		{
			// found active scheme
			if ( IsPC() )
			{
				pScheme->ReloadFontGlyphs();
			}
			return hScheme;
		}
	}
	
	KeyValues *pKVData = new KeyValues( "Scheme" );

	pKVData->UsesEscapeSequences( true );	// VGUI uses this
	
	{
		//VPROF_2( "CSchemeManager::LoadSchemeFromFileEx -> LoadFromFile", VPROF_BUDGETGROUP_OTHER_VGUI, false, 0 );
		VPROF( "CSchemeManager::LoadSchemeFromFileEx -> LoadFromFile" );

		// look first in skins directory
		bool bResult = pKVData->LoadFromFile( g_pFullFileSystem, pFilename, "SKIN" );
		if ( !bResult )
		{
			bResult = pKVData->LoadFromFile( g_pFullFileSystem, pFilename, "GAME" );
			if ( !bResult )
			{
				// look in any directory
				bResult = pKVData->LoadFromFile( g_pFullFileSystem, pFilename, NULL );
			}
		}

		if ( !bResult )
		{
			pKVData->deleteThis();
			return 0;
		}
	}
	
	if ( hScheme == 0 )
	{
		// not using an existing inactive scheme
		// add new scheme
		pScheme = new CScheme();
		hScheme = m_Schemes.AddToTail( pScheme );
	}

	if ( IsPC() )
	{
		ConVarRef cl_hud_minmode( "cl_hud_minmode", true );
		if ( cl_hud_minmode.IsValid() && cl_hud_minmode.GetBool() )
		{
			pKVData->ProcessResolutionKeys( "_minmode" );
		}
	}

	{
		//VPROF_2( "pScheme->LoadFromFile", VPROF_BUDGETGROUP_OTHER_VGUI, false, 0 );
		VPROF( "pScheme->LoadFromFile" );
		pScheme->SetActive( true );
		pScheme->LoadFromFile( sizingPanel, pFilename, tag, pKVData );
	}

	return hScheme;
}