void UTIL_ComputeBaseDir()
{
#ifndef _PS3
	g_szBasedir[0] = 0;

	if ( IsX360() )
	{
		char const *pBaseDir = CommandLine()->ParmValue( "-basedir" );
		if ( pBaseDir )
		{
			strcpy( g_szBasedir, pBaseDir );
		}
	}

	if ( !g_szBasedir[0] && GetExecutableName( g_szBasedir, sizeof( g_szBasedir ) ) )
	{
		char *pBuffer = strrchr( g_szBasedir, '\\' );
		if ( *pBuffer )
		{
			*(pBuffer+1) = '\0';
		}

		int j = strlen( g_szBasedir );
		if (j > 0)
		{
			if ( ( g_szBasedir[j-1] == '\\' ) || 
				 ( g_szBasedir[j-1] == '/' ) )
			{
				g_szBasedir[j-1] = 0;
			}
		}
	}

	if ( IsPC() )
	{
		char const *pOverrideDir = CommandLine()->CheckParm( "-basedir" );
		if ( pOverrideDir )
		{
			strcpy( g_szBasedir, pOverrideDir );
		}
	}

#ifdef WIN32
	Q_strlower( g_szBasedir );
#endif
	Q_FixSlashes( g_szBasedir );

#else
	

#endif
}