uint64_t Endian::HostToNetworkUnsigned( const uint64_t hostInt, const uint8_t length ) {
	int64_t signedNum = *( int64_t * )&hostInt;
	signedNum = Endian::HostToNetwork( signedNum, length );

	const uint64_t result = *( int64_t * )&signedNum;

	return result;
}