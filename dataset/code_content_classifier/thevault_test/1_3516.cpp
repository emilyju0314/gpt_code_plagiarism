bool xiSocket::AddressFromStringV4( const char * const address, xiSocket::addressInfo_s * const info ) {
	uint8_t bytes[IP_V4_BYTE_LEN];

	const size_t len = NetString::ToV4Address( address, strlen( address ) + 1, &bytes[0], IP_V4_BYTE_LEN );
	if ( len == 0 ) {
		return false;
	}
	
	const char * portPiece = address;
	while ( *portPiece != ':' && *portPiece != 0 ) {
		portPiece++;
	}

	if ( *portPiece == 0 ) {
		return false;
	}

	portPiece += 1;
		
	const uint16_t port = ( uint16_t )atoi( portPiece );

	return AddressV4( bytes[0], bytes[1], bytes[2], bytes[3], port, info );
}