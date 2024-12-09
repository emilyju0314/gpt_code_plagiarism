bool Section::GetMemberType(
    uint32_t     lineNum,         // Line No.
    const char*  pMemberName,     // [in]  Member string name
    MemberType*  pValueType,      // [out] Member data type.
    std::string* pErrorMsg)       // [out] Error message
{
    bool result = false;
    for (uint32_t i = 0; i < m_tableSize; ++i)
    {
        if ((m_pMemberTable[i].pMemberName != nullptr) && strcmp(pMemberName, m_pMemberTable[i].pMemberName) == 0)
        {
            result = true;

            if (pValueType != nullptr)
            {
                *pValueType = m_pMemberTable[i].memberType;
            }

            break;
        }
    }

    if (result == false)
    {
        PARSE_WARNING(*pErrorMsg, lineNum, "Invalid member name: %s", pMemberName);
    }

    return result;
}