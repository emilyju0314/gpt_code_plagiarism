bool SectionShader::IsShaderSourceSection()
{
    bool ret = false;
    switch (m_shaderType)
    {
    case Glsl:
    case SpirvAsm:
        ret = true;
        break;
    default:
        ret = false;
        break;
    }
    return ret;
}