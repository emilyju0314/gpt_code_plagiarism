std::string CSFTP::readLink(const std::string &linkPath)
    {
        std::string finalPath;
        char *file;
        file = sftp_readlink(m_sftp, linkPath.c_str());
        if (file == NULL)
        {
            throw Exception(*this, __func__);
        }
        finalPath.assign(&file[0], &file[std::strlen(file)]);
        free(file);
        return (finalPath);
    }