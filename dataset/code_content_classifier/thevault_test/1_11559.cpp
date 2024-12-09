static void downloadFile(CSCP &scpServer, const std::string &destinationFile)
    {
        std::ofstream localFile;
        CSCP::FilePermissions filePermissions;
        char *ioBuffer = scpServer.getIoBuffer().get();
        size_t ioBufferSize = scpServer.getIoBufferSize();
        int bytesRead{0};
        int fileSize{0};
        filePermissions = scpServer.requestFilePermissions();
        fileSize = scpServer.requestFileSize();
        scpServer.acceptRequest();
        if (!std::filesystem::exists(std::filesystem::path(destinationFile).parent_path()))
        {
            std::filesystem::create_directories(std::filesystem::path(destinationFile).parent_path());
        }
        localFile.open(destinationFile, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
        if (!localFile)
        {
            throw std::system_error(errno, std::system_category());
        }
        for (;;)
        {
            bytesRead = scpServer.read(ioBuffer, ioBufferSize);
            if (bytesRead)
            {
                localFile.write(ioBuffer, bytesRead);
                if (!localFile)
                {
                    throw std::system_error(errno, std::system_category());
                }
                fileSize -= bytesRead;
            }
            if ((fileSize <= 0) || (bytesRead == 0))
            {
                break;
            }
        }
        localFile.close();
        std::filesystem::permissions(destinationFile, static_cast<std::filesystem::perms>(filePermissions));
    }