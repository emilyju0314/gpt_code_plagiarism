const std::string Resources::getAddress(const struct ifreq *ifr) const
{
    BOOST_ASSERT(ifr);
    std::string addr;
    const struct sockaddr *sa = &ifr->ifr_addr;
    BOOST_ASSERT(sa);
    if (sa->sa_family == AF_INET)
    {
        const struct sockaddr_in*
            sin = reinterpret_cast<const struct sockaddr_in*>(sa);
        char addrstr[64];
        const void *addrp = static_cast<const void*>(&sin->sin_addr);
        inet_ntop(sa->sa_family, addrp, addrstr, sizeof(addrstr));
        addr = addrstr;
    }

    return addr;
}