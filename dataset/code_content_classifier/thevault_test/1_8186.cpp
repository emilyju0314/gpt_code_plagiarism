bool CODK_CpuReadData::ReadUINT64(const long  byteOffset,  // Buffer index to the data
                                  ODK_UINT64 &value) const // Variable to store the read value
{
    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + ODK_SIZEBIT64) > m_nBytes))
    {
        return false;
    }

    // Read, convert, and return the data
    ODK_UINT64 qword = reinterpret_cast<ODK_UINT64&>(m_data[byteOffset]);
    value = (((qword & 0x00000000000000FFULL) << 56) |
             ((qword & 0x000000000000FF00ULL) << 40) |
             ((qword & 0x0000000000FF0000ULL) << 24) |
             ((qword & 0x00000000FF000000ULL) <<  8) |
             ((qword & 0x000000FF00000000ULL) >>  8) |
             ((qword & 0x0000FF0000000000ULL) >> 24) |
             ((qword & 0x00FF000000000000ULL) >> 40) |
             ((qword & 0xFF00000000000000ULL) >> 56));

    return true;
}