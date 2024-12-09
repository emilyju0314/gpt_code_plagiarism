byteLen_t xiSocket::WriteInt16( char * const buffer, const void * const varptr ) {
	const byteLen_t size = sizeof( uint16_t );

	uint16_t num = *( uint16_t * )varptr;
	num = ( uint16_t )Endian::HostToNetworkUnsigned( num, size );

	memcpy( buffer, &num, size );

	return size;
}