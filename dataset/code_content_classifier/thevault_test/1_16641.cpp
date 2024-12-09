static HWND createDummyWindow()
{
    registerDummyWindowClass();
    return ::CreateWindowW(dummyWindowClass, 0, WS_POPUP, 0, 0, 10, 10, 0, 0, instanceHandle(), 0);
}