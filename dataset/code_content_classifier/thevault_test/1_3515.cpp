bool xiSocket::AddressV4( const uint8_t bA, const uint8_t bB, const uint8_t bC, const uint8_t bD, const uint16_t port, xiSocket::addressInfo_s * const info ) {
	if ( info == nullptr ) {
		return false;
	}

	info->address.protocolV4[0] = bA;
	info->address.protocolV4[1] = bB;
	info->address.protocolV4[2] = bC;
	info->address.protocolV4[3] = bD;
	info->port = port;

	return true;
}