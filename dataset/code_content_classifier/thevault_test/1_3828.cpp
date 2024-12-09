char const *V_ParseLine( char const *pStrIn, char *pToken, int bufsize, bool *pbOverflowed /*= NULL*/ )
{
	if ( pbOverflowed )
	{
		*pbOverflowed = false;
	}

	int maxpos = bufsize - 1;
	int             len;

	len = 0;
	pToken[0] = 0;

	if (!pStrIn)
		return NULL;
	if ( maxpos <= 0 )
		return pStrIn;

	while ( *pStrIn && *pStrIn != '\n')
	{
		pToken[ len++ ] = *pStrIn++; 
		if ( len >= maxpos )
		{
			if ( pbOverflowed )
			{
				*pbOverflowed = true;
			}
			return NULL;
		}
	}

	pToken[len] = 0;

	if ( *pStrIn == 0 )
		return NULL;

	return pStrIn + 1;	
}