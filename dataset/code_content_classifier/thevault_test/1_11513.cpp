bool CZIP::fileExists(const std::string &fileName)
    {
        struct stat64 fileStat
        {
        };
        int rc = lstat64(fileName.c_str(), &fileStat);
        if (rc != 0)
        {
            throw Exception("stat() error getting file size. ERRNO = " + std::to_string(errno));
        }
        return (rc == 0);
    }