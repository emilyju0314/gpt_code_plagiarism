void StripCommandLineArg( const char *pCmdLine, char *pNewCmdLine, const char *pStripArg )
{
	// cannot operate in place
	assert( pCmdLine != pNewCmdLine );

	int numTotal = strlen( pCmdLine ) + 1;
	const char* pArg = strstr( pCmdLine, pStripArg );
	if ( !pArg )
	{
		strcpy( pNewCmdLine, pCmdLine );
		return;
	}

	int numDiscard = strlen( pStripArg );
	while ( pArg[numDiscard] && ( pArg[numDiscard] != '-' && pArg[numDiscard] != '+' ) )
	{
		// eat whitespace up to the next argument
		numDiscard++;
	}

	memcpy( pNewCmdLine, pCmdLine, pArg - pCmdLine );
	memcpy( pNewCmdLine + ( pArg - pCmdLine ), (void*)&pArg[numDiscard], numTotal - ( pArg + numDiscard - pCmdLine  ) );

	// ensure we don't leave any trailing whitespace, occurs if last arg is stripped
	int len = strlen( pNewCmdLine );
	while ( len > 0 &&  pNewCmdLine[len-1] == ' ' )
	{
		len--;
	}
	pNewCmdLine[len] = '\0';
}