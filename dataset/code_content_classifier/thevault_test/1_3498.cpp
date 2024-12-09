byteLen_t xiUDP::ReadIntoBuffer( char * const buffer, const int32_t bufferLength, addressInfo_s * const senderInfo ) {
	union {
		sockaddr_in		v4;
		sockaddr_in6	v6;
	} sender;

	socklen_t senderLength = ( socklen_t )sizeof( sender );
	const byteLen_t receivedBytes = recvfrom( nativeHandle, buffer, bufferLength, 0, ( sockaddr * )&sender, &senderLength );

	if ( senderInfo ) {
		memset( senderInfo, 0, sizeof( *senderInfo ) );
        
		if ( protocolVer == PROTO_V4 ) {
#if defined( __WIN_API__ )
			senderInfo->address.protocolV4[0] = sender.v4.sin_addr.S_un.S_un_b.s_b1;
			senderInfo->address.protocolV4[1] = sender.v4.sin_addr.S_un.S_un_b.s_b2;
			senderInfo->address.protocolV4[2] = sender.v4.sin_addr.S_un.S_un_b.s_b3;
			senderInfo->address.protocolV4[3] = sender.v4.sin_addr.S_un.S_un_b.s_b4;
#elif defined( __POSIX__ )
			memcpy( &senderInfo->address.protocolV4[0], &sender.v4.sin_addr.s_addr, sizeof( sender.v4.sin_addr.s_addr ) );
#endif
			senderInfo->port = ( uint16_t )Endian::NetworkToHostUnsigned( sender.v4.sin_port, sizeof( sender.v4.sin_port ) );
		} else if ( protocolVer == PROTO_V6 ) {
#if defined( __WIN_API__ )
			memcpy( &senderInfo->address.protocolV6[0], &sender.v6.sin6_addr.u.Byte[0], sizeof( sender.v6.sin6_addr.u ) );
			senderInfo->port = ( uint16_t )Endian::NetworkToHostUnsigned( sender.v6.sin6_port, sizeof( sender.v6.sin6_port ) );
#elif defined( __POSIX__ )
			memcpy( &senderInfo->address.protocolV6[0], &sender.v6.sin6_addr, sizeof( sender.v6.sin6_addr ) );
#endif
		}
	}

	return receivedBytes;
}