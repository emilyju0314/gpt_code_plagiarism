void ConfigBuilderBase::SetUserDataLimit()
{
    if (GeneratingMsgPack())
    {
        m_pipelineNode[Util::Abi::PipelineMetadataKey::UserDataLimit] = m_document->getNode(m_userDataLimit);
    }
    else
    {
        SetPseudoRegister(mmUSER_DATA_LIMIT, m_userDataLimit);
    }
}