xiTCP * xiTCP::ConnectTo( const addressInfo_s * const listenInfo, const uint8_t protocol ) {
	xiTCP * const self = new xiTCP( protocol );

	self->nativeHandle = OpenNativeSocket( SOCK_STREAM );
	if ( self->nativeHandle == INVALID_SOCKET ) {
		self->status = STATUS_INVALID;
	}

	if ( self->status == STATUS_INVALID ) {
		delete( self );

		return nullptr;
	}

	if ( protocol == PROTO_V4 ) {
		if ( !self->BindToPortV4( 0 ) ) {
			delete( self );

			return nullptr;
		}
	} else if ( protocol == PROTO_V6 ) {
		if ( !self->BindToPortV6( 0 ) ) {
			delete( self );

			return nullptr;
		}
	} else {
		delete( self );

		return nullptr;
	}

	const bool isConnected = self->Connect( listenInfo );
	if ( !isConnected ) {
		delete( self );

		return nullptr;
	}

	self->Grab();

	return self;
}