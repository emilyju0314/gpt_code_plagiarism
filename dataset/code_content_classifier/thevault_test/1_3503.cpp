byteLen_t xiSocket::ReadInt8( const char * const buffer, void * const varptr ) {
	memcpy( varptr, buffer, sizeof( uint8_t ) );

	return sizeof( uint8_t );
}