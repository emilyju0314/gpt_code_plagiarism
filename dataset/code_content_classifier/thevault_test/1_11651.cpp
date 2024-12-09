w32::rgs::Key sources ()
    {
        const ::WCHAR root[] =
            L"SYSTEM\\CurrentControlSet\\Services\\Log\\Application";
        return (w32::rgs::Key(w32::rgs::Key::machine(), root));
    }