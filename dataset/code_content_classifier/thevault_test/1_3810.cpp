int	_V_stricmp_NegativeForUnequal( const char *s1, const char *s2 )
{
	VPROF_2( "V_stricmp", VPROF_BUDGETGROUP_OTHER_UNACCOUNTED, false, BUDGETFLAG_ALL );

	// It is not uncommon to compare a string to itself. Since stricmp
	// is expensive and pointer comparison is cheap, this simple test
	// can save a lot of cycles, and cache pollution.
	if ( s1 == s2 )
		return 0;

	uint8 const *pS1 = ( uint8 const * ) s1;
	uint8 const *pS2 = ( uint8 const * ) s2;
	int iExactMatchResult = 1;
	for(;;)
	{
		int c1 = *( pS1++ );
		int c2 = *( pS2++ );
		if ( c1 == c2 )
		{
			// strings are case-insensitive equal, coerce accumulated
			// case-difference to 0/1 and return it
			if ( !c1 ) return !iExactMatchResult;
		}
		else
		{
			if ( ! c2 )
			{
				// c2=0 and != c1  =>  not equal
				return -1;
			}
			iExactMatchResult = 0;
			c1 = FastASCIIToLower( c1 );
			c2 = FastASCIIToLower( c2 );
			if ( c1 != c2 )
			{
				// strings are not equal
				return -1;
			}
		}
		c1 = *( pS1++ );
		c2 = *( pS2++ );
		if ( c1 == c2 )
		{
			// strings are case-insensitive equal, coerce accumulated
			// case-difference to 0/1 and return it
			if ( !c1 ) return !iExactMatchResult;
		}
		else
		{
			if ( ! c2 )
			{
				// c2=0 and != c1  =>  not equal
				return -1;
			}
			iExactMatchResult = 0;
			c1 = FastASCIIToLower( c1 );
			c2 = FastASCIIToLower( c2 );
			if ( c1 != c2 )
			{
				// strings are not equal
				return -1;
			}
		}
	}
}