xiSocket::~xiSocket() {
#if defined( __WIN_API__ )
	if ( --winsockReferenceCount == 0 ) {
		WSACleanup(); // Destroy winsock
	}
#endif
}