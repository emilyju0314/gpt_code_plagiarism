static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "CNN - 1/10/2018 - Trump uses 'no collusion' 7 times in a single Russia answer.";
    const CScript genesisOutputScript = CScript() << ParseHex("04ec6c4067508aac107247623667b0cfef20ee4e17fd4a6edb457781ea7f6de109ac3448108cbe1af58db4df88da7a76fb1af47cb3987dabe9064161494d662e9c") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}