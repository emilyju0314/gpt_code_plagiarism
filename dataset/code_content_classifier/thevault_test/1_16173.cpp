static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "BBC NEWS 1/March/2021 Sarkozy: Former French president sentenced to jail for corruption";
    const CScript genesisOutputScript = CScript() << ParseHex("04aec47b35fe068cd9e9044430683418f8d256a3e4af9c93b3d3981f8cca72553db204795d9485c0dcfaebb71f719390a5115944ae4bd9e1b20498a27de7aaf3a0") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}