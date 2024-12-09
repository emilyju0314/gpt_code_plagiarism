std::string CSFTP::canonicalizePath(const std::string &pathName)
    {
        std::string finalPath;
        char *path;
        path = sftp_canonicalize_path(m_sftp, pathName.c_str());
        if (path == NULL)
        {
            throw Exception(*this, __func__);
        }
        finalPath.assign(&path[0], &path[std::strlen(path)]);
        free(path);
        return (finalPath);
    }