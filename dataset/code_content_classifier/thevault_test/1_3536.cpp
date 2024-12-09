HFont CScheme::FindFontInAliasList( const char *pFontName )
{
	// FIXME: Slow!!!
	for (int i = m_FontAliases.Count(); --i >= 0; )
	{
		// exposed out for debugging ease
		const char *pAliasName = m_FontAliases[i]._fontName.String();
		if ( !strnicmp( pFontName, pAliasName, FONT_ALIAS_NAME_LENGTH ) )
		{
			return m_FontAliases[i]._font;
		}
	}

	// No dice
	return 0;
}