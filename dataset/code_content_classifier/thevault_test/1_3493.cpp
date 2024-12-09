void NetString::CopySection( char input[5], size_t charIndex, const char * const buffer, const size_t bufferLen ) {
	const size_t charA = ( charIndex + IP_V4_SEGMENTS - 3 );
	const size_t charB = ( charIndex + IP_V4_SEGMENTS - 2 );
	const size_t charC = ( charIndex + IP_V4_SEGMENTS - 1 );
	const size_t charD = ( charIndex + IP_V4_SEGMENTS );

	if ( charA < bufferLen && buffer[charA] != '.' ) {
		input[0] = buffer[charA];
	} else {
		input[0] = 0;
	}
	if ( charB < bufferLen && buffer[charB] != '.' ) {
		input[1] = buffer[charB];
	} else {
		input[1] = 0;
	}
	if ( charC < bufferLen && buffer[charC] != '.' ) {
		input[2] = buffer[charC];
	} else {
		input[2] = 0;
	}
	if ( charD < bufferLen && buffer[charD] != '.' ) {
		input[3] = buffer[charD];
	} else {
		input[3] = 0;
	}
	input[4] = 0; // Null terminate
}