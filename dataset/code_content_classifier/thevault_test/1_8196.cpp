bool CODK_CpuReadData::CheckS7S5Time(const ODK_UINT16& value) const
{
    ODK_INT8 bcd;

    // check time value
    bcd = GetBCD(value & 0xFF);
    if (bcd < 0  ||  bcd > 99) return false;
    bcd = GetBCD((value >> 8) & 0x0F);
    if (bcd < 0  ||  bcd > 9) return false;
    // check time base is always valid (two bits, four states)

    return true;
}