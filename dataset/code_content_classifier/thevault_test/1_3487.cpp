xiTCPListen::xiTCPListen( const uint8_t protocol ) : xiProtoBase( protocol ) {
	status = STATUS_NOT_BOUND;
	nativeHandle = OpenNativeSocket( SOCK_STREAM );

	if ( nativeHandle == INVALID_SOCKET ) {
		status = STATUS_INVALID;
	}
}