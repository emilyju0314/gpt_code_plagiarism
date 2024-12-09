static bool fileExists(CSFTP &sftpServer, const std::string &remotePath)
    {
        try
        {
            CSFTP::FileAttributes fileAttributes;
            sftpServer.getFileAttributes(remotePath, fileAttributes);
            return (true);
        }
        catch (CSFTP::Exception &e)
        {
            if (e.sftpGetCode() != SSH_FX_NO_SUCH_FILE)
            {
                throw;
            }
        }
        return (false);
    }