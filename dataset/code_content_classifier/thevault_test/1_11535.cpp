static inline void listLocalRecursive(const std::string &localDirectory, FileList &fileList, FileFeedBackFn localFileFeedbackFn = nullptr)
    {
        for (auto directoryEntry : std::filesystem::recursive_directory_iterator{localDirectory})
        {
            fileList.push_back(directoryEntry.path().string());
            if (localFileFeedbackFn)
            {
                localFileFeedbackFn(directoryEntry.path().string());
            }
        }
    }