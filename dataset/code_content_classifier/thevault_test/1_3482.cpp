int64_t Endian::NetworkToHost( const int64_t networkInt, const uint8_t length ) {
	int64_t result = 0;

	switch ( length ) {
	case 2:
		result = ntohs( ( uint16_t )networkInt );
		break;
	case 4:
		result = ntohl( ( uint32_t )networkInt );
		break;
	case 8:
		result = ntohll( networkInt );
		break;
	default:
		result = networkInt;
	}

	return result;
}