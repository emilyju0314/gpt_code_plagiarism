LONG GetCurrentEffectsSetting(IPropertyStore* properties, PROPERTYKEY pkeyEnable, GUID processingMode)
{
    HRESULT hr;
    BOOL enabled;
    PROPVARIANT var;

    PropVariantInit(&var);

    // Get the state of whether channel swap MFX is enabled or not. 

    // Check the master disable property defined by Windows
    hr = properties->GetValue(PKEY_AudioEndpoint_Disable_SysFx, &var);
    enabled = (SUCCEEDED(hr)) && !((var.vt == VT_UI4) && (var.ulVal != 0));

    PropVariantClear(&var);

    // Check the APO's enable property, defined by this APO.
    hr = properties->GetValue(pkeyEnable, &var);
    enabled = enabled && ((SUCCEEDED(hr)) && ((var.vt == VT_UI4) && (var.ulVal != 0)));

    PropVariantClear(&var);

    enabled = enabled && !IsEqualGUID(processingMode, AUDIO_SIGNALPROCESSINGMODE_RAW);

    return (LONG)enabled;
}