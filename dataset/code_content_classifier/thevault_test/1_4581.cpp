Section* Section::CreateSection(
    const char* pSectionName)    // [in] Section name
{
    auto it = m_sectionInfo.find(pSectionName);

    VFX_ASSERT(it->second.type != SectionTypeUnset);

    Section* pSection = nullptr;
    switch (it->second.type)
    {
    case SectionTypeResult:
        pSection = new SectionResult();
        break;
    case SectionTypeBufferView:
        pSection = new SectionBufferView();
        break;
    case SectionTypeVertexState:
        pSection = new SectionVertexState();
        break;
    case SectionTypeDrawState:
        pSection = new SectionDrawState();
        break;
    case SectionTypeImageView:
        pSection = new SectionImageView();
        break;
    case SectionTypeSampler:
        pSection = new SectionSampler();
        break;
    case SectionTypeVersion:
        pSection = new SectionVersion();
        break;
    case SectionTypeCompileLog:
        pSection = new SectionCompileLog();
        break;
    case SectionTypeGraphicsState:
        pSection = new SectionGraphicsState();
        break;
    case SectionTypeComputeState:
        pSection = new SectionComputeState();
        break;
    case SectionTypeVertexInputState:
        pSection = new SectionVertexInput();
        break;
    case SectionTypeVertexShaderInfo:
    case SectionTypeTessControlShaderInfo:
    case SectionTypeTessEvalShaderInfo:
    case SectionTypeGeometryShaderInfo:
    case SectionTypeFragmentShaderInfo:
    case SectionTypeComputeShaderInfo:
        pSection = new SectionShaderInfo(it->second.type);
        break;
    case SectionTypeVertexShader:
    case SectionTypeTessControlShader:
    case SectionTypeTessEvalShader:
    case SectionTypeGeometryShader:
    case SectionTypeFragmentShader:
    case SectionTypeComputeShader:
        pSection = new SectionShader(it->second);
        break;
    default:
        VFX_NEVER_CALLED();
        break;
    }

    return pSection;
}