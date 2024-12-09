CRedirect::CRedirect(std::FILE *stdStream, const std::string &outfileName, const char *mode)
    {
        FILE *ignore = std::freopen(outfileName.c_str(), mode, stdStream);
        (void)ignore;
    }