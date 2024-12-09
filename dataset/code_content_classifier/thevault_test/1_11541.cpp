void listRemoteRecursive(CSFTP &sftpServer, const std::string &directoryPath, FileList &remoteFileList, FileFeedBackFn remoteFileFeedbackFn)
    {
        try
        {
            CSFTP::Directory directoryHandle;
            CSFTP::FileAttributes fileAttributes;
            std::string filePath;
            directoryHandle = sftpServer.openDirectory(directoryPath);
            while (sftpServer.readDirectory(directoryHandle, fileAttributes))
            {
                if ((static_cast<std::string>(fileAttributes->name) != ".") && (static_cast<std::string>(fileAttributes->name) != ".."))
                {
                    std::string filePath{directoryPath};
                    if (filePath.back() == kServerPathSep)
                        filePath.pop_back();
                    filePath += std::string(1, kServerPathSep) + fileAttributes->name;
                    if (sftpServer.isADirectory(fileAttributes))
                    {
                        listRemoteRecursive(sftpServer, filePath, remoteFileList, remoteFileFeedbackFn);
                    }
                    remoteFileList.push_back(filePath);
                    if (remoteFileFeedbackFn)
                    {
                        remoteFileFeedbackFn(remoteFileList.back());
                    }
                }
            }
            if (!sftpServer.endOfDirectory(directoryHandle))
            {
                sftpServer.closeDirectory(directoryHandle);
                throw CSFTP::Exception(sftpServer, __func__);
            }
            sftpServer.closeDirectory(directoryHandle);
        }
        catch (const CSFTP::Exception &e)
        {
            throw;
        }
    }