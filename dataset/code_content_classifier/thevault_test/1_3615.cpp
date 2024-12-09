bool ContainsBinding( const char *pszBindingString, const char *pszBinding, bool bSearchAliases /*= false*/ )
{
	if ( !strchr( pszBindingString, ';' ) && !bSearchAliases )
	{
		return !Q_stricmp( pszBindingString, pszBinding );
	}
	else
	{
		//lwss: change this to a regular CUtlVector.
		// This is the only use of this weird Vector class that calls the wrong delete operator instead of delete[] on destruction.
		//CUtlVectorAutoPurge< char *> cmdStrings;
		CUtlVector< char *> cmdStrings;
		//lwss end
        // Tokenize the binding name
        V_SplitString( pszBindingString, ";", cmdStrings );
		FOR_EACH_VEC( cmdStrings, i )
		{
			char* szCmd = cmdStrings[ i ];
			if ( bSearchAliases )
			{
				// Search for command in any contained aliases. 
				const char* szAliasCmd = engine->AliasToCommandString( szCmd );
				// NOTE: we could use some kind of recursion guard, but recursive aliases already infinite loop 
				// when being processed by the cmd system. 
				if ( szAliasCmd )
				{
					CUtlString strCmd( szAliasCmd );
					V_StripTrailingWhitespace( strCmd.Access() ); // Alias adds trailing spaces to commands, strip it here so the compare works
					if ( ContainsBinding( strCmd.Get(), pszBinding, true ) )
						return true;
				}
			}

			if ( !Q_stricmp( pszBinding, szCmd ) )
			{
				return true;
			}
		}
		return false;
	}
}