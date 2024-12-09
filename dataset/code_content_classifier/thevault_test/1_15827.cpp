void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    HWND hwnd;
    window = make<MainWindow>();
    window.as<IWindowNative>()->get_WindowHandle(&hwnd);
    window.Activate();

    // The Window object doesn't have Width and Height properties in WInUI 3 Desktop yet.
    // To set the Width and Height, you can use the Win32 API SetWindowPos.
    // Note, you should apply the DPI scale factor if you are thinking of dpi instead of pixels.
    setWindowSize(hwnd, 800, 600);
}