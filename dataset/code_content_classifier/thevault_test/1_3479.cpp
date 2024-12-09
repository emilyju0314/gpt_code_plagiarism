bool xiProtoBase::SetBroadcasting( const bool doBroadcast ) {
	if ( broadcastAllowed == doBroadcast ) {
		// This broadcast option is already set
		return true;
	} else if ( doBroadcast ) {
		int val = 1;
		const int optStatus = setsockopt( nativeHandle, SOL_SOCKET, SO_BROADCAST, ( char * )&val, sizeof( int ) );
		if ( optStatus != SOCKET_ERROR ) {
			broadcastAllowed = doBroadcast;
		} else {
			return false;
		}
	} else {
		int val = 0;
		const int optStatus = setsockopt( nativeHandle, SOL_SOCKET, SO_BROADCAST, ( char * )&val, sizeof( int ) );
		if ( optStatus != SOCKET_ERROR ) {
			broadcastAllowed = doBroadcast;
		} else {
			return false;
		}
	}

	return true;
}