void ConfigBuilderBase::SetShaderHash(
    ShaderStage apiStage, // API shader stage
    uint64_t    hash64)   // Its hash
{
    if (GeneratingMsgPack())
    {
        auto hashNode = GetApiShaderNode(uint32_t(apiStage))[Util::Abi::ShaderMetadataKey::ApiShaderHash].getArray(true);
        hashNode[0] = hashNode.getDocument()->getNode(hash64);
        hashNode[1] = hashNode.getDocument()->getNode(0U);
    }
    else
    {
        static const uint32_t hashKeys[] =
        {
            // In ShaderStage order
            mmAPI_VS_HASH_DWORD0,
            mmAPI_HS_HASH_DWORD0,
            mmAPI_DS_HASH_DWORD0,
            mmAPI_GS_HASH_DWORD0,
            mmAPI_PS_HASH_DWORD0,
            mmAPI_CS_HASH_DWORD0
        };
        SetPseudoRegister(hashKeys[apiStage], uint32_t(hash64));
        SetPseudoRegister(hashKeys[apiStage] + 1, uint32_t(hash64 >> 32));
    }
}