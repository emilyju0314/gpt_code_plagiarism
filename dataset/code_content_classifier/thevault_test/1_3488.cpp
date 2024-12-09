xiTCP * xiTCPListen::Listen( addressInfo_s * const senderInfo ) {
	const int listenStatus = listen( nativeHandle, 1 );
	if ( !listenStatus ) {
		// worked, open connection
		xiTCP * const newConnection = CreateOnSocket( nativeHandle, senderInfo, protocolVer );

		return newConnection;
	} else {
		status = STATUS_ERROR;
	}

	return nullptr;
}