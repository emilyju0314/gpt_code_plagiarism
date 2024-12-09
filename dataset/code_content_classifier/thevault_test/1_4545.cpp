void ConfigBuilderBase::SetNumAvailVgprs(
    Util::Abi::HardwareStage hwStage, // Hardware shader stage
    uint32_t value)                   // Number of available VGPRs
{
    if (GeneratingMsgPack())
    {
        auto hwShaderNode = GetHwShaderNode(hwStage);
        hwShaderNode[Util::Abi::HardwareStageMetadataKey::VgprLimit] = hwShaderNode.getDocument()->getNode(value);
    }
    else
    {
        static const uint32_t availVgprsKeys[] =
        {
            // In Util::Abi::HardwareStage order
            mmLS_NUM_AVAIL_VGPRS,
            mmHS_NUM_AVAIL_VGPRS,
            mmES_NUM_AVAIL_VGPRS,
            mmGS_NUM_AVAIL_VGPRS,
            mmVS_NUM_AVAIL_VGPRS,
            mmPS_NUM_AVAIL_VGPRS,
            mmCS_NUM_AVAIL_VGPRS
        };
        SetPseudoRegister(availVgprsKeys[uint32_t(hwStage)], value);
    }
}