bool SectionShader::CompileShader(
    const std::string&  docFilename,      // [in] File name of parent document
    const Section*      pShaderInfo,      // [in] Shader info sections
    std::string*        pErrorMsg)        // [out] Error message
{
    bool result = false;
    switch (m_shaderType)
    {
    case Glsl:
    case Hlsl:
        {
            result = CompileGlsl(pShaderInfo, pErrorMsg);
            break;
        }
    case GlslFile:
    case HlslFile:
        {
            result = ReadFile(docFilename, fileName, false, &m_spvBin, &shaderSource, pErrorMsg);
            if (result)
            {
                CompileGlsl(pShaderInfo, pErrorMsg);
            }
            break;
        }
    case SpirvAsm:
        {
            result = AssembleSpirv(pErrorMsg);
            break;
        }
    case SpirvAsmFile:
        {
            result = ReadFile(docFilename, fileName, false, &m_spvBin, &shaderSource, pErrorMsg);
            if (result)
            {
                AssembleSpirv(pErrorMsg);
            }
            break;
        }
    case SpirvFile:
        {
            result = ReadFile(docFilename, fileName, true, &m_spvBin, &shaderSource, pErrorMsg);
            break;
        }
    default:
        {
            VFX_NEVER_CALLED();
            break;
        }
    }
    return result;
}