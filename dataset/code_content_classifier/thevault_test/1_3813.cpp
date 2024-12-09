char *V_strncat( char *pDest, const char *pSrc, size_t maxLenInBytes, int nMaxCharsToCopy )
{
	DEBUG_LINK_CHECK;
	size_t charstocopy = (size_t)0;

	Assert( nMaxCharsToCopy >= 0 || nMaxCharsToCopy == COPY_ALL_CHARACTERS );
	
	size_t len = V_strlen(pDest);
	size_t srclen = V_strlen( pSrc );
	if ( nMaxCharsToCopy == COPY_ALL_CHARACTERS )
	{
		charstocopy = srclen;
	}
	else
	{
		charstocopy = MIN( nMaxCharsToCopy, (int)srclen );
	}

	if ( len + charstocopy >= maxLenInBytes )
	{
		charstocopy = maxLenInBytes - len - 1;
	}

	// charstocopy can end up negative if you fill a buffer and then pass in a smaller
	// buffer size. Yes, this actually happens.
	// Cast to ptrdiff_t is necessary in order to check for negative (size_t is unsigned)
	if ( charstocopy <= 0 )
	{
		return pDest;
	}

	ANALYZE_SUPPRESS( 6059 ); // warning C6059: : Incorrect length parameter in call to 'strncat'. Pass the number of remaining characters, not the buffer size of 'argument 1'
	char *pOut = strncat( pDest, pSrc, charstocopy );
	pOut[maxLenInBytes-1] = 0;
	return pOut;
}