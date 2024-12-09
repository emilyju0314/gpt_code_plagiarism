CODK_CpuReadData::CODK_CpuReadData(const ODK_CLASSIC_DB *db) // Pointer to a classic db structure
    : m_nBytes(0), 
      m_data(0)
{
    SetBuffer(db->Len, (ODK_BYTE *)db->Data);
}