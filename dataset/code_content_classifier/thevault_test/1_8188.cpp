bool CODK_CpuReadData::ReadS7S5TIME(const long  byteOffset,  // Offset to begin reading
                                    ODK_UINT16 &value) const // 16-bit time value read
{
    if (!ReadUINT16(byteOffset, value))
    {
        return false;
    }

    return CheckS7S5Time(value);
}