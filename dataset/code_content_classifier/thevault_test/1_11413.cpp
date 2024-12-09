void CRedirect::change(const std::string &outfileName, const char *mode)
    {
        FILE *ignore = std::freopen(outfileName.c_str(), mode, m_savedStdOutErr);
        (void)ignore;
    }