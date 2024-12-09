CODK_CpuReadData::CODK_CpuReadData(long      nBytes, // Size, in bytes, of the data buffer
                                   ODK_BYTE *data)   // Pointer to the data buffer
    : m_nBytes(0), 
      m_data(0)								   
{
    SetBuffer(nBytes, data);
}