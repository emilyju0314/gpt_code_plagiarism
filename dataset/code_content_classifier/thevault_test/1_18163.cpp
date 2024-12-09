static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "SpaceX to fly two tourists around Moon in 2018";////////////
    const CScript genesisOutputScript = CScript() << ParseHex("0404ce9b5e05e4c53dd34742d7c31ba0a134974eda77f9284499e572b2ba702722315a34538690bcbd9d147729542776a731d0923ad3ce9bac53ab9579bc147146") << OP_CHECKSIG;////////////
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}