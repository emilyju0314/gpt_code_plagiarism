bool CODK_CpuReadData::ReadUINT8(const long  byteOffset,   // Buffer index to the data
                                 ODK_UINT8  &value) const  // Variable to store the read value
{
    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + ODK_SIZEBIT8) > m_nBytes))
    {
        return false;
    }

    // Read, convert, and return the data
    value = reinterpret_cast<ODK_UINT8&>(m_data[byteOffset]);

    return true;
}