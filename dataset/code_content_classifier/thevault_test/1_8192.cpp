bool CODK_CpuReadData::ReadS7DTL(long     byteOffset, // Offset to begin reading
                                 ODK_DTL &dtl) const  // DTL structure read
{
    // Verify offset is within data area
    if ((byteOffset < 0) || ((byteOffset + static_cast<long>(sizeof(dtl))) > m_nBytes))
    {
        return false;
    }

    // year
    ReadUINT16(byteOffset, dtl.Year);
    byteOffset += ODK_SIZEBIT16;
    // month
    ReadUINT8(byteOffset, dtl.Month);
    byteOffset += ODK_SIZEBIT8;
    // day
    ReadUINT8(byteOffset, dtl.Day);
    byteOffset += ODK_SIZEBIT8;
    // weekday
    ReadUINT8(byteOffset, dtl.Weekday);
    byteOffset += ODK_SIZEBIT8;
    // hour
    ReadUINT8(byteOffset, dtl.Hour);
    byteOffset += ODK_SIZEBIT8;
    // minute
    ReadUINT8(byteOffset, dtl.Minute);
    byteOffset += ODK_SIZEBIT8;
    // second
    ReadUINT8(byteOffset, dtl.Second);
    byteOffset += ODK_SIZEBIT8;
    // nanosecond
    ReadUINT32(byteOffset, dtl.Nanosecond);

	return CheckS7DTL(dtl);
}