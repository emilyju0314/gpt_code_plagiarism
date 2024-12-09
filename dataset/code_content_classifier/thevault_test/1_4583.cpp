bool Section::GetPtrOfSubSection(
    uint32_t     lineNum,         // Line No.
    const char*  pMemberName,     // [in] Member name
    MemberType   memberType,      // Member type
    bool         isWriteAccess,   // Whether the sub section will be written
    uint32_t     arrayIndex,      // Array index
    Section**    ptrOut,          // [out] Pointer of sub section
    std::string* pErrorMsg)       // [out] Error message
{
    bool result = false;

    switch (memberType)
    {
    CASE_SUBSECTION(MemberTypeResultItem, SectionResultItem)
    CASE_SUBSECTION(MemberTypeVertexBufferBindingItem, SectionVertexBufferBinding)
    CASE_SUBSECTION(MemberTypeVertexAttributeItem, SectionVertexAttribute)
    CASE_SUBSECTION(MemberTypeSpecConstItem, SectionSpecConstItem)
    CASE_SUBSECTION(MemberTypeSpecConst, SectionSpecConst)
    CASE_SUBSECTION(MemberTypePushConstRange, SectionPushConstRange)
    CASE_SUBSECTION(MemberTypeVertexInputBindingItem, SectionVertexInputBinding)
    CASE_SUBSECTION(MemberTypeVertexInputAttributeItem, SectionVertexInputAttribute)
    CASE_SUBSECTION(MemberTypeVertexInputDivisorItem, SectionVertexInputDivisor)
    CASE_SUBSECTION(MemberTypeColorBufferItem, SectionColorBuffer)
    CASE_SUBSECTION(MemberTypeSpecEntryItem, SectionSpecEntryItem)
    CASE_SUBSECTION(MemberTypeResourceMappingNode, SectionResourceMappingNode)
    CASE_SUBSECTION(MemberTypeSpecInfo, SectionSpecInfo)
    CASE_SUBSECTION(MemberTypeDescriptorRangeValue, SectionDescriptorRangeValueItem)
    CASE_SUBSECTION(MemberTypePipelineOption, SectionPipelineOption)
    CASE_SUBSECTION(MemberTypeShaderOption, SectionShaderOption)
#if VKI_BUILD_GFX10
    CASE_SUBSECTION(MemberTypeNggState, SectionNggState)
#endif
        break;
    default:
        VFX_NEVER_CALLED();
        break;
    }

    return result;
}