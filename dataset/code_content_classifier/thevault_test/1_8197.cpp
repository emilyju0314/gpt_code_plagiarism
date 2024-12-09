bool CODK_CpuReadData::CheckS7DateAndTime(const ODK_UINT64& value) const
{
    ODK_INT8 bcd;

    // check year
    bcd = GetBCD((value >> 56) & 0xFF);
    if (bcd < 0  ||  bcd > 99) return false;
    // check month
    bcd = GetBCD((value >> 48) & 0xFF);
    if (bcd < 1 || bcd > 12) return false;
    // check day
    bcd = GetBCD((value >> 40) & 0xFF);
    if (bcd < 1 || bcd > 31) return false;
    // check hour
    bcd = GetBCD((value >> 32) & 0xFF);
    if (bcd < 0 || bcd > 23) return false;
    // check minute
    bcd = GetBCD((value >> 24) & 0xFF);
    if (bcd < 0 || bcd > 59) return false;
    // check second
    bcd = GetBCD((value >> 16) & 0xFF);
    if (bcd < 0 || bcd > 59) return false;
    // check millisecond
    bcd = GetBCD((value >> 8) & 0xFF);
    if (bcd < 0 || bcd > 99) return false;
    bcd = GetBCD((value >> 4) & 0x0F);
    if (bcd < 0 || bcd > 9) return false;
    // check weekday
    bcd = GetBCD(value & 0x0F);
    if (bcd < 1 || bcd > 7) return false;

    return true;
}