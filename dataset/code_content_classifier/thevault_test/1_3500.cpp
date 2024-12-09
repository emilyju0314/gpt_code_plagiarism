byteLen_t xiUDP::BroadcastBuffer( const char * const buffer, const int32_t bufferLength, const uint16_t port ) {
	if ( SetBroadcasting( true ) == false ) {
		return -1; // Could not enable broadcasting
	}

	sockaddr_in target;
	int targetLength = ( int )sizeof( target );
	memset( &target, 0, sizeof( target ) );
	
	if ( protocolVer == PROTO_V4 ) {
		target.sin_family = AF_INET;
	} else if ( protocolVer == PROTO_V6 ) {
		target.sin_family = AF_INET6;
	} else {
		return -1;
	}

    target.sin_addr.s_addr = INADDR_BROADCAST;

	target.sin_port = ( uint16_t )Endian::HostToNetworkUnsigned( port, sizeof( port ) );

	const byteLen_t sentBytes = sendto( nativeHandle, buffer, bufferLength, 0, ( sockaddr * )&target, targetLength );

	return sentBytes;
}