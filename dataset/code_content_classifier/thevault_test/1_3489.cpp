xiTCP * xiTCPListen::CreateOnSocket( const socketHandle_t _nativeHandle, addressInfo_s * const senderInfo, const uint8_t protocol ) {
	xiTCP * const self = new xiTCP( protocol );
	self->Accept( _nativeHandle, senderInfo );

	if ( self->status == STATUS_INVALID ) {
		delete( self );

		return nullptr;
	}
	
	self->Grab();

	return self;
}