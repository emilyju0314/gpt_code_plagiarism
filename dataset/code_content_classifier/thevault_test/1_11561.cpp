FileList putFiles(CSSHSession &sshSession, FileMapper &fileMapper, FileCompletionFn completionFn)
    {
        FileList successList;
        try
        {
            FileList localFileList;
            listLocalRecursive(fileMapper.getLocalDirectory(), localFileList);
            for (auto localFile : localFileList)
            {
                putFile(sshSession, localFile, fileMapper.toRemote(localFile));
                successList.push_back(fileMapper.toRemote(localFile));
                if (completionFn)
                {
                    completionFn(successList.back());
                }
            }
            // On exception report and return with files that where successfully uploaded.
        }
        catch (const CSCP::Exception &e)
        {
            std::cerr << e.getMessage() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        return (successList);
    }