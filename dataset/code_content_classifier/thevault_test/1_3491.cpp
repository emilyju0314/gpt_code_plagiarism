void xiTCP::Accept( const socketHandle_t _nativeHandle, addressInfo_s * const senderInfo ) {
	sockaddr_in target;
	socklen_t targetLength = ( int )sizeof( target );
	memset( &target, 0, sizeof( target ) );
	
	nativeHandle = accept( _nativeHandle, ( sockaddr * )&target, &targetLength );

	if ( nativeHandle == INVALID_SOCKET ) {
		status = STATUS_INVALID;
	} else {
#if defined( __WIN_API__ )
		senderInfo->address.protocolV4[0] = target.sin_addr.S_un.S_un_b.s_b1;
		senderInfo->address.protocolV4[1] = target.sin_addr.S_un.S_un_b.s_b2;
		senderInfo->address.protocolV4[2] = target.sin_addr.S_un.S_un_b.s_b3;
		senderInfo->address.protocolV4[3] = target.sin_addr.S_un.S_un_b.s_b4;
#elif defined( __POSIX__ )
        memcpy( &senderInfo->address.protocolV4[0], &target.sin_addr.s_addr, sizeof( target.sin_addr.s_addr ) );
#endif

		senderInfo->port = ( uint16_t )Endian::NetworkToHostUnsigned( target.sin_port, sizeof( target.sin_port ) );
	}
}