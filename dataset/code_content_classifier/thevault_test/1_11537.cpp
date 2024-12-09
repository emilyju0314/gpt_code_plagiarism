static void makeRemotePath(CSFTP &sftpServer, const std::string &remotePath, const CSFTP::FilePermissions &permissions)
    {
        std::vector<std::string> pathComponents;
        CPath currentPath{""};
        boost::split(pathComponents, remotePath, boost::is_any_of(std::string(1, kServerPathSep)));
        for (auto directory : pathComponents)
        {
            currentPath.join(directory);
            if (!directory.empty())
            {
                if (!fileExists(sftpServer, currentPath.toString()))
                {
                    sftpServer.createDirectory(currentPath.toString(), permissions);
                }
            }
        }
    }