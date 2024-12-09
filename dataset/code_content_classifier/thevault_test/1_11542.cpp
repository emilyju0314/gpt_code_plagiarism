FileList putFiles(CSFTP &sftpServer, FileMapper &fileMapper, const FileList &localFileList, FileCompletionFn completionFn, bool safe, char postFix)
    {
        FileList successList;
        try
        {
            CSFTP::FileAttributes remoteDirectoryAttributes;
            // Create any directories using root path permissions
            sftpServer.getFileAttributes(fileMapper.getRemoteDirectory(), remoteDirectoryAttributes);
            // Process file/directory list
            for (auto localFile : localFileList)
            {
                if (CFile::exists(localFile))
                {
                    std::string remoteFilePath;
                    bool transferFile{false};
                    // Create remote full remote path and set file to be transfered flag
                    if (CFile::isDirectory(localFile))
                    {
                        remoteFilePath = fileMapper.toRemote(localFile);
                    }
                    else if (CFile::isFile(localFile))
                    {
                        remoteFilePath = fileMapper.toRemote(CPath(localFile).parentPath().toString());
                        transferFile = true;
                    }
                    else
                    {
                        continue; // Not valid for transfer NEXT FILE!
                    }
                    if (!fileExists(sftpServer, remoteFilePath))
                    {
                        makeRemotePath(sftpServer, remoteFilePath, remoteDirectoryAttributes->permissions);
                        successList.push_back(remoteFilePath);
                        if (!transferFile && completionFn)
                        {
                            completionFn(successList.back());
                        }
                    }
                    remoteFilePath = fileMapper.toRemote(localFile);
                    // Transfer file
                    if (transferFile)
                    {
                        std::string destinationFilePath{remoteFilePath + postFix};
                        if (!safe)
                        {
                            destinationFilePath.pop_back();
                        }
                        putFile(sftpServer, localFile, destinationFilePath);
                        if (safe)
                        {
                            if (fileExists(sftpServer, remoteFilePath))
                            {
                                sftpServer.removeLink(remoteFilePath);
                            }
                            sftpServer.renameFile(destinationFilePath, remoteFilePath);
                        }
                        successList.push_back(remoteFilePath);
                        if (completionFn)
                        {
                            completionFn(successList.back());
                        }
                    }
                }
            }
            // On exception report and return with files that where successfully uploaded.
        }
        catch (const CSFTP::Exception &e)
        {
            std::cerr << e.getMessage() << std::endl;
        }
        catch (const CFile::Exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        return (successList);
    }