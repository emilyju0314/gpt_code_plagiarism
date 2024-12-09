void VerifyAllEndpointsPluggedIn()
{
    wil::com_ptr_nothrow<IMMDeviceEnumerator>    spEnumerator;
    wil::com_ptr_nothrow<IMMDeviceCollection>    spEndpoints;
    UINT                                         cDevices = 0;

    SetVerifyOutput verifySettings(VerifyOutputSettings::LogOnlyFailures);
    DisableVerifyExceptions disable;

    VERIFY_SUCCEEDED(::CoInitializeEx(NULL, COINIT_MULTITHREADED));

    // Create IMMDevice Enumerator
    VERIFY_SUCCEEDED(CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void **)&spEnumerator));

    // Enumerate all unplugged endpoints
    VERIFY_SUCCEEDED(spEnumerator->EnumAudioEndpoints(eAll, DEVICE_STATE_UNPLUGGED, &spEndpoints));
    VERIFY_SUCCEEDED(spEndpoints->GetCount(&cDevices));

    if (!VERIFY_IS_TRUE(cDevices == 0))
    {
        Log::Comment(L"Following unplugged audio device(s) found, please plug in unplugged device(s).");

        for (UINT i = 0; i < cDevices; i++) {
            wil::com_ptr_nothrow<IMMDevice> spEndpoint;
            wil::unique_cotaskmem_string id;
            wil::unique_cotaskmem_string friendlyName;

            VERIFY_SUCCEEDED(spEndpoints->Item(i, &spEndpoint));
            VERIFY_SUCCEEDED(spEndpoint->GetId(&id));
            VERIFY_SUCCEEDED(GetEndpointFriendlyName(spEndpoint.get(), &friendlyName));

            Log::Comment(String().Format(L"Device: %s (%s) is unplugged.", friendlyName.get(), id.get()));
        }
    }
}