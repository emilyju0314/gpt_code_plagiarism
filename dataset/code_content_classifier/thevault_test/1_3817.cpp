int _V_UnicodeToUCS2( const wchar_t *pUnicode, int cubSrcInBytes, char *pUCS2, int cubDestSizeInBytes )
{
	 // TODO: MACMERGE: Figure out how to convert from 2-byte Win32 wchars to platform wchar_t type that can be 4 bytes
#if defined( _WIN32 ) || defined( _PS3 )
	// Figure out which buffer is smaller and convert from bytes to character
	// counts.
	int cchResult = MIN(cubSrcInBytes/sizeof(wchar_t), cubDestSizeInBytes/sizeof(wchar_t) );
	wchar_t *pDest = (wchar_t*)pUCS2;
	wcsncpy( pDest, pUnicode, cchResult );
	// Make sure we NULL-terminate.
	pDest[ cchResult - 1 ] = 0;

#elif defined (POSIX)
	iconv_t conv_t = iconv_open( "UCS-2LE", "UTF-32LE" );
	size_t cchResult = -1;
	size_t nLenUnicde = cubSrcInBytes;
	size_t nMaxUCS2 = cubDestSizeInBytes;
	char *pIn = (char*)pUnicode;
	char *pOut = pUCS2;
	if ( conv_t > (iconv_t)0 )
	{
		cchResult = 0;
		cchResult = iconv( conv_t, &pIn, &nLenUnicde, &pOut, &nMaxUCS2 );
		iconv_close( conv_t );
		if ( (int)cchResult < 0 )
			cchResult = 0;
		else
			cchResult = cubSrcInBytes / sizeof( wchar_t );
	}
#else
	#error Must be implemented for this platform
#endif
	return cchResult;	
}