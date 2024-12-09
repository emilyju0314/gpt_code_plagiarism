void putFile(CSFTP &sftpServer, const std::string &sourceFile, const std::string &destinationFile, FileCompletionFn completionFn)
    {
        CSFTP::File remoteFile;
        std::ifstream localFile;
        try
        {
            std::string remoteFilePath;
            CFile::Status fileStatus;
            int bytesWritten{0};
            bool transferFile{false};
            if (CFile::isDirectory(sourceFile))
            {
                remoteFilePath = destinationFile;
                fileStatus = CFile::fileStatus(sourceFile);
            }
            else if (CFile::isFile(sourceFile))
            {
                remoteFilePath = CPath(destinationFile).parentPath().toString();
                fileStatus = CFile::fileStatus(CPath(sourceFile).parentPath());
                transferFile = true;
            }
            else
            {
                return; // Not valid for transfer NEXT FILE!
            }
            if (!fileExists(sftpServer, remoteFilePath))
            {
                makeRemotePath(sftpServer, remoteFilePath, static_cast<CSFTP::FilePermissions>(fileStatus.permissions()));
                if (!transferFile && completionFn)
                {
                    completionFn(remoteFilePath);
                }
            }
            if (transferFile)
            {
                localFile.open(sourceFile, std::ios_base::in | std::ios_base::binary);
                if (!localFile)
                {
                    throw std::system_error(errno, std::system_category());
                }
                fileStatus = CFile::fileStatus(sourceFile);
                remoteFile = sftpServer.openFile(destinationFile, O_CREAT | O_WRONLY | O_TRUNC, (int)fileStatus.permissions());
                for (;;)
                {
                    localFile.read(sftpServer.getIoBuffer().get(), sftpServer.getIoBufferSize());
                    if (localFile.gcount())
                    {
                        bytesWritten = sftpServer.writeFile(remoteFile, sftpServer.getIoBuffer().get(), localFile.gcount());
                        if ((bytesWritten < 0) || (bytesWritten != localFile.gcount()))
                        {
                            throw CSFTP::Exception(sftpServer, __func__);
                        }
                    }
                    if (!localFile)
                        break;
                }
                sftpServer.closeFile(remoteFile);
                localFile.close();
                if (completionFn)
                {
                    completionFn(destinationFile);
                }
            }
        }
        catch (const CSFTP::Exception &e)
        {
            throw;
        }
        catch (const std::system_error &e)
        {
            throw;
        }
    }