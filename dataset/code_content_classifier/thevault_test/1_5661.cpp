BOOL DI_Open(DI_mode_e DI_mode)
{
    DirectInput8Create(GetModuleHandle(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, 0);
    dinput->EnumDevices(DI8DEVCLASS_GAMECTRL, DI_EnumDevicesCallback, (void*)DI_mode, DIEDFL_ALLDEVICES);

    if (xinputCount > 0) {
        DI_Close();
        wprintf_s(L"XInput (x360).\n");
        return XI_Open(xinputCount);
    }
    if (deviceCount == 0) {
        wprintf_s(L"Error: There are no Controllers connected.\n");
        return FALSE;
    }
    wprintf_s(L"DirectInput (DS4).\n");

    if (deviceCount != 1) {
        wprintf_s(L"Error: There is More than 1 DirectInput Controller connected.\n");
        return FALSE;
    }
    DIJOYSTATE state;
    if (devices[0]->GetDeviceState(sizeof(state), &state) != DI_OK) {
        wprintf_s(L"Error: Cannot determine the DirectInput Controller State.\n");
        return FALSE;
    }
    if (state.lX != LX || state.lY != LY) {
        wprintf_s(L"Error: The DirectInput Controller is NOT centered.\n");
        return FALSE;
    }
    return TRUE;
}