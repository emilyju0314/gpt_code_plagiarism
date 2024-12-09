unsigned
ML_TrueRandomUnsigned()
{
    static LARGE_INTEGER nPerformanceCount;
    static unsigned n;
    BOOL bResult;
    int i;


    for (i = 0; i < 32; i += 8) {
        bResult = QueryPerformanceCounter(&nPerformanceCount);
        Sleep(1L);
        n = (n << 8) | (n >> 24);
        n ^= nPerformanceCount.LowPart;
    }
    return n;
}