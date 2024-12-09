const char* GetRegisterNameString(
    GfxIpVersion gfxIp, // Graphics IP version info
    uint32_t     regId) // ID (byte-based) of the register
{
    LLPC_ASSERT(gfxIp.major <= 8);

    if (RegNameMap.empty())
    {
        InitRegisterNameMap(gfxIp);
    }

    const char* pNameString = nullptr;
    if ((regId / 4 >= Util::Abi::PipelineMetadataBase) &&
        (regId / 4 <= Util::Abi::PipelineMetadataBase + static_cast<uint32_t>(Util::Abi::PipelineMetadataType::Count)))
    {
        pNameString = Util::Abi::PipelineMetadataNameStrings[regId / 4 - Util::Abi::PipelineMetadataBase];
    }
    else
    {
        auto nameMap = RegNameMap.find(regId);
        if  (nameMap != RegNameMap.end())
        {
            pNameString = nameMap->second;
        }
        else
        {
            static char unknownRegNameBuf[256] = {};
            int32_t length = snprintf(unknownRegNameBuf, 256, "UNKNOWN(0x%08X)", regId);
            LLPC_UNUSED(length);
            pNameString = unknownRegNameBuf;
        }
    }

    return pNameString;
}