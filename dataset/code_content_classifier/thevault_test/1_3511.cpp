byteLen_t xiSocket::ReadBytes( const char * const buffer, void * const byteptr, const byteLen_t byteLen ) {
	memcpy( byteptr, &buffer[0], ( size_t )byteLen );

	return byteLen;
}