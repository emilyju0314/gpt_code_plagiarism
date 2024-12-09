void Memory::GetPrimaryDeviceIndex(
    uint32_t  maxDevices,
    uint32_t  allocationMask,
    uint32_t* pIndex,
    bool*     pMultiInstance)
{
    if (Util::CountSetBits(allocationMask) > 1)
    {
        *pMultiInstance = true;
    }
    else
    {
        *pMultiInstance = false;
    }

    Util::BitMaskScanForward(pIndex, allocationMask);
}