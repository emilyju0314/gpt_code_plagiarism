size_t NetString::FromV4Address( const uint8_t * const buffer, const size_t bufferLen, char * const output, const size_t outputLen ) {
	if ( outputLen < 16 || !output ) {
		// IP 4 Addresses are a minimum of 16 chars in length!
		return 0;
	} else if ( bufferLen < IP_V4_SEGMENTS || !buffer ) {
		// Needs an IP address to work!
		return 0;
	}

#if defined( __WIN_API__ )
	#pragma warning( push)
	#pragma warning( disable: 4996 )
#endif
	sprintf( output, "%u.%u.%u.%u", buffer[0], buffer[1], buffer[2], buffer[3] );
#if defined( __WIN_API__ )
	#pragma warning( pop )
#endif

	return strlen( output );
}