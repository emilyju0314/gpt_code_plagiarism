xiSocket::xiSocket() {
	nativeHandle = 0; // This is a null socket, it shouldn't do anything

#if defined( __WIN_API__ )
	if ( winsockReferenceCount++ == 0 ) {
		const int winSockError = WSAStartup( MAKEWORD( 2, 2 ), &winSockData ); // Start winsock
		if ( winSockError ) {
			if ( --winsockReferenceCount == 0 ) {
				WSACleanup(); // Destroy winsock
			}

			status = STATUS_ERROR;
		}
	}
#endif
}