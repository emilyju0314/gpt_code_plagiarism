bool CopyFileIfNewer(const std::string& source, const std::string& destDir)
{
    // Check source
    struct stat bufSource;
    if (stat(source.c_str(), &bufSource) != 0)
        // source doesn't exist
        return false;               
    size_t nPos = source.find_last_of("/\\");       // find beginning of file name
    if (nPos == std::string::npos)
        return false;

    // Check destination directory
    if (destDir.empty())
        return false;
    std::string target = destDir;
    if (target.back() == '\\' ||
        target.back() == '/')                       // remove traling (back)slash
        target.pop_back();
    if (!CreateDir(target))
        // directory does not exist and could be be created
        return false;

    // Check target file
    target += source.substr(nPos);
    struct stat bufTarget;
    if (stat(target.c_str(), &bufTarget) == 0)                  // file exists?
    {
        // is target not older than source?
        if (bufTarget.st_mtime >= bufSource.st_mtime)
            // Skip copy, all good already
            return true;
    }

    // Target dir exists, target file does not or is older -> Do copy!
    // https://stackoverflow.com/a/10195497
    std::ifstream src(source, std::ios::binary);
    std::ofstream dst(target, std::ios::binary | std::ios::trunc);
    if (!src || !dst)
        return false;
    dst << src.rdbuf();

    // all good?
    if (src.good() && dst.good()) {
        LOG_MSG(logINFO, "Copied %s to %s", source.c_str(), destDir.c_str());
        return true;
    }
    else {
        LOG_MSG(logERR, "FAILED copying %s to %s", source.c_str(), destDir.c_str());
        return true;
    }
}