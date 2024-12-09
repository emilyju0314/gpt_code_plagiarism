int  TABFile::GetFieldIndexNumber(int nFieldId)
{
    if (m_panIndexNo == NULL || nFieldId < 0 || 
        m_poDATFile== NULL || nFieldId >= m_poDATFile->GetNumFields())
        return 0;  // no index

    return m_panIndexNo[nFieldId];
}