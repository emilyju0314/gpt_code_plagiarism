std::string FROMPOSIX (const std::string& p)
{
    // no actual conversion if XPLM_USE_NATIVE_PATHS is activated
    if (XPLMIsFeatureEnabled("XPLM_USE_NATIVE_PATHS"))
        return p;
    else {
        char hfs[1024];
        if (Posix2HFSPath(p.c_str(), hfs, sizeof(hfs)))
            return hfs;
        else
            return p;
    }
}