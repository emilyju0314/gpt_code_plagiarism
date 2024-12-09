size_t NetString::ToV4Address( const char * const buffer, const size_t bufferLen, uint8_t * const output, const size_t outputLen ) {
	if ( outputLen < IP_V4_SEGMENTS || !output ) {
		// Needs 32 bit output!
		return 0;
	} else if ( !bufferLen || !buffer ) {
		// Needs an input buffer
		return 0;
	}

	size_t count = 0;
	uint8_t * byte = &output[3];

	size_t charIndex = bufferLen - 1;
	do {
		if ( buffer[charIndex] == '.' || charIndex == 0 ) {
			// Found byte point!
			char input[5];
			CopySection( input, ( charIndex ? charIndex : -1 ), buffer, bufferLen );
			
			*byte = atoi( input );
			byte--;
			
			count++;
		}
	} while ( charIndex-- );

	return count;
}