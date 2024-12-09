ODK_INT8 CODK_CpuReadData::GetBCD(const ODK_UINT8 value) const
{
    if ((value & 0x0F) > 9) return -1;
    if (((value >> 4) & 0x0F) > 9) return -1;

    return ((value >> 4) * 10) + (value & 0x0F);
}