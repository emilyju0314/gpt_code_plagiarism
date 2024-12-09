HRESULT StartFactories()
{
    HRESULT hr = S_OK;
    for (int i = 0; (i < ARRAYSIZE(g_Classes)) && SUCCEEDED(hr); ++i)
    {        
        hr = CClassFactory_CreateInstance(g_Classes[i].pfnCreateInstance,
                                          IID_IUnknown,
                                          (LPVOID*) &g_Classes[i].pUnknown);
        if (SUCCEEDED(hr))
        {
            hr = CoRegisterClassObject(g_Classes[i].rclsid,
                                       g_Classes[i].pUnknown,
                                       CLSCTX_LOCAL_SERVER,
                                       REGCLS_MULTIPLEUSE,
                                       &g_Classes[i].dwRegister);

            if (FAILED(hr))
            {
                g_Classes[i].pUnknown->Release();
                g_Classes[i].pUnknown = nullptr;
            }
        }
    }

    if (FAILED(hr))
    {
        (void)StopFactories();
    }

    return hr; 
}