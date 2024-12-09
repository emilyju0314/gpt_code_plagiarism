void ConfigBuilderBase::SetLdsSizeByteSize(
    Util::Abi::HardwareStage hwStage, // Hardware shader stage
    uint32_t                 value)   // Value to set
{
    if (value == 0)
    {
        return; // Optional
    }

    if (GeneratingMsgPack())
    {
        auto hwShaderNode = GetHwShaderNode(hwStage);
        hwShaderNode[Util::Abi::HardwareStageMetadataKey::LdsSize] = hwShaderNode.getDocument()->getNode(value);
    }
}