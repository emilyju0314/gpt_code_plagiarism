static bool isDirectory(CSFTP &sftpServer, const std::string &remotePath)
    {
        CSFTP::FileAttributes fileAttributes;
        sftpServer.getFileAttributes(remotePath, fileAttributes);
        return (sftpServer.isADirectory(fileAttributes));
    }