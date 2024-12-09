void RemoveSpuriousGameParameters()
{
	// Find the last -game parameter.
	int nGameArgs = 0;
	char lastGameArg[MAX_PATH];
	for ( int i=0; i < CommandLine()->ParmCount()-1; i++ )
	{
		if ( Q_stricmp( CommandLine()->GetParm( i ), "-game" ) == 0 )
		{
			Q_snprintf( lastGameArg, sizeof( lastGameArg ), "\"%s\"", CommandLine()->GetParm( i+1 ) );
			++nGameArgs;
			++i;
		}
	}

	// We only care if > 1 was specified.
	if ( nGameArgs > 1 )
	{
		CommandLine()->RemoveParm( "-game" );
		CommandLine()->AppendParm( "-game", lastGameArg );
	}
}