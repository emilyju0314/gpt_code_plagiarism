STDAPI DllUnregisterServer()
{
    HRESULT hr = S_OK;
    
    //  Loop through the global classes table to unregister each class.
    //  Do not bail on failures, continue to unregister whatever we had registered.    
    for (int i = 0; i < ARRAYSIZE(g_Classes); ++i)
    {
        HRESULT hrUnregisterClass = _UnregisterClass(g_Classes[i].rclsid);
        if (FAILED(hrUnregisterClass))
        {
            hr = hrUnregisterClass;
        }
    }

    // Unregister the AppId.
    HRESULT hrUnregisterAppId = _UnregisterAppId(APPID_LOCALSERVER);
    if (FAILED(hrUnregisterAppId))
    {
        hr = hrUnregisterAppId;
    }

    return hr;
}