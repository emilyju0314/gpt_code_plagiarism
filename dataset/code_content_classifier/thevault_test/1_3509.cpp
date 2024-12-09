byteLen_t xiSocket::WriteInt32( char * const buffer, const void * const varptr ) {
	const byteLen_t size = sizeof( uint32_t );

	uint32_t num = *( uint32_t * )varptr;
	num = ( uint32_t )Endian::HostToNetworkUnsigned( num, size );

	memcpy( buffer, &num, size );

	return size;
}