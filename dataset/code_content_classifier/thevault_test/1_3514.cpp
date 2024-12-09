byteLen_t xiSocket::WriteString( char * const buffer, const char * const byteptr ) {
	const char * c = &buffer[0];
	while ( *c ) {
		c++;
	}
	const size_t strLen = ( c - &buffer[0] );

	memcpy( &buffer[0], &byteptr[0], strLen );
	const byteLen_t lenPlusNull = ( byteLen_t )strlen( byteptr ) + 1; // Returns the string plus the null terminator

	return lenPlusNull;
}