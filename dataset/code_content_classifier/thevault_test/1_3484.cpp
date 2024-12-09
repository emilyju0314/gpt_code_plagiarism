uint64_t Endian::NetworkToHostUnsigned( const uint64_t networkInt, const uint8_t length ) {
	int64_t signedNum = *( int64_t * )&networkInt;
	signedNum = Endian::NetworkToHost( signedNum, length );

	const uint64_t result = *( int64_t * )&signedNum;

	return result;
}