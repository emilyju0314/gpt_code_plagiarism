std::pair<std::uint16_t, std::uint16_t> CZIP::getFileModificationDateTime(const std::string &fileName)
    {
        struct stat64 fileStat
        {
        };
        std::uint16_t modificatioDate, modificationTime;
        int rc = lstat64(fileName.c_str(), &fileStat);
        if (rc == 0)
        {
            struct std::tm *fileTimeInfo = std::localtime(&fileStat.st_mtime);
            modificationTime = (fileTimeInfo->tm_sec & 0b11111) |
                               ((fileTimeInfo->tm_min & 0b111111) << 5) |
                               ((fileTimeInfo->tm_hour & 0b11111) << 11);
            modificatioDate = (fileTimeInfo->tm_mday & 0b11111) |
                              ((((fileTimeInfo->tm_mon + 1) & 0b1111)) << 5) |
                              (((fileTimeInfo->tm_year - 80) & 0b1111111) << 9);
        }
        else
        {
            throw Exception("stat() error getting file modified time. ERRNO = " + std::to_string(errno));
        }
        return (std::make_pair(modificatioDate, modificationTime));
    }