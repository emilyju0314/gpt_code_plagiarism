static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "LeefCoin was released by Gilad Leef";
    const CScript genesisOutputScript = CScript() << ParseHex("04061a6f1e93404c5684f84413f7cc8d7e49de9a6c388faf02b19614f8edec2ebf6b1a41edbbb3c56b10d7dabcbb07961f9e5ac3a6f1420be83b420098f6a5e774") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}