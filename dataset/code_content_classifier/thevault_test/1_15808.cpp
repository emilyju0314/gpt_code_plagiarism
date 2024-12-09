Utility::LocIndString GetDefaultUserAgent()
    {
        std::ostringstream strstr;
        strstr <<
            "winget-cli"
            " WindowsPackageManager/" << GetClientVersion() <<
            " DesktopAppInstaller/" << GetPackageVersion();
        return Utility::LocIndString{ strstr.str() };
    }