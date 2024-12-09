std::uint32_t CZIP::getFileAttributes(const std::string &fileName)
    {
        struct stat64 fileStat
        {
        };
        std::uint32_t attributes = 0;
        int rc = lstat64(fileName.c_str(), &fileStat);
        if (rc == 0)
        {
            attributes = fileStat.st_mode;
            attributes <<= 16;
        }
        else
        {
            throw Exception("stat() error getting file attributes. ERRNO = " + std::to_string(errno));
        }
        return (attributes);
    }