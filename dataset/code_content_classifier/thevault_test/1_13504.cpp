const short Resources::getFlags(const struct ifreq *ifr) const
{
    BOOST_ASSERT(ifr);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0)
    {
        throw Exception(__FILE__, __LINE__,
                             "Error %d in socket(): %s",
                             errno, strerror(errno));
    }

    // getting additional info
    short flags = 0;
    try
    {
        //get netmask
        struct ifreq copy = *ifr;
        if(ioctl(sock, SIOCGIFFLAGS, reinterpret_cast<char*>(&copy)) == -1)
        {
            throw Exception(__FILE__, __LINE__,
                                 "Error %d in ioctl(): %s",
                                 errno, strerror(errno));
        };
        flags = copy.ifr_flags;
    }
    catch(...)
    {
        close(sock);
        throw;
    }
    close(sock);

    return flags;
}