const BinaryData
Utils::readDataFromFile(const std::string& fname, size_t size)
{
    BinaryData data(size);
    BOOST_ASSERT(fileExist(fname));
    int fd = open(fname.c_str(),  O_RDONLY);
    if (fd < 0)
    {
        throw Exception(__FILE__, __LINE__, "Error %d in open(); %s",
                             errno, strerror(errno));
    }

    try
    {
        size_t read_count = read(fd, data.toVoid(), size);
        if (read_count < 0)
        {
            throw Exception(__FILE__, __LINE__, "Error %d in read(); %s",
                                 errno, strerror(errno));
        }
        if (read_count != size)
        {
            data.resize(read_count);
        }
    }
    catch(...)
    {
        close(fd);
        throw;
    }
    close(fd);

    return data;
}