Function* PipelineShaders::GetEntryPoint(
    ShaderStage shaderStage     // Shader stage
    ) const
{
    LLPC_ASSERT((uint32_t)shaderStage < ShaderStageCountInternal);
    return m_entryPoints[shaderStage];
}