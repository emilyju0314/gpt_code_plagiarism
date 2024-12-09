uint16_t xiProtoBase::GetPort() const {
	if ( protocolVer == PROTO_V4 ) {
		sockaddr_in addressInfo;
		socketLen_t infoLen = sizeof( addressInfo );
		if ( getsockname( nativeHandle, ( sockaddr * )&addressInfo, &infoLen ) != -1 ) {
			return ( uint16_t )Endian::NetworkToHost( addressInfo.sin_port, sizeof( addressInfo.sin_port ) );
		}
	} else if ( protocolVer == PROTO_V6 ) {
		sockaddr_in6 addressInfo;
		socketLen_t infoLen = sizeof( addressInfo );
		if ( getsockname( nativeHandle, ( sockaddr * )&addressInfo, &infoLen ) != -1 ) {
			return ( uint16_t )Endian::NetworkToHost( addressInfo.sin6_port, sizeof( addressInfo.sin6_port ) );
		}
	}
	
	return 0;
}