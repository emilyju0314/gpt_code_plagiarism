STDAPI DllRegisterServer()
{
    HRESULT hr = S_OK;

    //  Loop through the global classes table to register each class.
    //  Bail out when we fail to register any of the classes.
    for (int i = 0; ((i < ARRAYSIZE(g_Classes)) && SUCCEEDED(hr)); ++i)
    {
        hr = _RegisterClass(g_Classes[i].rclsid, 
                            g_Classes[i].pwszName,
                            g_Classes[i].pwszThreadModel,
                            g_Classes[i].pwszAppId);
    }

    // Register the AppId that will enable the objects to run as out of proc components inside a surrogate host.
    if (SUCCEEDED(hr))
    {
        hr = _RegisterAppId(APPID_LOCALSERVER);
    }

    // If anything fails at all, unregister whatever registration we might have done so far.
    if (FAILED(hr))
    {
        (void)DllUnregisterServer();
    }

    return hr;
}