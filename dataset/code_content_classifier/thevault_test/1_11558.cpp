static void makeRemotePath(CSCP &scpServer, const std::string &remotePath, const CSCP::FilePermissions permissions)
    {
        std::vector<std::string> pathComponents;
        std::filesystem::path currentPath{std::string(1, kServerPathSep)};
        boost::split(pathComponents, remotePath, boost::is_any_of(std::string(1, kServerPathSep)));
        for (auto directory : pathComponents)
        {
            if (!directory.empty())
            {
                scpServer.pushDirectory(directory, permissions);
            }
        }
    }