inline uint32_t ReadU24_LE_Min4Bytes(const uint8_t* data)
{
#ifdef TONK_CPP_SDK_ALIGNED_ACCESSES
    return ReadU24_LE(data);
#else
    return *(uint32_t*)data & 0xFFFFFF;
#endif
}