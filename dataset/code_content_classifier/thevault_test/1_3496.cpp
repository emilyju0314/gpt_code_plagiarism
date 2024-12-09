xiUDP * xiUDP::CreateOnPort( const uint16_t port, const uint8_t protocol ) {
	xiUDP * const self = new xiUDP( protocol );

	if ( self->status == STATUS_INVALID ) {
		delete( self );

		return nullptr;
	}

	if ( protocol == PROTO_V4 ) {
		if ( !self->BindToPortV4( port ) ) {
			delete( self );

			return nullptr;
		}
	} else if ( protocol == PROTO_V6 ) {
		if ( !self->BindToPortV6( port ) ) {
			delete( self );

			return nullptr;
		}
	} else {
		delete( self );

		return nullptr;
	}

	self->Grab();

	return self;
}