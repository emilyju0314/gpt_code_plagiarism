byteLen_t xiUDP::SendBufferToAddress( const char * const buffer, const int32_t bufferLength, const addressInfo_s * const targetInfo ) {
	if ( SetBroadcasting( false ) == false ) {
		return -1; // Could not disable broadcasting
	}

	union {
		sockaddr_in		v4;
		sockaddr_in6	v6;
	} target;
	int targetLength = ( int )sizeof( target );
	memset( &target, 0, sizeof( target ) );
	
	if ( protocolVer == PROTO_V4 ) {
#if defined( __WIN_API__ )
		target.v4.sin_family = AF_INET;
		target.v4.sin_addr.S_un.S_un_b.s_b1 = targetInfo->address.protocolV4[0];
		target.v4.sin_addr.S_un.S_un_b.s_b2 = targetInfo->address.protocolV4[1];
		target.v4.sin_addr.S_un.S_un_b.s_b3 = targetInfo->address.protocolV4[2];
		target.v4.sin_addr.S_un.S_un_b.s_b4 = targetInfo->address.protocolV4[3];
#elif defined( __POSIX__ )
		memcpy( &target.v4.sin_addr.s_addr, &targetInfo->address.protocolV4[0], sizeof( target.v4.sin_addr.s_addr ) );
#endif
		target.v4.sin_port = ( uint16_t )Endian::HostToNetworkUnsigned( targetInfo->port, sizeof( targetInfo->port ) );
	} else if ( protocolVer == PROTO_V6 ) {
#if defined( __WIN_API__ )
		memcpy( &target.v6.sin6_addr.u.Byte[0], &targetInfo->address.protocolV6[0], sizeof( target.v6.sin6_addr.u ) );
		target.v6.sin6_port = ( uint16_t )Endian::HostToNetworkUnsigned( targetInfo->port, sizeof( targetInfo->port ) );
#elif defined( __POSIX__ )
		memcpy( &target.v6.sin6_addr, &targetInfo->address.protocolV6[0], sizeof( target.v6.sin6_addr ) );
#endif
	}

	const byteLen_t sentBytes = sendto( nativeHandle, buffer, bufferLength, 0, ( sockaddr * )&target, targetLength );

	return sentBytes;
}