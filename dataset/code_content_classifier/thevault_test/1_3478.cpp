xiProtoBase::~xiProtoBase() {
	if ( status != STATUS_INVALID ) {
		closesocket( nativeHandle );
	}
}