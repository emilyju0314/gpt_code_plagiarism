SectionType Section::GetSectionType(
    const char* pSectionName)   // [in] Section name
{
    SectionType type = SectionTypeUnset;
    auto it = m_sectionInfo.find(pSectionName);
    if (it != m_sectionInfo.end())
    {
        type = it->second.type;
    }
    return type;
}