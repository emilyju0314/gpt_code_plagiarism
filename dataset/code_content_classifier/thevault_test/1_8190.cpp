bool CODK_CpuReadData::ReadS7LTIME_OF_DAY(const long  byteOffset,  // Offset to begin reading
                                          ODK_UINT64 &value) const // 64-bit long time of day value read
{
    if (!ReadUINT64(byteOffset, value))
    {
        return false;
    }

    return (sm_maxLTOD >= value);
}