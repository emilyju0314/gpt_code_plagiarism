bool xiTCP::Connect( const addressInfo_s * const listenInfo ) {
	sockaddr_in target;
	int targetLength = ( int )sizeof( target );
	memset( &target, 0, sizeof( target ) );
	
#if defined( __WIN_API__ )
	target.sin_family = AF_INET;
	target.sin_addr.S_un.S_un_b.s_b1 = listenInfo->address.protocolV4[0];
	target.sin_addr.S_un.S_un_b.s_b2 = listenInfo->address.protocolV4[1];
	target.sin_addr.S_un.S_un_b.s_b3 = listenInfo->address.protocolV4[2];
	target.sin_addr.S_un.S_un_b.s_b4 = listenInfo->address.protocolV4[3];
#elif defined( __POSIX__ )
    memcpy( &target.sin_addr.s_addr, &listenInfo->address.protocolV4[0], sizeof( target.sin_addr.s_addr ) );
#endif
	
	target.sin_port = ( uint16_t )Endian::HostToNetworkUnsigned( listenInfo->port, sizeof( listenInfo->port ) );

	const int connectResult = connect( nativeHandle, ( sockaddr * )&target, targetLength );
	if ( connectResult == SOCKET_ERROR ) {
		return false;
	}

	return true;
}