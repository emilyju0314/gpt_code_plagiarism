FileEntry* FileEntryTree::Add(AZ::IO::PathView inputPathView)
    {
        if (inputPathView.empty())
        {
            AZ_Assert(false, "An empty file path cannot be added to the zip file entry tree");
            return nullptr;
        }

        // If a path separator was found, add a subdirectory
        auto inputPathIter = inputPathView.begin();
        AZ::IO::PathView firstPathSegment(*inputPathIter);
        auto inputPathNextIter = inputPathIter == inputPathView.end() ? inputPathView.end() : AZStd::next(inputPathIter, 1);
        AZ::IO::PathView remainingPath = inputPathNextIter != inputPathView.end() ?
            AZStd::string_view(inputPathNextIter->Native().begin(), inputPathView.Native().end())
            : AZStd::string_view{};
        if (!remainingPath.empty())
        {
            auto dirEntryIter = m_mapDirs.find(firstPathSegment);
            // we have a subdirectory here - create the file in it
            if (dirEntryIter == m_mapDirs.end())
            {
                dirEntryIter = m_mapDirs.emplace(firstPathSegment, AZStd::make_unique<FileEntryTree>()).first;
            }
            return dirEntryIter->second->Add(remainingPath);
        }
        // Add the filename
        auto fileEntryIter = m_mapFiles.find(firstPathSegment);
        if (fileEntryIter == m_mapFiles.end())
        {
            fileEntryIter = m_mapFiles.emplace(firstPathSegment, AZStd::make_unique<FileEntry>()).first;
        }
        return fileEntryIter->second.get();
    }