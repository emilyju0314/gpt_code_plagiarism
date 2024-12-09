static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Red Lotus Network is here 12/10/2018";
    const CScript genesisOutputScript = CScript() << ParseHex("04dc110385f94e73951ee147c4a0e375d4e4cadac4a6d7bdb24b35f8392cb173b62b5431687903a607f370dcaecd39959c10b06d9913ea2100c436fca615d6e63e") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}