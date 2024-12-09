void putFile(CSSHSession &sshSession, const std::string &sourceFile, const std::string &destinationFile)
    {
        std::ifstream localFile;
        std::filesystem::file_status fileStatus;
        localFile.open(sourceFile, std::ios_base::in | std::ios_base::binary);
        if (!localFile)
        {
            throw std::system_error(errno, std::system_category());
        }
        fileStatus = std::filesystem::status(std::filesystem::path(sourceFile).parent_path().string());
        CSCP scpServer{sshSession, SSH_SCP_WRITE | SSH_SCP_RECURSIVE, std::string(1, kServerPathSep)};
        scpServer.open();
        if (std::filesystem::is_directory(sourceFile))
        {
            makeRemotePath(scpServer, std::filesystem::path(destinationFile).string(), (CSCP::FilePermissions)fileStatus.permissions());
        }
        else if (std::filesystem::is_regular_file(sourceFile))
        {
            makeRemotePath(scpServer, std::filesystem::path(destinationFile).parent_path().string(), (CSCP::FilePermissions)fileStatus.permissions());
            fileStatus = std::filesystem::status(std::filesystem::path(sourceFile));
            scpServer.pushFile(std::filesystem::path(destinationFile).filename().string(), std::filesystem::file_size(sourceFile), (CSCP::FilePermissions)fileStatus.permissions());
            for (;;)
            {
                localFile.read(scpServer.getIoBuffer().get(), scpServer.getIoBufferSize());
                if (localFile.gcount())
                {
                    scpServer.write(scpServer.getIoBuffer().get(), localFile.gcount());
                }
                if (!localFile)
                    break;
            }
            localFile.close();
        }
        scpServer.close();
    }