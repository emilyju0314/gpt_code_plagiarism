void CScheme::LoadFonts()
{
	char language[64];
	bool bValid = false;

	// get our language
	if ( IsPC() )
	{
		bValid = vgui::g_pSystem->GetRegistryString( "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language", language, sizeof( language ) - 1 );
	}
	else if ( IsGameConsole() )
	{
		Q_strncpy( language, XBX_GetLanguageString(), sizeof( language ) );
		bValid = true;
	}

	if ( !bValid )
	{
		Q_strncpy( language, "english", sizeof( language ) );
	}

	// add our custom fonts
	for (KeyValues *kv = m_pData->FindKey("CustomFontFiles", true)->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey())
	{
		const char *fontFile = kv->GetString();
		if (fontFile && *fontFile)
		{
			g_pSchemeManager->GetSurface()->AddCustomFontFile( fontFile );
		}
		else
		{
			// we have a block to read
			int nRangeMin = 0, nRangeMax = 0;
			const char *pszName = NULL;
			bool bUseRange = false;

			for ( KeyValues *pData = kv->GetFirstSubKey(); pData != NULL; pData = pData->GetNextKey() )
			{
				const char *pszKey = pData->GetName();
				if ( !Q_stricmp( pszKey, "font" ) )
				{
					fontFile = pData->GetString();
				}
				else if ( !Q_stricmp( pszKey, "name" ) )
				{
					pszName = pData->GetString();
				}
				else
				{
					// we must have a language
					if ( Q_stricmp( language, pszKey ) == 0 ) // matches the language we're running?
					{
						// get the range
						KeyValues *pRange = pData->FindKey( "range" );
						if ( pRange )
						{
							bUseRange = true;
							sscanf( pRange->GetString(), "%x %x", &nRangeMin, &nRangeMax );

							if ( nRangeMin > nRangeMax )
							{
								int nTemp = nRangeMin;
								nRangeMin = nRangeMax;
								nRangeMax = nTemp;
							}
						}
					}
				}
			}

			if ( fontFile && *fontFile )
			{
				g_pSchemeManager->GetSurface()->AddCustomFontFile( fontFile );

				if ( bUseRange )
				{
					SetFontRange( pszName, nRangeMin, nRangeMax );
				}
			}
		}
	}

	// add bitmap fonts
	for (KeyValues *kv = m_pData->FindKey("BitmapFontFiles", true)->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey())
	{
		const char *fontFile = kv->GetString();
		if (fontFile && *fontFile)
		{
			bool bSuccess = g_pSchemeManager->GetSurface()->AddBitmapFontFile( fontFile );
			if ( bSuccess )
			{
				// refer to the font by a user specified symbol
				g_pSchemeManager->GetSurface()->SetBitmapFontName( kv->GetName(), fontFile );
			}
		}
	}

	// create the fonts
	for (KeyValues *kv = m_pData->FindKey("Fonts", true)->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey())
	{
		// check to see if the font has been specified as having ONLY a proportional or ONLY a nonproportional
		// version. (if not, the default is to make both a normal font, then a proportional one)
		const char *proportionality = kv->GetString( "isproportional" );
		if ( proportionality && proportionality[0] != 0 )
		{
			if ( V_strcmp( proportionality, "only" ) == 0 )
			{	// ONLY a proportional version
				AddFontHelper( kv->GetName(), true );
			}
			else if ( V_strcmp( proportionality, "no" ) == 0 )
			{	// ONLY a nonproportional version
				AddFontHelper( kv->GetName(), false );
			}
			else for ( int i = 0; i < 2; i++ ) // else default behavior (both) 
			{
				// create the base font
				bool proportionalFont = i ? true : false;
				AddFontHelper( kv->GetName(), proportionalFont );
			}
		}
		else for ( int i = 0; i < 2; i++ )
		{
			// create the base font
			bool proportionalFont = i ? true : false;
			AddFontHelper( kv->GetName(), proportionalFont );
			/*
			const char *fontName = GetMungedFontName( kv->GetName(), m_tag.String(), proportionalFont ); // first time it adds a normal font, and then a proportional one
			HFont font = g_pSchemeManager->GetSurface()->CreateFont();
			int j = m_FontAliases.AddToTail();
			m_FontAliases[j]._fontName = fontName;
			m_FontAliases[j]._trueFontName = kv->GetName();
			m_FontAliases[j]._font = font;
			m_FontAliases[j].m_bProportional = proportionalFont;
			*/
		}
	}

	// add critical font section
	for ( KeyValues *kv = m_pData->FindKey( "CriticalFonts", true )->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey() )
	{
		const char *pFontFile = kv->GetName();
		if ( pFontFile && *pFontFile )
		{
			AddCriticalFont( pFontFile, kv );
		}
	}

	// load in the font glyphs
	ReloadFontGlyphs();

	PrecacheCriticalFontGlyphs( language );
}