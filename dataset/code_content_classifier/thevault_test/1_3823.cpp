bool V_IsAbsolutePath( const char *pStr )
{
	if ( !( pStr[0] && pStr[1] ) )
		return false;
	
#if defined( PLATFORM_WINDOWS )
	bool bIsAbsolute = ( pStr[0] && pStr[1] == ':' ) || 
	  ( ( pStr[0] == '/' || pStr[0] == '\\' ) && ( pStr[1] == '/' || pStr[1] == '\\' ) );
#else
	bool bIsAbsolute = ( pStr[0] && pStr[1] == ':' ) || pStr[0] == '/' || pStr[0] == '\\';
#endif

	if ( IsX360() && !bIsAbsolute )
	{
		bIsAbsolute = ( V_stristr( pStr, ":" ) != NULL );
	}
	
	return bIsAbsolute;
}