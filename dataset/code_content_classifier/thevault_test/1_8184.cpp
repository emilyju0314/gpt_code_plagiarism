bool CODK_CpuReadData::ReadUINT16(const long  byteOffset,  // Buffer index to the data
                                  ODK_UINT16 &value) const // Variable to store the read value
{
    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + ODK_SIZEBIT16) > m_nBytes))
    {
        return false;
    }

    // Read, convert, and return the data
    ODK_UINT16 word = reinterpret_cast<ODK_UINT16&>(m_data[byteOffset]);
    value = (((word & 0x00FFU) << 8) |
             ((word & 0xFF00U) >> 8));

    return true;
}