void Utils::unlink(const std::string& path)
{
    if (access(path.c_str(), F_OK) == 0)
    {
        // check that the parent is a folder
        struct stat st;

        if (lstat(path.c_str(), &st) < 0)
        {
            throw Exception(__FILE__, __LINE__,
                                 "Error %d in lstat(): %s",
                                 errno, strerror(errno));
        }

        // check that there is a folder
        if (S_ISDIR(st.st_mode))
        {
            rmDir(path);
        }
        else if (::unlink(path.c_str()) < 0)
        {
            throw Exception(__FILE__, __LINE__,
                                 "Error %d in unlink(): %s. Argument: '%s'",
                                 errno, strerror(errno),
                                 path.c_str());
        }
    }
}