byteLen_t xiSocket::ReadString( const char * const buffer, char * const byteptr ) {
	const char * c = &buffer[0];
	while ( *c ) {
		c++;
	}
	const size_t strLen = ( c - &buffer[0] );

	memcpy( &byteptr[0], &buffer[0], strLen );
	const byteLen_t lenPlusNull = ( byteLen_t )strlen( buffer ) + 1; // Returns the string plus the null terminator

	return lenPlusNull;
}