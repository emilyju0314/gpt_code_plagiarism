const bool Network::isMulticast(const std::string& host)
{

    // check multicast address that have to be assigned to any interface
    // Class Name Address Bits 	From ... To 	            Pourpose
    // Class D 	  1110          224.0.0.0 - 239.255.255.255 Multicast IP Addr
    struct in_addr addr;
    int domain = AF_INET, s = 0;
    s = inet_pton(domain, host.c_str(), &addr);
    if (s == 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Host value '%s' is invalid",
                        host.c_str());
    }
    else if (s < 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Error %d in inet_pton(): %s. "
                        "Host value '%s' is invalid",
                        s, strerror(s), host.c_str());
    }

    return IN_MULTICAST(ntohl(addr.s_addr));
}