HRESULT ExeRegisterServer()
{
    //  Register our service first
    HRESULT hr = RegisterService(SERVICE_NAME, SERVICE_DISPLAY_NAME);
    if (SUCCEEDED(hr))
    {
        //  Register the AppID
        hr = RegisterAppID(SERVICE_APPID, SERVICE_DISPLAY_NAME, SERVICE_NAME);
        if (SUCCEEDED(hr))
        {
            //  Loop through the global classes table to register each class.
            //  Bail if we fail to register any of the classes.
            for (int i = 0; (i < ARRAYSIZE(g_Classes)) && SUCCEEDED(hr); ++i)
            {
                hr = RegisterClass(g_Classes[i].rclsid, 
                                   g_Classes[i].pszName,
                                   SERVICE_APPID);
                if (FAILED(hr))
                {
                    printf("Failed to register class %ls, hr = %08X\n", g_Classes[i].pszName, hr);
                }
            }
        }
        else
        {
            printf("Failed to register AppID, hr = %08X\n", hr);
        }
    }
    else
    {
        printf("Failed to register service, hr = %08X\n", hr);
    }

    // Unregister everything if any of the registration process fails.
    if (FAILED(hr))
    {
        (void)ExeUnregisterServer();
    }

    return hr;
}