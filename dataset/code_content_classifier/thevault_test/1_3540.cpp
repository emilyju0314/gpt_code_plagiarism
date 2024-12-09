int CScheme::GetMinimumFontHeightForCurrentLanguage( const char *pLanguage )
{
	char language[64];
	bool bValid = false;
	if ( IsPC() )
	{
		if ( pLanguage )
		{
			Q_strncpy( language, pLanguage, sizeof( language ) );
			bValid = true;
		}
		else
		{
			bValid = g_pSystem->GetRegistryString( "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language", language, sizeof(language)-1 );
		}
	}
	else if ( IsGameConsole() )
	{
		Q_strncpy( language, XBX_GetLanguageString(), sizeof( language ) );
		bValid = true;
	}

	if ( bValid )
	{
		if (!stricmp(language, "korean")
			|| !stricmp(language, "koreana")
			|| !stricmp(language, "tchinese")
			|| !stricmp(language, "schinese")
			|| !stricmp(language, "japanese"))
		{
			// the bitmap-based fonts for these languages simply don't work with a pt. size of less than 9 (13 pixels)
			return 13;
		}

		if ( !stricmp(language, "thai" ) )
		{
			// thai has problems below 18 pts
			return 18;
		}
	}

	// no special minimum height required
	return 0;
}