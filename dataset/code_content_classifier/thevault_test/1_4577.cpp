bool GraphicsContext::GetShaderWgpMode(
    ShaderStage shaderStage // Shader stage
    ) const
{
    if (shaderStage == ShaderStageCopyShader)
    {
        // Treat copy shader as part of geometry shader
        shaderStage = ShaderStageGeometry;
    }

    LLPC_ASSERT(shaderStage < ShaderStageGfxCount);

    bool wgpMode = false;

    switch (shaderStage)
    {
    case ShaderStageVertex:
        wgpMode = m_pPipelineInfo->vs.options.wgpMode;
        break;
    case ShaderStageTessControl:
        wgpMode = m_pPipelineInfo->tcs.options.wgpMode;
        break;
    case ShaderStageTessEval:
        wgpMode = m_pPipelineInfo->tes.options.wgpMode;
        break;
    case ShaderStageGeometry:
        wgpMode = m_pPipelineInfo->gs.options.wgpMode;
        break;
    case ShaderStageFragment:
        wgpMode = m_pPipelineInfo->fs.options.wgpMode;
        break;
    default:
        LLPC_NEVER_CALLED();
        break;
    }

    return wgpMode;
}