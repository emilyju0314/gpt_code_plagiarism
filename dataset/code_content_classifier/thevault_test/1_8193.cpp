bool CODK_CpuReadData::ReadS7STRING_LEN(const long  byteOffset,   // Buffer index to the data
                                        ODK_UINT8  &maxLen,       // Variable to store the maximum length of the string
                                        ODK_UINT8  &curLen) const // Variable to store the current length of the string
{
    if (ReadUINT8(byteOffset, maxLen)  &&  ReadUINT8(byteOffset + sizeof(ODK_CHAR), curLen))
    {
        return true;
    }

    return false;
}