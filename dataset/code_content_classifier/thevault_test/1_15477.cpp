TABFieldType MIFFile::GetNativeFieldType(int nFieldId)
{
    if ( m_poDefn==NULL || m_paeFieldType==NULL ||
         nFieldId < 0 || nFieldId >= m_poDefn->GetFieldCount())
        return TABFUnknown;

    return m_paeFieldType[nFieldId];
}