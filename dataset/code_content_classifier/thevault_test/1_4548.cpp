void ConfigBuilderBase::SetSpillThreshold()
{
    if (GeneratingMsgPack())
    {
        m_pipelineNode[Util::Abi::PipelineMetadataKey::SpillThreshold] = m_document->getNode(m_spillThreshold);
    }
    else
    {
        SetPseudoRegister(mmSPILL_THRESHOLD, m_spillThreshold);
    }
}