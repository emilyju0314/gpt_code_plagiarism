void UpdateTimesEGLConfigUsed(int threadid)
{
    const TraceSurface *traceSurf = GetCurTraceSurface(threadid);
    if (traceSurf && traceSurf->mEGLSurf)
    {
        timesEGLConfigIdUsed[threadid][traceSurf->mEGLConfigId]++;
    }
}