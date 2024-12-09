bool CODK_CpuReadData::ReadS7TIME_OF_DAY(const long  byteOffset,  // Offset to begin reading
                                         ODK_UINT32 &value) const // 32-bit time of day value read
{
    if (!ReadUINT32(byteOffset, value))
    {
        return false;
    }

    return (sm_maxTOD >= value);
}