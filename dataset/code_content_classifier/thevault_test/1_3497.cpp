xiUDP::xiUDP( const uint8_t protocol ) : xiProtoBase( protocol ) {
	status = STATUS_NOT_BOUND;
	nativeHandle = OpenNativeSocket( SOCK_DGRAM );

	if ( nativeHandle == INVALID_SOCKET ) {
		status = STATUS_INVALID;
	}
}