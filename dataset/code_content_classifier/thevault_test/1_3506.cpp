byteLen_t xiSocket::ReadInt64( const char * const buffer, void * const varptr ) {
	const byteLen_t size = sizeof( uint64_t );

	uint64_t num = *( uint64_t * )buffer;
	num = Endian::NetworkToHostUnsigned( num, size );

	memcpy( varptr, &num, size );

	return size;
}