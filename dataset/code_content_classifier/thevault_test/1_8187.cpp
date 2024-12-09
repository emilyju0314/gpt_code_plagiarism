bool CODK_CpuReadData::ReadS7BOOL(const long  byteOffset,  // Buffer index to the data
                                  int         bitNo,       // Bit number within the byte to read
                                  bool       &value) const // Variable to store the read value
{
    ODK_UINT8 temp;

    // Verify valid bit index
    if ((bitNo < 0) || (bitNo > 7))
    {
        return false;
    }

    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + ODK_SIZEBIT8) > m_nBytes))
    {
        return false;
    }

    // read the byte containing the bit
    if (!ReadUINT8(byteOffset, temp))
    {
        return false;
    }

    // Shift the bit to the first location
    temp = static_cast<ODK_UINT8>(temp >> bitNo);

    // Isolate the value
    if ((temp & 1) == 1)
    {
        value = true;
    }
    else
    {
        value = false;
    }
    return true;
}