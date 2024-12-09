static bool isRegularFile(CSFTP &sftpServer, const std::string &remotePath)
    {
        CSFTP::FileAttributes fileAttributes;
        sftpServer.getFileAttributes(remotePath, fileAttributes);
        return (sftpServer.isARegularFile(fileAttributes));
    }