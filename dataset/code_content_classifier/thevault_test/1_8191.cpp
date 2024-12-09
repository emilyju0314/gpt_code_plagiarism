bool CODK_CpuReadData::ReadS7DATE_AND_TIME(long        byteOffset,  // Offset to begin reading
                                           ODK_UINT64 &value) const // Date and time in BCD format read
{
    if (!ReadUINT64(byteOffset, value))
    {
        return false;
    }

	return CheckS7DateAndTime(value);
}