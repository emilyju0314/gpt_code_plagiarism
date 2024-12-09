void EnumerateFilesRecursive(AZ::IO::Path currentPath, ZipDir::FileEntryTree* currentTree, AZStd::vector<AZ::IO::Path>& fileList)
    {
        // Drill down directories first...
        for (auto dirIter = currentTree->GetDirBegin(); dirIter != currentTree->GetDirEnd(); ++dirIter)
        {
            if (ZipDir::FileEntryTree* subTree = currentTree->GetDirEntry(dirIter);
                subTree != nullptr)
            {
                EnumerateFilesRecursive(currentPath / currentTree->GetDirName(dirIter), subTree, fileList);
            }
        }

        // Then enumerate the files in current directory...
        for (auto fileIter = currentTree->GetFileBegin(); fileIter != currentTree->GetFileEnd(); ++fileIter)
        {
            fileList.emplace_back(currentPath / currentTree->GetFileName(fileIter));
        }
    }