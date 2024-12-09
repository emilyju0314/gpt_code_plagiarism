const char* V_stristr( const char* pStr, const char* pSearch )
{
	Assert( pStr );
	Assert( pSearch );
	if (!pStr || !pSearch) 
		return 0;

	const char* pLetter = pStr;

	// Check the entire string
	while (*pLetter != 0)
	{
		// Skip over non-matches
		if ( FastASCIIToLower( *pLetter ) == FastASCIIToLower( *pSearch) )
		{
			// Check for match
			const char* pMatch = pLetter + 1;
			const char* pTest = pSearch + 1;
			while (*pTest != 0)
			{
				// We've run off the end; don't bother.
				if (*pMatch == 0)
					return 0;

				if ( FastASCIIToLower( *pMatch) != FastASCIIToLower( *pTest ) )
					break;

				++pMatch;
				++pTest;
			}

			// Found a match!
			if ( *pTest == 0 )
				return pLetter;
		}

		++pLetter;
	}

	return 0;
}