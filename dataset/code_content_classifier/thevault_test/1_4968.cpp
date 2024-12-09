void
TestPerformanceCounter()
{
    static LARGE_INTEGER nCount1, nCount2;
    static int rgn[1000000];
    static unsigned n, m;
    BOOL bResult;
    int i;

    printf("Performance counter jitter:\n");
    bResult = QueryPerformanceCounter(&nCount1);
    for (i = 0; i < 100000; i++) {
        Sleep(1L);
        bResult = QueryPerformanceCounter(&nCount2);
        n = nCount2.QuadPart - nCount1.QuadPart;
        nCount1 = nCount2;
        if (n >= 0 && n < 1000000)
            rgn[n]++;
    }
    printf("%d\n", n);
    m = 1000000/20000;
    for (i = 30000; i < 40000; i++) {
        if (i % m == 0)
            n = 0;
        if (i % m == m-1)
            printf("%7d %5d\n", i+1, n);
        n += rgn[i];
    }
}