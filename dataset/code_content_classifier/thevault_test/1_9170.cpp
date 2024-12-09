static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "BBC News - 19 Dec - Homo erectus: Ancient humans survived longer than we thought";
    const CScript genesisOutputScript = CScript() << ParseHex("044F489B07AB7D0A0454FB1D925D709B6C743B16D965E576AA05A475CBB7A58085066CE6FD73B10AC22791E121BE68E8CA44B852B22EE8F204663CF8086D3DE721") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}