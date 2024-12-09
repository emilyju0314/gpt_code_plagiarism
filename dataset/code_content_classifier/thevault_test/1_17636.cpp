HRESULT ExeUnregisterServer()
{
    HRESULT hr = S_OK;

    //  Unregister service 
    HRESULT hrTemp = UnregisterService(SERVICE_NAME);
    if (FAILED(hrTemp))
    {
        hr = hrTemp;
        printf("Failed to unregister service, hr = %08X\n", hr);
    }

    //  Unregister AppID 
    hrTemp = UnregisterAppID(SERVICE_APPID);
    if (FAILED(hrTemp))
    {
        hr = hrTemp;
        printf("Failed to unregister AppID, hr = %08X\n", hr);
    }
    
    //  Loop through the global classes table to unregister each class.
    //  Do not bail on failures, continue to unregister whatever we had registered.
    for (int i = 0; i < ARRAYSIZE(g_Classes); ++i)
    {
        hrTemp = UnregisterClass(g_Classes[i].rclsid);
        if (FAILED(hrTemp))
        {
            hr = hrTemp;
            printf("Failed to unregister class %ls, hr = %08X\n", g_Classes[i].pszName, hr);
        }
    }

    return hr;
}