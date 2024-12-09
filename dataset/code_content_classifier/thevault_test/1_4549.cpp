void ConfigBuilderBase::SetPipelineHash()
{
    auto hash64 = m_pContext->GetPiplineHashCode();
    if (GeneratingMsgPack())
    {
        auto pipelineHashNode = m_pipelineNode[Util::Abi::PipelineMetadataKey::InternalPipelineHash].getArray(true);
        pipelineHashNode[0] = m_document->getNode(hash64);
        pipelineHashNode[1] = m_document->getNode(0U);
    }
    else
    {
        SetPseudoRegister(mmPIPELINE_HASH_LO, uint32_t(hash64));
        SetPseudoRegister(mmPIPELINE_HASH_HI, uint32_t(hash64 >> 32));
    }
}