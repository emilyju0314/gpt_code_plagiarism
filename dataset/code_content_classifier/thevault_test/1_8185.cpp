bool CODK_CpuReadData::ReadUINT32(const long   byteOffset, // Buffer index to the data
                                  ODK_UINT32 &value) const // Variable to store the read value
{
    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + ODK_SIZEBIT32) > m_nBytes))
    {
        return false;
    }

    // Read, convert, and return the data
    ODK_UINT32 dword = reinterpret_cast<ODK_UINT32&>(m_data[byteOffset]);
    value = (((dword & 0x000000FFUL) << 24) |
             ((dword & 0x0000FF00UL) <<  8) |
             ((dword & 0x00FF0000UL) >>  8) |
             ((dword & 0xFF000000UL) >> 24));

    return true;
}