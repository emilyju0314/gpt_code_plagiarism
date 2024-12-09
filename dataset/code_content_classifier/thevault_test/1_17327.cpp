static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount &genesisReward,
	std::vector<unsigned char> extraNonce) {
	const char *pszTimestamp = "Bitcoin hash: 00000000000000000043e9b341aba1b492927f3a063342ab1792297cbe7d296b";
	const CScript genesisOutputScript = CScript();
	return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward,
		extraNonce);
}