std::uint64_t CZIP::getFileSize(const std::string &fileName)
    {
        struct stat64 fileStat
        {
        };
        std::uint64_t fileSize = 0;
        int rc = lstat64(fileName.c_str(), &fileStat);
        if (rc == 0)
        {
            if (S_ISDIR(fileStat.st_mode))
            {
                fileSize = 0;
            }
            else
            {
                fileSize = fileStat.st_size;
            }
        }
        else
        {
            throw Exception("stat() error getting file size. ERRNO = " + std::to_string(errno));
        }
        return (fileSize);
    }