static bool ShouldUseColor(bool stdout_is_tty)
    {
        const char* const gtest_color = testing::GTEST_FLAG(color).c_str();

        if (azstricmp(gtest_color, "auto") == 0)
        {
            // On non-Windows platforms, we rely on the TERM variable.
            
            return stdout_is_tty && Platform::TerminalSupportsColor();
        }

        return azstricmp(gtest_color, "yes") == 0 || azstricmp(gtest_color, "true") == 0 || azstricmp(gtest_color, "t") == 0 || strcmp(gtest_color, "1") == 0;
    }