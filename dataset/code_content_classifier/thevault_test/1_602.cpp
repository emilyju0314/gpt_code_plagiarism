static CBlock CreateGenesisBlock(uint32_t nTime=1390262400, uint32_t nNonce=13562315, uint32_t nBits=0x1e0fffff, int32_t nVersion=112, const CAmount& genesisReward=1 * COIN)
{
    const char* pszTimestamp = "Shueisha Reveals Winners of Shonen Jump Manga Contest";
    CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}