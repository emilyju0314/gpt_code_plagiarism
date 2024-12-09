void BinAndMeta::saveAllEGLConfigs(EGLDisplay dpy)
{
    int cfgCnt = 0;

    _eglGetConfigs(dpy, NULL, 0, &cfgCnt);
    EGLConfig* cfgArray = new(nothrow) EGLConfig[cfgCnt];
    if (cfgArray == NULL)
    {
        DBG_LOG("malloc failed\n");
        os::abort();
    }
    else
    {
        EGLint numCfgsReturned = 0;
        _eglGetConfigs(dpy, cfgArray, cfgCnt, &numCfgsReturned);
        std::lock_guard<std::recursive_mutex> guard(gTraceOut->callMutex); // changing global EGL config state
        configIdToConfigAttribsMap.clear();
        configIdToConfigAttribsMap[0] = MyEGLAttribs();     // create an all-zero attribs for EGL_CONFIG_ID=0
        for (EGLint i = 0; i < cfgCnt; i++)
        {
            EGLint cfgId;
            _eglGetConfigAttrib(dpy, cfgArray[i], EGL_CONFIG_ID, &cfgId);
            configIdToConfigAttribsMap[cfgId] = GetEGLConfigValues(dpy,cfgArray[i]);
        }
        delete[] cfgArray;
    }
}