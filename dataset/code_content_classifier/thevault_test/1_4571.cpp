ShaderStage PipelineShaders::GetShaderStage(
    const Function* pFunc  // [in] Function to look up
    ) const
{
    auto entryMapIt = m_entryPointMap.find(pFunc);
    if (entryMapIt == m_entryPointMap.end())
    {
        return ShaderStageInvalid;
    }
    return entryMapIt->second;
}