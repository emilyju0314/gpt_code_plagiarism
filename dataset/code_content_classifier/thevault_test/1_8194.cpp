bool CODK_CpuReadData::ReadS7STRING(const long  byteOffset,   // Buffer index to the data
                                    ODK_UINT8   readMax,      // Maximum characters to read including the string terminating zero
                                    ODK_CHAR*   string) const // Buffer to receive the string characters
{
    ODK_UINT8  curLen  = 0; // Current length of the string
    ODK_UINT8  maxLen  = 0; // Maximum length of the string
    ODK_UINT8  stop    = 0; // Maximum bytes to read
    ODK_UINT16 strData = static_cast<ODK_UINT16>(byteOffset + ODK_SIZEBIT16); // Offset to the string data (characters)

    // must receive a valid buffer for the string  AND  must have space for 1 character and the string terminator
    if (0 == string  ||  readMax < 2)
    {
        return false;
    }

    // Get the current string length
    if (! ReadS7STRING_LEN(byteOffset, maxLen, curLen))
    {
        return false;
    }

    // Verify offset not out of bounds
    if ((byteOffset < 0) || (byteOffset + static_cast<long>(maxLen) + ODK_SIZEBIT16 > m_nBytes))
    {
        return false;
    }

    // Get the value to read to
    if (curLen < readMax)
    {
        stop = curLen;
    }
    else
    {
        stop = static_cast<ODK_UINT8>(readMax - 1);
    }

    // Read the value
    memcpy(string, &(m_data[strData]), stop);
    string[stop] = '\0';  // terminate the string

    return true;
}