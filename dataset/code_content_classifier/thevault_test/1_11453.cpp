bool CSFTP::readDirectory(const Directory &directoryHandle, FileAttributes &fileAttributes)
    {
        sftp_attributes file{sftp_readdir(m_sftp, directoryHandle.get())};
        if (file)
        {
            fileAttributes.reset(file);
            return (true);
        }
        return (false);
    }