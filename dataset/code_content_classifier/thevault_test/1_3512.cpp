byteLen_t xiSocket::WriteBytes( char * const buffer, const void * const byteptr, const byteLen_t byteLen ) {
	memcpy( &buffer[0], byteptr, ( size_t )byteLen );

	return byteLen;
}