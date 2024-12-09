inline void BitsAlpha64(uint64 n, char* s)
{
    for (int i = 0; n != 0; n >>= 1, i++)
    {
        if (n & 1)
        {
            *s++ = i < 32 ? static_cast<char>(i + 'z' - 31) : static_cast<char>(i + 'Z' - 63);
        }
    }
    *s++ = '\0';
}