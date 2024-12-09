byteLen_t xiSocket::ReadInt32( const char * const buffer, void * const varptr ) {
	const byteLen_t size = sizeof( uint32_t );

	uint32_t num = *( uint32_t * )buffer;
	num = ( uint32_t )Endian::NetworkToHostUnsigned( num, size );

	memcpy( varptr, &num, size );

	return size;
}