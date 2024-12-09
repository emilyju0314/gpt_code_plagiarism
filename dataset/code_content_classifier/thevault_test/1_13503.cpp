const std::string Resources::getMask(const struct ifreq *ifr) const
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
    std::string netmask;
    try
    {
        //get netmask
        struct ifreq ifrnm;
        strncpy(ifrnm.ifr_name, ifr->ifr_name, sizeof(ifrnm.ifr_name));
        if(ioctl(sock, SIOCGIFNETMASK, reinterpret_cast<char*>(&ifrnm)) == -1)
        {
            throw Exception(__FILE__, __LINE__,
                                 "Error %d in ioctl(): %s",
                                 errno, strerror(errno));
        };
        struct sockaddr *sa = &ifrnm.ifr_addr;
        struct sockaddr_in* sin = reinterpret_cast<struct sockaddr_in*>(sa);
        char addrstr[64];
        void *addrp = static_cast<void*>(&sin->sin_addr);
        inet_ntop(sa->sa_family, addrp, addrstr, sizeof(addrstr));
        netmask = addrstr;
    }
    catch(...)
    {
        close(sock);
        throw;
    }
    close(sock);

    return netmask;
}