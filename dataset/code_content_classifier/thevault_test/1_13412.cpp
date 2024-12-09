void Utils::saveData2File(const std::string& fname,
                          const BinaryData& data)
{
    int fd = open(fname.c_str(),  O_WRONLY|O_APPEND|O_CREAT);
    if (fd < 0)
    {
        throw Exception(__FILE__, __LINE__, "Error %d in open(): %s",
                             errno, strerror(errno));
    }

    try
    {
        size_t wcount = write(fd, data.toVoid(), data.size());
        if (wcount != data.size())
        {
            throw Exception(__FILE__, __LINE__, "Error %d in write(): %s",
                                 errno, strerror(errno));
        }
    }
    catch(...)
    {
        close(fd);
        throw;
    }
    close(fd);

    // change permsiisons to rw for owner
    if (chmod (fname.c_str(), S_IRUSR|S_IWUSR) < 0)
    {
        throw Exception(__FILE__, __LINE__, "Error %d in chmod(): %s",
                             errno, strerror(errno));
    }
}