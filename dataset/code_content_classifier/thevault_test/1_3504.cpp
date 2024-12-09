byteLen_t xiSocket::ReadInt16( const char * const buffer, void * const varptr ) {
	const byteLen_t size = sizeof( uint16_t );

	uint16_t num = *( uint16_t * )buffer;
	num = ( uint16_t )Endian::NetworkToHostUnsigned( num, size );

	memcpy( varptr, &num, size );

	return size;
}