char const * Host_CleanupConVarStringValue( char const *invalue )
{
	static char clean[ 256 ];

	Q_snprintf( clean, sizeof( clean ), "%s", invalue );

	// Don't mess with empty string
	// Otherwise, if it appears numeric and has a decimal, try to strip all zeroes after decimal
	if ( Q_strlen( clean ) >= 1 && AppearsNumeric( clean ) && Q_strstr( clean, "." ) )
	{
		char *end = clean + strlen( clean ) - 1;
		while ( *end && end >= clean )
		{
			// Removing trailing zeros
			if ( *end != '0' )
			{
				// Remove decimal, zoo
				if ( *end == '.' )
				{
					if ( end == clean )
					{
						*end = '0';
					}
					else
					{
						*end = 0;
					}
				}
				break;
			}

			*end-- = 0;
		}
	}

	return clean;
}