std::uint16_t PJWHash16(const char *pc)
{
    std::uint16_t h = 0, high;
    const unsigned char* s = reinterpret_cast<const unsigned char*>(pc);
    while (*s)
    {
        h <<= 2;                    // shift by 2 bits only, not 4
        h += *s++;
        high = h & 0xC000;          // pick the upper 2 bits only, not 4
        if (high)
            h ^= high >> 14;
        h &= ~high;
    }
    return h;
}