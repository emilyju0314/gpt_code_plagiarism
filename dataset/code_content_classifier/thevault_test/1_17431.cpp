static bool FindResFile (const char* fName, std::string& outPath,
                         bool bRequired = true)
{
    std::string path = glob.resourceDir + fName;
    if (ExistsFile(path)) {
        outPath = std::move(path);
        return true;
    } else {
        if (bRequired) {
            LOG_MSG(logFATAL, ERR_RSRC_FILE_UNAVAIL,
                    fName, glob.resourceDir.c_str());
        }
        return false;
    }
}