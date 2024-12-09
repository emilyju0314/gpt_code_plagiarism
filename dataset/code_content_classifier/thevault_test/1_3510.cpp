byteLen_t xiSocket::WriteInt64( char * const buffer, const void * const varptr ) {
	const byteLen_t size = sizeof( uint64_t );

	uint64_t num = *( uint64_t * )varptr;
	num = Endian::HostToNetworkUnsigned( num, size );

	memcpy( buffer, &num, size );

	return size;
}