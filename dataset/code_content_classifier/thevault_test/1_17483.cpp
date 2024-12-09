std::string TOPOSIX (const std::string& p)
{
    // no actual conversion if XPLM_USE_NATIVE_PATHS is activated
    if (XPLMIsFeatureEnabled("XPLM_USE_NATIVE_PATHS"))
        return p;
    else {
        char posix[1024];
        if (HFS2PosixPath(p.c_str(), posix, sizeof(posix)))
            return posix;
        else
            return p;
    }
}