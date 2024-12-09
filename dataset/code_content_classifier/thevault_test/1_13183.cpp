static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "I created bitbony 20/04/2018 for my dissertation";
    const CScript genesisOutputScript = CScript() << ParseHex("041e331e4dcbda799dd12bb6f238b25774367e54e28562a811a03fb4a29a36ad7d01410cfff5b17bcebe9683952c8b91450c1ed691eff143de13d4b83f6f93ef19") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}