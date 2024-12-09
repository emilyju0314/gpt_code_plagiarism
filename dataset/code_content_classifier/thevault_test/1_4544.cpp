void ConfigBuilderBase::SetNumAvailSgprs(
    Util::Abi::HardwareStage hwStage, // Hardware shader stage
    uint32_t value)                   // Number of available SGPRs
{
    if (GeneratingMsgPack())
    {
        auto hwShaderNode = GetHwShaderNode(hwStage);
        hwShaderNode[Util::Abi::HardwareStageMetadataKey::SgprLimit] = hwShaderNode.getDocument()->getNode(value);
    }
    else
    {
        static const uint32_t availSgprsKeys[] =
        {
            // In Util::Abi::HardwareStage order
            mmLS_NUM_AVAIL_SGPRS,
            mmHS_NUM_AVAIL_SGPRS,
            mmES_NUM_AVAIL_SGPRS,
            mmGS_NUM_AVAIL_SGPRS,
            mmVS_NUM_AVAIL_SGPRS,
            mmPS_NUM_AVAIL_SGPRS,
            mmCS_NUM_AVAIL_SGPRS
        };
        SetPseudoRegister(availSgprsKeys[uint32_t(hwStage)], value);
    }
}