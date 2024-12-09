const BinaryData
Utils::readWholeDataFromFile(const std::string& fname)
{
    // retrive the size of the file
    BOOST_ASSERT(fileExist(fname));
    int fd = open(fname.c_str(),  O_RDONLY);
    if (fd < 0)
    {
        throw Exception(__FILE__, __LINE__, "Error %d in open(); %s",
                             errno, strerror(errno));
    }

    off_t size = 0;
    try
    {
        size = lseek(fd, 0L, SEEK_END);
        if (size < 0)
        {
            throw Exception(__FILE__, __LINE__, "Error %d in lseek(); %s",
                                 errno, strerror(errno));
        }
    }
    catch(...)
    {
        klk_close(fd);
        throw;
    }

    close(fd);
    return readDataFromFile(fname, size);
}