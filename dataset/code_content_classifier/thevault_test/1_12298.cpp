bool FindData::PreFind(AZ::IO::PathView pathGlob)
    {
        if (!m_pRoot)
        {
            return false;
        }

        FileEntryTree* entryTreeHeader = m_pRoot;
        // If there is a root path in the glob path, attempt to locate it from the root
        if (AZ::IO::PathView rootPath = m_szWildcard.RootPath(); !rootPath.empty())
        {
            FileEntryTree* dirEntry = entryTreeHeader->FindDir(rootPath);
            if (dirEntry == nullptr)
            {
                return false;
            }

            entryTreeHeader = dirEntry->GetDirectory();
            pathGlob = pathGlob.RelativePath();
        }


        AZ::IO::PathView filenameSegment = pathGlob;
        // Recurse through the directories within the file tree for each remaining parent path segment
        // of pathGlob parameter
        auto parentPathIter = pathGlob.begin();
        for (auto filenamePathIter = parentPathIter == pathGlob.end() ? pathGlob.end() : AZStd::next(parentPathIter, 1);
            filenamePathIter != pathGlob.end(); ++parentPathIter, ++filenamePathIter)
        {
            FileEntryTree* dirEntry = entryTreeHeader->FindDir(*parentPathIter);
            if (dirEntry == nullptr)
            {
                return false;
            }
            entryTreeHeader = dirEntry->GetDirectory();
            filenameSegment = *filenamePathIter;
        }
       
        // At this point the all the intermediate directories have been found
        // so update the directory header to point at the last file entry tree
        m_pDirHeader = entryTreeHeader;
        m_szWildcard = filenameSegment;
        return true;
    }