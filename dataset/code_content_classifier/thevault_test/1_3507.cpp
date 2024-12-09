byteLen_t xiSocket::WriteInt8( char * const buffer, const void * const varptr ) {
	memcpy( buffer, varptr, sizeof( uint8_t ) );

	return sizeof( uint8_t );
}