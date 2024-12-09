void CODK_CpuReadData::SetBuffer(long     nBytes, 
                                 ODK_BYTE data[])
{
    if (0 == data)
    {
        m_nBytes = 0;
    }
    else
    {
        m_nBytes = nBytes;
    }
    m_data = data;
}