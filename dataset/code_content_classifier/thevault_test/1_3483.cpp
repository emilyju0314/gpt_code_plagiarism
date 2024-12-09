int64_t Endian::HostToNetwork( const int64_t hostInt, const uint8_t length ) {
	int64_t result = 0;

	switch ( length ) {
	case 2:
		result = htons( ( uint16_t )hostInt );
		break;
	case 4:
		result = htonl( ( uint32_t )hostInt );
		break;
	case 8:
		result = htonll( hostInt );
		break;
	default:
		result = hostInt;
	}

	return result;
}