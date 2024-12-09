int FindAnnexBStart(const uint8_t* data, int bytes)
{
    bytes -= 2;
    for (int i = 0; i < bytes; ++i)
    {
        if (data[i] == 0) {
            if (data[i + 1] == 0) {
                if (data[i + 2] == 1) {
                    return i;
                }
            }
        }
    }
    return -1;
}