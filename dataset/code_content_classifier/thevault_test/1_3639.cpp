bool ParseCommandLineArg( const char *pCmdLine, const char* pKey, char* pValueBuff = NULL, int valueBuffSize = 0 )
{
	int keyLen = (int)strlen( pKey );
	const char* pArg = pCmdLine;
	for ( ;; )
	{
		// scan for match
		pArg = strstr( (char*)pArg, pKey );
		if ( !pArg )
		{
			return false;
		}
		
		// found, but could be a substring
		if ( pArg[keyLen] == '\0' || pArg[keyLen] == ' ' )
		{
			// exact match
			break;
		}

		pArg += keyLen;
	}

	if ( pValueBuff )
	{
		// caller wants next token
		// skip past key and whitespace
		pArg += keyLen;
		while ( *pArg == ' ' )
		{
			pArg++;
		}

		int i;
		for ( i=0; i<valueBuffSize; i++ )
		{
			pValueBuff[i] = *pArg;
			if ( *pArg == '\0' || *pArg == ' ' )
				break;
			pArg++;
		}
		pValueBuff[i] = '\0';
	}
	
	return true;
}